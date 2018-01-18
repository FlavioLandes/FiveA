#include <vector>
#include <cstdlib>
#include "util.h"

using namespace std;


void MSconstrucao(vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas) {
   
    
    bool demandafoiatendida = false;
    unsigned int padraoescolhido;
    
    
    while (!demandafoiatendida) {
        padraoescolhido = rand() % quantpadroes;
        solucao[padraoescolhido] += 20;
        
        demandafoiatendida = demandaatendida(padroes, quantpadroes, demandas, solucao);
    }   
}
