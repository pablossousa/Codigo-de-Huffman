#include "huffman.hpp"

void Hash::stockMap(string nome) {
    fstream myFile;
    string destino;
    destino = "arquivos/";
    myFile.open(destino.append(nome));
    if (!myFile)
        printf("Arquivo não existe\n");
    string palavras, linha, arquivos;
    while (myFile >> palavras) {
        while(palavras.back() == ',' || palavras.back() == '.' || palavras.back() == '!' || palavras.back() == '?' || palavras.back() == ':' || palavras.back() =='-' || palavras.back() =='/')
            palavras.pop_back();
        if (palavras.size() > 0){
            if (palavras.compare("a") && palavras.compare("e") && palavras.compare("o") && palavras.compare("nos") && palavras.compare("à") && palavras.compare("e") && palavras.compare("ser") && palavras.compare("é") && palavras.compare("uma") && palavras.compare("em") && palavras.compare("como") && palavras.compare("por") && palavras.compare("da") && palavras.compare("das") && palavras.compare("dos") && palavras.compare("um") && palavras.compare("com") && palavras.compare("o") && palavras.compare("de") && palavras.compare("do") && palavras.compare("no") && palavras.compare("na") && palavras.compare("que") && palavras.compare("se") && palavras.compare("ao") && palavras.compare("as") && palavras.compare("não")) {
                if(this->umap.find(palavras) == this->umap.end())
                    this->umap[palavras].first = 1;
                else
                    this->umap[palavras].first += 1;
            }
        }
    } 
}

bool cmp(pair<string, pair<int,float>>&a, pair<string, pair<int,float>>& b) {
    return a.second.second < b.second.second;
}

bool cmpTree(Arvore*&a, Arvore*& b) {
    return a->item.value.second.second < b->item.value.second.second;
}

void Hash::arvore(Arvore **TREE) {
    vector<pair<string, pair<int,float>>> vec;
    for (auto& it : this->umap)
        vec.push_back(it);
    sort(vec.begin(), vec.end(), cmp);

    vector<Arvore*> rec;
    for (size_t i = 0; i < vec.size(); i++) {
        Arvore *T;
        initialize(&T);
        insert(&T,vec[i]);
        rec.push_back(T);
    }
    while (rec.size() > 2) {
        Arvore *T = new Arvore;
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

Hash::Hash() {

}

void compressao(Arvore **T, string nome) {
    fstream myFile;
    ofstream arquivoFinal ("arquivos/compressao.txt");
    unordered_map <string, vector<bool>> hash;
    queue<Arvore*> tempFila;
	Arvore *temp;
	int tempCont = 1, cont = 0;
	tempFila.push((*T));
	while (!(tempFila.empty())) {
		cont=0;
		for (int i = 0; i < tempCont; i++) {
			temp = tempFila.front();
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
    string destino, palavras;
    destino = "arquivos/";
    myFile.open(destino.append(nome));
    while (myFile >> palavras) {
        while(palavras.back() == ',' || palavras.back() == '.' || palavras.back() == '!' || palavras.back() == '?' || palavras.back() == ':' || palavras.back() == '-' || palavras.back() == '/')
            palavras.pop_back();
        if (palavras.size() > 0) {
            if (palavras.compare("a") && palavras.compare("e") && palavras.compare("o") && palavras.compare("nos") && palavras.compare("à") && palavras.compare("e") && palavras.compare("ser") && palavras.compare("é") && palavras.compare("uma") && palavras.compare("em") && palavras.compare("como") && palavras.compare("por") && palavras.compare("da") && palavras.compare("das") && palavras.compare("dos") && palavras.compare("um") && palavras.compare("com") && palavras.compare("o") && palavras.compare("de") && palavras.compare("do") && palavras.compare("no") && palavras.compare("na") && palavras.compare("que") && palavras.compare("se") && palavras.compare("ao") && palavras.compare("as") && palavras.compare("não")) {
                for (size_t i = 0; i < hash[palavras].size(); i++)
                    arquivoFinal << hash[palavras][i];
                arquivoFinal << " ";
            }
        }
    }
}