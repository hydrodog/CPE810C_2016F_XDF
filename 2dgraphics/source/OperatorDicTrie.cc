#include "OperatorDicTrie.hh"

/*
 @author: Seito Ryu  18/11/16
*/
//constructor of Node class
OperatorDicTrie::Node::Node(){
  for(int i = 0; i < 26; ++i){
    next[i] = nullptr;
    isOptor[i] = false;
  }
}
//deconstructor of Node class
OperatorDicTrie::Node::~Node(){
//delete isOptor;
  for(int i = 0; i < 26; ++i){
    if(next[i] != nullptr){
      delete next[i];
    }
  }    
}
//constructor of OperatorDicTrie class
OperatorDicTrie::~OperatorDicTrie(){
  if(root != nullptr)
    delete root;  
}
//add one operator into trie
void OperatorDicTrie::addOptor(const std::string& s){
  unsigned long length = s.length();
  Node* curNode = root;
  int offset = 0;
  char curChar;
  for(int i = 0; i < length; ++i){
    curChar = s[i];
    if(curChar < 'a' || curChar > 'z'){
      throw ExceptionDraw(curChar);
    }
    offset = curChar - 'a';
    if(i == (length - 1)){
      curNode->isOptor[offset] = true;
    }else{
      if(!curNode->next[offset]){
        curNode->next[offset] = new Node;
      }
      curNode = curNode->next[offset];
    }
  }
}
//check whether one string is an operator or not
bool OperatorDicTrie::isOptor(const std::string& s) const {
  bool resultBl = false;
  unsigned long length = s.length();
  Node* curNode = root;
  int offset = 0;
  char curChar;
  for(int i = 0; i < length; ++i){
    curChar = s[i];
    if(curChar < 'a' || curChar > 'z'){
      return false;
    }
    offset = curChar - 'a';
    if(i == (length - 1) && curNode->isOptor[offset])
      return true;
    if(curNode->next[offset]){
      curNode = curNode->next[offset];
    }else{
      return false;
    }
  }
  return resultBl;
}

#endif