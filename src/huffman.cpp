#include "huffman.hpp"

Hash::Hash() {

}

void Hash::preencheMap(string nome) {
    fstream myFile;
    string caminho, palavras, linha, arquivos;
    caminho = "arquivos/";
    myFile.open(caminho.append(nome));
    if (!myFile)
        printf("Arquivo não existe\n");
    while (myFile >> palavras) {
        while(palavras.back() == ',' || palavras.back() == '.' || palavras.back() == '!' || palavras.back() == '?' || palavras.back() == ':' || palavras.back() =='-' || palavras.back() =='/')
            palavras.pop_back();
        transform(palavras.begin(), palavras.end(), palavras.begin(), [](unsigned char c){ return tolower(c); });
        if (palavras.size() > 0){
            if (palavras.compare("a") && palavras.compare("e") && palavras.compare("o") && palavras.compare("nos") && palavras.compare("à") && palavras.compare("e") && palavras.compare("ser") && palavras.compare("é") && palavras.compare("uma") && palavras.compare("em") && palavras.compare("como") && palavras.compare("por") && palavras.compare("da") && palavras.compare("das") && palavras.compare("dos") && palavras.compare("um") && palavras.compare("com") && palavras.compare("o") && palavras.compare("de") && palavras.compare("do") && palavras.compare("no") && palavras.compare("na") && palavras.compare("que") && palavras.compare("se") && palavras.compare("ao") && palavras.compare("as") && palavras.compare("não")) {
                if(this->umap.find(palavras) == this->umap.end())
                    this->umap[palavras].first = 1;
                else
                    this->umap[palavras].first += 1;
            }
        }
    } 
    myFile.close();
}

bool cmp(pair<string, pair<int,float>>&a, pair<string, pair<int,float>>& b) {
    return a.second.second < b.second.second;
}

bool cmpTree(Tree*&a, Tree*& b) {
    return a->item.value.second.second < b->item.value.second.second;
}

void Hash::arvore(Tree **TREE) {
    vector<pair<string, pair<int,float>>> vec;
    for (auto& it : this->umap)
        vec.push_back(it);
    sort(vec.begin(), vec.end(), cmp);

    vector<Tree*> rec;
    for (size_t i = 0; i < vec.size(); i++) {
        Tree *T;
        initialize(&T);
        insert(&T,vec[i]);
        rec.push_back(T);
    }
    while (rec.size() > 2) {
        Tree *T = new Tree;
        (*T).item.value.second.second = rec[0]->item.value.second.second+rec[1]->item.value.second.second;
        (*T).FD = rec[1];
        (*T).FE = rec[0];
        rec.erase(rec.begin());
        rec.erase(rec.begin());
        rec.push_back(T);
        sort(rec.begin(), rec.end(), cmpTree);
    }
    (*TREE)->item.value.second.second = rec[0]->item.value.second.second+rec[1]->item.value.second.second;
    (*TREE)->FE = rec[0];
    rec.erase(rec.begin());
    if (!(rec.empty()))
        (*TREE)->FD = rec[1];
}

void compressao(Tree **T, string nome) {
    string caminho, palavras;
    fstream myFile;
    ofstream arquivoFinal ("arquivos/compressao.txt");
    unordered_map <string, vector<bool>> hash;
    queue<Tree*> tempFila;
	Tree *temp;
	int tempCont = 1, cont = 0;
	tempFila.push((*T));
	while (!(tempFila.empty())) {
		cont=0;
		for (int i = 0; i < tempCont; i++) {
			temp =tempFila.front();
            if (temp->item.value.first!="")
                hash[temp->item.value.first] = temp->item.trad;
			tempFila.pop();
			if (temp->FE) {
				tempFila.push(temp->FE);
				cont++;
			}
			if (temp->FD) {
				tempFila.push(temp->FD);
				cont++;
			}
		}
		tempCont = cont;
    }
    caminho = "arquivos/";
    myFile.open(caminho.append(nome));
    while (myFile >> palavras) {
        while(palavras.back() == ',' || palavras.back() == '.' || palavras.back() == '!' || palavras.back() == '?' || palavras.back() == ':' || palavras.back() == '-' || palavras.back() == '/')
            palavras.pop_back();
        transform(palavras.begin(), palavras.end(), palavras.begin(),[](unsigned char c){ return tolower(c); });
        if (palavras.size() > 0) {
            if (palavras.compare("a") && palavras.compare("e") && palavras.compare("o") && palavras.compare("nos") && palavras.compare("à") && palavras.compare("e") && palavras.compare("ser") && palavras.compare("é") && palavras.compare("uma") && palavras.compare("em") && palavras.compare("como") && palavras.compare("por") && palavras.compare("da") && palavras.compare("das") && palavras.compare("dos") && palavras.compare("um") && palavras.compare("com") && palavras.compare("o") && palavras.compare("de") && palavras.compare("do") && palavras.compare("no") && palavras.compare("na") && palavras.compare("que") && palavras.compare("se") && palavras.compare("ao") && palavras.compare("as") && palavras.compare("não")) {
                for (size_t i = 0; i < hash[palavras].size(); i++)
                    arquivoFinal << hash[palavras][i];
                arquivoFinal << " ";
            }
        }
    }
}