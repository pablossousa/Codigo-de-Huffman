#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <unordered_map>
#include "tree.hpp"
#include <fstream>
#include <algorithm>

using namespace std;

class Hash {
    private:
        unordered_map <string, pair<int,float>> umap;
    public:
        Hash();
    void stockMap(string nomeArquivo);
    void arvore(Arvore **TREE);
};

void compressao(Arvore **T, string nome);

bool cmp(pair<string, pair<int,float>>& a,pair<string, pair<int,float>>& b);

bool cmpTree(Arvore*&a, Arvore*& b);

#endif