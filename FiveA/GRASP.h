#ifndef GRASP_H
#define GRASP_H



#endif /* GRASP_H */

#include <vector>

using namespace std;


void GRASP(vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas, unsigned int custoquantpadroesusados, unsigned int custoquantpadroesdiferentesusados,  unsigned int maxiteracoesGRASP, unsigned int maxiteracoesILS, unsigned int maxiteracoessemmelhoraMRNAD, float alpha);