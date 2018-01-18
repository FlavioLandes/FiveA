#ifndef BUSCALOCAL_H
#define BUSCALOCAL_H



#endif /* BUSCALOCAL_H */

#include <vector>

using namespace std;

// pega um vizinho da solucao corrente.
void pegarvizinho(vector <unsigned int>& vizinho, vector <unsigned int> solucao);


// Metodo Randomico nao ascendente/descedente.
void metodorandomiconaoascdesc(vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas, unsigned int custoquantpadroesusados, unsigned int custoquantpadroesdiferentesusados, unsigned int maxiteracoessemmelhora);
