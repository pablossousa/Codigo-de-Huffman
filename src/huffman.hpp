#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <algorithm>
#include <unordered_map>
#include "tree.hpp"
#include <fstream>

using namespace std;

class Hash {
    private:
        unordered_map <string, pair<int,float>> umap;
    public:
        Hash();
    void preencheMap(string nomeArquivo);
    void arvore(Tree **TREE);
};

bool cmp(pair<string, pair<int,float>>& a,pair<string, pair<int,float>>& b);
bool cmpTree(Tree*&a,Tree*& b);
void compressao(Tree **T, string nome);

#endif