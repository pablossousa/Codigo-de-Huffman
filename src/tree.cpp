#include "tree.hpp"

void initialize(Arvore **T) {
	(*T) = nullptr;
}

void tamArvore(Arvore **T) {
	queue<Arvore*> tempFila;
	vector<bool> trad;
	Arvore *temp;

	int cont1 = 1, cont2;

	tempFila.push((*T));
	while (!(tempFila.empty())) {
		
		cont2 = 0;

		for (int i = 0; i < cont1; i++) {
			temp = tempFila.front();
			trad = temp->item.trad;
			tempFila.pop();
			if (temp->FE) {
				tempFila.push(temp->FE);
				cont2++;
				trad.push_back(0);
				temp->FE->item.trad = trad;
			}
			trad = temp->item.trad;
			if (temp->FD) {
				tempFila.push(temp->FD);
				cont2++;
				trad.push_back(1);
				temp->FD->item.trad = trad;
			}
		}
		cont1 = cont2;
	}
}

void insert(Arvore **T, pair<string, pair<int,float>> valor) {
	if ((*T) == nullptr) {
		(*T) = new Arvore;
		(*T)->item.value = valor;
		(*T)->item.nivel = 0;
		(*T)->FE = nullptr;
		(*T)->FD = nullptr;
	}
}