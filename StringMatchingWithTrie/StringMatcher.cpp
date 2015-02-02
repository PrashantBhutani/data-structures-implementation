#include "StringMatcher.h"

StringMatcher::StringMatcher() {
}

StringMatcher::~StringMatcher(){
  trie.~TrieNode();
}

void StringMatcher::add_exact_match(const char* exact_str, int id) {
  TrieNode* temp = &this->trie;
  int c = 0;
  for (int i = 0; exact_str[i] != '\0'; ++i) {
    c = exact_str[i] - 'A';
    if (c < 26) {
      temp = temp->getCap();
      temp += c;
    } else {
      temp = temp->getSmall();
      temp += c;
    }
  }
  temp->setExactMatch(id);
}

void StringMatcher::add_prefix_match(const char* prefix_str, int id) {
  TrieNode* temp = &this->trie;
  int c = 0;
  for (int i = 0; prefix_str[i] != '\0'; ++i) {
    c = prefix_str[i] - 'A';
    if (c < 26) {
      temp = temp->getCap();
      temp += c;
    } else {
      temp = temp->getSmall();
      temp += c;
    }
  }
  temp->setPrefixMatch(id);
}

bool StringMatcher::delete_exact_match(const char* exact_str) {
  TrieNode* temp = &this->trie;
  int c = 0;
  for (int i = 0; exact_str[i] != '\0'; ++i) {
    c = exact_str[i] - 'A';
    if (c < 26) {
      temp = temp->getCap();
      temp += c;
    } else {
      temp = temp->getSmall();
      temp += c;
    }
  }
  if (temp->getExactMatch() > 0) {
    temp->setExactMatch(-1);
    return true;
  } else {
    return false;
  }
}

bool StringMatcher::delete_prefix_match(const char* prefix_str) {
  TrieNode* temp = &this->trie;
  int c = 0;
  for (int i = 0; prefix_str[i] != '\0'; ++i) {
    c = prefix_str[i] - 'A';
    if (c < 26) {
      temp = temp->getCap();
      temp += c;
    } else {
      temp = temp->getSmall();
      temp += c;
    }
  }
  if (temp->getPrefixMatch() > 0) {
    temp->setPrefixMatch(-1);
    return true;
  } else {
    return false;
  }

}

int StringMatcher::lookup(const char* input) const {
  const TrieNode* temp = &this->trie;
  int val = -1, c = 0;
  for (int i = 0; input[i] != '\0'; ++i) {
    c = input[i] - 'A';
    if (c < 26) {
      temp = temp->lookUpCap();
    } else {
      temp = temp->lookUpSmall();
    }

    if (temp == NULL) {
      return val;
    } else {
      temp += c;
      if (temp->getExactMatch() != -1 && input[i+1] == '\0') {
	return temp->getExactMatch();
      } else if (temp->getPrefixMatch() > 0) {
	val = temp->getPrefixMatch();
      }
    }
  }
  return val;
}
