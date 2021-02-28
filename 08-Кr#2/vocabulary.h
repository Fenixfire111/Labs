#ifndef VOCABULARY_H_
#define VOCABULARY_H_

#include <string>
#include <map>
#include <fstream>
#include <cassert>
#include "word_card.h"
#include "file_reader.h"
#include "bidirectional_list_on_array.h"

class Vocabulary {
 public:
  Vocabulary() : list_word_cards() {}

  ~Vocabulary() = default;

  void ReadFileToCards(const std::string &file_path);

  WordCard *ConvertStringToWordCard(const std::string &str);

  void MakeFrequencyVocab();

  void SortWords();

  std::map<std::string, size_t> CopyToMap();
 private:
  containers::BiDirectionalListOnArray<WordCard *> list_word_cards;
};

void Vocabulary::ReadFileToCards(const std::string &file_path) {
  std::vector<std::string> words = FileReader::ReadWords(file_path);
  for (const std::string &word : words) {
    WordCard *word_card = ConvertStringToWordCard(word);
    list_word_cards.PushBack(word_card);
  }
}

WordCard *Vocabulary::ConvertStringToWordCard(const std::string &str) {
  WordCard *word_card = new WordCard(str);
  return word_card;
}

void Vocabulary::MakeFrequencyVocab() {
  SortWords();
  for (int i = 0; i < list_word_cards.Size(); ++i) {
    if (i + 1 < list_word_cards.Size() && (*list_word_cards[i])->GetWord() ==
        (*list_word_cards[i + 1])->GetWord()) {
      (*list_word_cards[i])->IncCounter();
      list_word_cards.Erase(i + 1);
      --i;
    }
  }
}

void Vocabulary::SortWords() {
  for (int i = 0; i < list_word_cards.Size() - 1; ++i) {
    int minWordCardIndex = i;
    for (int j = i + 1; j < list_word_cards.Size(); ++j) {
      if (**list_word_cards[j] < **list_word_cards[minWordCardIndex]) {
        minWordCardIndex = j;
      }
    }
    std::swap(*list_word_cards[i], *list_word_cards[minWordCardIndex]);
  }
}

std::map<std::string, size_t> Vocabulary::CopyToMap() {
  std::map<std::string, size_t> result;
  for (int i = 0; i < list_word_cards.Size(); ++i) {
    std::string key = (*list_word_cards[i])->GetWord();
    if (result.find(key) == result.cend()) {
      result.insert(std::pair<std::string, size_t>(key, 0));
    }
    result[key] += (*list_word_cards[i])->GetCounter();
  }
  return result;
}

#endif // VOCABULARY_H_
