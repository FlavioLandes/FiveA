#include <cstdlib>
#include <vector>
#include "util.h"

using namespace std;


// funcao para efetuar a pertubacao na solucao. Faz parte da ILS.
void pertubacao(vector <unsigned int>& solucao, unsigned int quantpadroes) {
    //vector <unsigned int> auxsolucao;
    unsigned int quantpertubacao;
    //bool demandafoiatendida;
    unsigned int padraoserapertubado;
    unsigned int maxpertubacao;
    
    
    maxpertubacao = quantpadroes / 4;
    quantpertubacao = (rand() % maxpertubacao) + 1;
    
    for(unsigned int contpertubacao = 1; contpertubacao <= quantpertubacao; contpertubacao++) {
            padraoserapertubado = rand() % quantpadroes;      
            solucao[padraoserapertubado]++;         
    }    
    
   /* do {
        auxsolucao = solucao;
        
        for(unsigned int contpertubacao = 1; contpertubacao <= quantpertubacao; contpertubacao++) {
            padraoserapertubado = rand() % quantpadroes;
        
        
            if (auxsolucao[padraoserapertubado] > 0) {
                auxsolucao[padraoserapertubado]--;
            }
            else {
                auxsolucao[padraoserapertubado]++;
            }
        }    
            
            demandafoiatendida = demandaatendida(padroes, quantpadroes, demandas, auxsolucao);
    }while(!demandafoiatendida);
        
        solucao = auxsolucao; */
        
}