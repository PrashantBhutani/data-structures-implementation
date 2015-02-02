#include "TrieNode.h"

TrieNode::TrieNode() {
  prefixMatch = -1;
  exactMatch = -1;
  small = NULL;
  cap = NULL;
}

TrieNode::~TrieNode() {
  prefixMatch = -1;
  exactMatch = -1;
}

int TrieNode::getPrefixMatch() const{
  return this->prefixMatch;
}

int TrieNode::getExactMatch() const{
  return this->exactMatch;
}

void TrieNode::setPrefixMatch(int val) {
  this->prefixMatch = val;
}

void TrieNode::setExactMatch(int val) {
  this->exactMatch = val;
}

TrieNode* TrieNode::getSmall() {
  if (this->small == NULL)
    this->setSmall(new TrieNode[26]);
  return this->small;
}

TrieNode* TrieNode::getCap() {
  if (this->cap == NULL)
    this->setCap(new TrieNode[26]);
  return this->cap;
}

void TrieNode::setCap(TrieNode* node) {
  this->cap = node;
}

void TrieNode::setSmall(TrieNode* node) {
  this->small = node;
}

TrieNode* TrieNode::lookUpSmall() const{
  return this->small;
}

TrieNode* TrieNode::lookUpCap() const{
  return this->cap;
}
