#include "huffman.hpp"

int main() {

	Arvore *T = new Arvore;
	Hash *map = new Hash;

	string nome;

	printf("Informe o nome do arquivo:\n");
    cin >> nome;

	map->stockMap(nome);
	map->arvore(&T);
	
	tamArvore(&T);
	compressao(&T, nome);

	cout << "Foi gerado o arquivo comprimido chamado 'compressao.txt'" << endl;

	return 0;
}
