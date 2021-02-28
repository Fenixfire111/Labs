
#ifndef WORD_CARD_H_
#define WORD_CARD_H_
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using std::string;

class WordCard {
 public:
  WordCard() : word_(), counter_(1) {}
  explicit WordCard(std::string word) : word_(std::move(word)), counter_(1) {}

  WordCard(const WordCard &other) = default;
  WordCard &operator=(const WordCard &other);

  WordCard(WordCard &&other) noexcept;
  WordCard &operator=(WordCard &&other) noexcept;

  ~WordCard() = default;

  std::string GetWord() const {
    return word_;
  }
  size_t GetCounter() const {
    return counter_;
  }

  void IncCounter() {
    ++counter_;
  }

  bool operator==(const WordCard &other) const;
  bool operator!=(const WordCard &other) const;

  friend bool operator<(const WordCard &first, const WordCard &second);

 private:
  std::string word_;
  size_t counter_;
};
WordCard &WordCard::operator=(const WordCard &other) {
  if (this == &other) {
    return *this;
  }
  word_ = other.word_;
  counter_ = other.counter_;
  return *this;
}

WordCard::WordCard(WordCard &&other) noexcept {
  word_ = std::move(other.word_);
  counter_ = other.counter_;
}

WordCard &WordCard::operator=(WordCard &&other) noexcept {
  if (this == &other) {
    return *this;
  }
  word_ = std::move(other.word_);
  counter_ = other.counter_;
  return *this;
}

bool WordCard::operator==(const WordCard &other) const {
  return (word_ == other.word_ && counter_ == other.counter_);
}

bool WordCard::operator!=(const WordCard &other) const {
  return !(*this == other);
}

bool operator<(const WordCard &first, const WordCard &second) {
  if (first.word_ != second.word_) {
    return (first.word_ < second.word_);
  } else {
    return (first.counter_ < second.counter_);
  }
}

#endif // WORD_CARD_H_
