#ifndef FILE_READER_H_
#define FILE_READER_H_

#include <string>
#include <vector>
#include <fstream>
#include <cassert>
#include <sstream>

class FileReader {
 public:
  static std::vector<std::string> ReadLines(const std::string &file_path);
  static std::vector<std::string> ReadWords(const std::string &file_path);
};

std::vector<std::string> FileReader::ReadLines(const std::string &file_path) {
  std::ifstream fin(file_path);
  if (!fin.is_open()) {
    throw std::exception();
  }
  std::string str;
  std::vector<std::string> vect;
  while (getline(fin, str)) {
    vect.push_back(str);
  }
  return vect;
}

std::vector<std::string> FileReader::ReadWords(const std::string &file_path) {
  std::vector<std::string> lines = ReadLines(file_path);
  std::vector<std::string> vect;
  for (const std::string &str : lines) {
    std::stringstream string_stream(str);
    std::string word;
    while (string_stream >> word) {
      vect.push_back(word);
    }
  }
  return vect;
}

#endif // FILE_READER_H_
