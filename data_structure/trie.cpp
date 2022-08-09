#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode *> children;
  bool EOW;
  TrieNode() { this->EOW = false; }
};

class Trie {
 private:
  TrieNode *root;

 public:
  Trie() { root = new TrieNode(); }

  void insert(const string word) {
    TrieNode *curr = root;
    for (auto ch : word) {
      if (curr->children.find(ch) == curr->children.end()) {
        curr->children[ch] = new TrieNode();
      }
      curr = curr->children[ch];
    }
    curr->EOW = true;
  }

  bool search(const string word) { return search_substring(word, root); }

  bool search_substring(string s, TrieNode *p) {
    int len = s.size();
    if (len == 0) return p->EOW;
    char ch = s[0];
    if (p->children.find(ch) == p->children.end()) {
      if (ch == '.') {
        for (auto v : p->children) {
          if (search_substring(s.substr(1, len - 1), v.second)) {
            return true;
          }
        }
      }
    } else {
      p = p->children[ch];
      return search_substring(s.substr(1, len - 1), p);
    }

    return false;
  }
};
