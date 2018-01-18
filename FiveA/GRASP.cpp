#include <vector>
#include "padroes.h"
#include "util.h"
#include "construcaoGRASP.h"
#include "MRNAD.h"
#include "ILS.h"
#include <climits>

using namespace std;



void GRASP(vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas, unsigned int custoquantpadroesusados, unsigned int custoquantpadroesdiferentesusados,  unsigned int maxiteracoesGRASP, unsigned int maxiteracoesILS, unsigned int maxiteracoessemmelhoraMRNAD, float alpha){
    vector <unsigned int> melhorsolucao; 
    vector <unsigned int> solucaotemp;
    vector <unsigned int> vetorzerado (quantpadroes, 0); // serve para zerar outros vetores
    unsigned int valormelhorsolucao = UINT_MAX;
    unsigned int valorsolucaotemp;  
    
    
    for(unsigned int cont = 1; cont <= maxiteracoesGRASP; cont++) {
        // retorna a solucao construida utilizando RCL.
        solucaotemp = vetorzerado;
        
        
        // Metodo de construcao da GRASP.
        GRASPconstrucao(solucaotemp, padroes, quantpadroes, demandas, alpha);
       
        // refina a solucao tirando padroes desnecessarios para atender a demanda.
        //refinarsolucao(solucaotemp, padroes, quantpadroes, demandas);

        
        // Busca local.        
        ILS(solucaotemp, padroes, quantpadroes, demandas, custoquantpadroesusados, custoquantpadroesdiferentesusados, maxiteracoesILS, maxiteracoessemmelhoraMRNAD);
        // Metodo Randomico nao ascendente/descedente.
        //metodorandomiconaoascdesc(solucaotemp, padroes, quantpadroes, demandas, custoquantpadroesusados, custoquantpadroesdiferentesusados, maxiteracoessemmelhoraMRNAD);

        
        
        valorsolucaotemp = calcularvalorsolucao(solucaotemp, custoquantpadroesusados, custoquantpadroesdiferentesusados);  
        if (valorsolucaotemp < valormelhorsolucao) {
            melhorsolucao = solucaotemp;
            valormelhorsolucao = valorsolucaotemp;
        }   
        
    }
    
    solucao = melhorsolucao; // copia os dados da melhor solucao para o vetor solucao.
}