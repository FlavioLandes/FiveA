#ifndef PADROES_H
#define PADROES_H



#endif /* PADROES_H */

#include <vector>

using namespace std;


// Verifica se os padroes contem todos os itens da demanda;
bool padroessaovalidos(unsigned int** padroes, unsigned int quantpadroes, vector <unsigned int> itens);

// padroes[indicepadrao][itens].
unsigned int** gerarpadroes(unsigned int& quantpadroes, vector <unsigned int> itens, unsigned int comprimentobase);