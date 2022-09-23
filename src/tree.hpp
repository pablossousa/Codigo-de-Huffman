#ifndef TreeStruc
#define TreeStruc

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Record {
	pair <string, pair<int,float>> value;
	vector <bool> trad;
    int nivel;
};

struct Tree {
	Record item;
	Tree *FE, *FD;
};

void initialize(Tree **T);
void insert(Tree **T, pair<string, pair<int,float>> valor);
void tamArvore(Tree **T);

#endif