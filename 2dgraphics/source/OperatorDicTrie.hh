#ifndef OPERATOR_DIC_TRIE_HH__
#define OPERATOR_DIC_TRIE_HH__

#include "ExceptionOptDic.h"
#include <iostream>

/*
 @author: Seito Ryu  18/11/16
 @purpose: Read all operators from operatorList file and set into a trie.
           Check whether operators in raw data is in the file.
           If not in the file, discard that operator and its operands.
 @modifer: Seito Ryu 1/12/16  "fix some bugs"
*/
class OperatorDicTrie{
private:
  class Node{
  public:
    Node* next[26];
    bool isOptor[26];
    Node();
    ~Node();
  };
  Node* root;
public:
  OperatorDicTrie():root(new Node) {};
  ~OperatorDicTrie();
  //add one operator into trie
  void addOptor(const std::string& s);
  //check whether one string is an operator or not
  bool isOptor(const std::string& s) const;
};

#endif
