#include "huffman.hpp"

int main() {

	string nome;

	Tree *T = new Tree;
	Hash *map = new Hash;

	printf("Informe o nome do arquivo:\n");
    cin >> nome;

	map->preencheMap(nome);
	map->arvore(&T);
	
	tamArvore(&T);
	compressao(&T,nome);

	cout << "Foi gerado o arquivo comprimido chamado 'compressao.txt'" << endl;

	return 0;
}