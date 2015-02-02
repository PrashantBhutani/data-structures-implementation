#ifndef TRIENODE_H
#define TRIENODE_H

#include<stdlib.h>

class TrieNode {
 private:
    int prefixMatch;
    int exactMatch;
    TrieNode *small;
    TrieNode *cap; 
  
 public:
    TrieNode();
    ~TrieNode();

    int getPrefixMatch() const;
    int getExactMatch() const;
    void setPrefixMatch(int);
    void setExactMatch(int);
    
    TrieNode* getSmall();
    TrieNode* getCap();
    void setSmall(TrieNode*);
    void setCap(TrieNode*);

    TrieNode* lookUpSmall() const;
    TrieNode* lookUpCap() const;
};

#endif //TRIENODE_H
