/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia 2026-2027
 *
 * @file html_analyzer.cc
 * @author Alfonso Reyes Núñez Fernández <alu0101784809@ull.edu.es>
 * @date 30/09/2026
 * @brief Implementación de la clase HtmlAnalyzer corregida sin errores de enlace/compilador.
 */

#include "html_analyzer.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

#include "atribute_info.h"
#include "comment_info.h"
#include "tag_atributes_info.h"
#include "tag_info.h"

HtmlAnalyzer::HtmlAnalyzer(const std::string& input_filename)
    : input_filename_(input_filename) {}

int HtmlAnalyzer::CountLinesUpTo(const std::string& content, size_t position) const {
  int line_count = 1;
  for (size_t i = 0; i < position && i < content.size(); ++i) {
    if (content[i] == '\n') {
      ++line_count;
    }
  }
  return line_count;
}

void HtmlAnalyzer::ProcessStructure(const std::string& content, HtmlDocument& document) {
  try {
    const std::string kDoctypePattern = "<!DOCTYPE\\s+html>";
    const std::string kHtmlPattern = "<html[\\s>]";
    const std::string kHeadPattern = "<head[\\s>]";
    const std::string kBodyPattern = "<body[\\s>]";

    const std::regex doctype_regex(kDoctypePattern, std::regex_constants::icase);
    const std::regex html_regex(kHtmlPattern, std::regex_constants::icase);
    const std::regex head_regex(kHeadPattern, std::regex_constants::icase);
    const std::regex body_regex(kBodyPattern, std::regex_constants::icase);

    document.set_has_doctype(std::regex_search(content, doctype_regex));
    document.set_has_html(std::regex_search(content, html_regex));
    document.set_has_head(std::regex_search(content, head_regex));
    document.set_has_body(std::regex_search(content, body_regex));
  } catch (const std::regex_error& e) {
    std::cerr << "Regex error en ProcessStructure: " << e.what() << std::endl;
  }
}

void HtmlAnalyzer::ProcessComments(const std::string& content, HtmlDocument& document) {
  try {
    const std::string kCommentPattern = "<!--([\\s\\S]*?)-->";
    const std::string kDoctypePattern = "<!DOCTYPE\\s+html>";
    const std::string kWhitespacePattern = "\\s*";
    const std::string kTrimPattern = "^\\s+|\\s+$";

    const std::regex comment_regex(kCommentPattern);
    const std::regex doctype_regex(kDoctypePattern, std::regex_constants::icase);
    const std::regex whitespace_regex(kWhitespacePattern);
    const std::regex trim_regex(kTrimPattern);

    auto comments_begin = std::sregex_iterator(content.begin(), content.end(), comment_regex);
    auto comments_end = std::sregex_iterator();

    std::smatch doctype_match;
    bool has_doctype = std::regex_search(content, doctype_match, doctype_regex);
    size_t doctype_end_pos = has_doctype ? 
                             (static_cast<size_t>(doctype_match.position()) + 
                              static_cast<size_t>(doctype_match.length())) : 0;

    bool is_first_comment = true;

    for (std::sregex_iterator i = comments_begin; i != comments_end; ++i) {
      const std::smatch& match = *i;
      size_t start_pos = static_cast<size_t>(match.position());
      size_t end_pos = start_pos + static_cast<size_t>(match.length());

      int start_line = CountLinesUpTo(content, start_pos);
      int end_line = CountLinesUpTo(content, end_pos);
      
      std::string comment_text = match[1].str();

      bool is_desc = false;
      if (is_first_comment && has_doctype && start_pos >= doctype_end_pos) {
        std::string gap = content.substr(doctype_end_pos, start_pos - doctype_end_pos);
        if (std::regex_match(gap, whitespace_regex)) {
          is_desc = true;
          std::string cleaned_text = std::regex_replace(comment_text, trim_regex, "");
          document.set_description(cleaned_text);
        }
      }

      document.AddComment(CommentInfo(start_line, end_line, comment_text, is_desc));
      is_first_comment = false;
    }
  } catch (const std::regex_error& e) {
    std::cerr << "Regex error en ProcessComments: " << e.what() << std::endl;
  }
}

void HtmlAnalyzer::ProcessTagsAndAttributes(const std::vector<std::string>& lines,
                                            HtmlDocument& document) {
  try {
    const std::string kTargetTagsPattern = "^/?(html|head|title|body|h1|p|a|img)$";
    const std::string kTagPattern = "<(/?[a-zA-Z0-9]+)([^>]*)>";
    const std::string kAttrPattern = "([a-zA-Z0-9_-]+)\\s*=\\s*(\"([^\"]*)\"|'([^']*)'|([^\\s>]+))";

    const std::regex target_tags_regex(kTargetTagsPattern, std::regex_constants::icase);
    const std::regex tag_regex(kTagPattern);
    const std::regex attr_regex(kAttrPattern);

    for (size_t i = 0; i < lines.size(); ++i) {
      int line_num = static_cast<int>(i + 1);
      
      const std::string line_content = lines[i];

      auto tags_begin = std::sregex_iterator(line_content.begin(), line_content.end(), tag_regex);
      auto tags_end = std::sregex_iterator();

      for (std::sregex_iterator it = tags_begin; it != tags_end; ++it) {
        const std::smatch& match = *it;
        
        const std::string full_tag_name = match[1].str();
        const std::string attributes_str = match[2].str();

        bool is_closing = (!full_tag_name.empty() && full_tag_name[0] == '/');
        const std::string clean_tag_name = is_closing ? full_tag_name.substr(1) : full_tag_name;

        if (std::regex_match(clean_tag_name, target_tags_regex)) {
          document.AddTag(TagInfo(line_num, clean_tag_name, is_closing));

          if (!is_closing && !attributes_str.empty()) {
            std::vector<AttributeInfo> attr_list;

            auto attr_begin = std::sregex_iterator(attributes_str.begin(),
                                                  attributes_str.end(),
                                                  attr_regex);
            auto attr_end = std::sregex_iterator();

            for (std::sregex_iterator attr_it = attr_begin; attr_it != attr_end; ++attr_it) {
              const std::smatch& attr_match = *attr_it;
              
              std::string attr_name = attr_match[1].str();
              std::string attr_value = "";

              if (attr_match[3].matched) {
                attr_value = attr_match[3].str(); 
              } else if (attr_match[4].matched) {
                attr_value = attr_match[4].str(); 
              } else if (attr_match[5].matched) {
                attr_value = attr_match[5].str(); 
              }

              attr_list.emplace_back(attr_name, attr_value);
            }

            if (!attr_list.empty()) {
              document.AddTagAttributes(TagAttributesInfo(line_num, clean_tag_name, attr_list));
            }
          }
        }
      }
    }
  } catch (const std::regex_error& e) {
    std::cerr << "Regex error en ProcessTagsAndAttributes: " << e.what() << std::endl;
  }
}

HtmlDocument HtmlAnalyzer::Analyze() {
  std::ifstream file(input_filename_);
  if (!file.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo de entrada " << input_filename_ << std::endl;
    std::exit(EXIT_FAILURE);
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  const std::string full_content = buffer.str();

  file.clear();
  file.seekg(0, std::ios::beg);

  std::vector<std::string> lines;
  std::string line_buffer;
  while (std::getline(file, line_buffer)) {
    lines.push_back(line_buffer);
  }
  file.close();

  HtmlDocument document(input_filename_);
  ProcessStructure(full_content, document);
  ProcessComments(full_content, document);
  ProcessTagsAndAttributes(lines, document);

  return document;
}