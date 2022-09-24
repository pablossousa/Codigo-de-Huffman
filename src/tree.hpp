#ifndef TreeStruc
#define TreeStruc

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Gravar {
	pair <string, pair<int,float>> value;
	vector <bool> trad;
    int nivel;
};

struct Arvore {
	Gravar item;
	Arvore *FE, *FD;
};

void initialize(Arvore **T);
void insert(Arvore **T, pair<string, pair<int,float>> valor);
void tamArvore(Arvore **T);

#endif