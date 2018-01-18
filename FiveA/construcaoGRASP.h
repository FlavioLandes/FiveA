#ifndef CONSTRUCAOGRASP_H
#define CONSTRUCAOGRASP_H



#endif /* CONSTRUCAO_H */

#include <vector>

using namespace std;

// Calcula o valor de um padrao. 
unsigned int calcularvalorpadrao(unsigned int** padroes, unsigned int numpadrao, vector <long> demandas);

// Classifica os padroes colocando o valor de cada um na segunda coluna da matrizpadroesclassificados.
void classificarpadroes(unsigned int** padroes, unsigned int quantpadroes, unsigned int** matrizpadroesclassificados, vector <long> demandas);

// Ordena a matrizpadroesclassificados de forma decrescente.
void ordenarmatrizpadroesclassificados(unsigned int** matrizpadroesclassificados, unsigned int quantpadroes);


// Metodo de construcao da GRASP.
void GRASPconstrucao(vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas, float alpha);

