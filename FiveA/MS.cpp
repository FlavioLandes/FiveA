#include <vector>
#include <climits>
#include "util.h"
#include "construcaoMS.h"
#include "MRNAD.h"

using namespace std;

void MS(vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas, unsigned int custoquantpadroesusados, unsigned int custoquantpadroesdiferentesusados,  unsigned int maxiteracoesMS, unsigned int maxiteracoessemmelhoraMRNAD) {

    vector <unsigned int> melhorsolucao; 
    vector <unsigned int> solucaotemp;
    vector <unsigned int> vetorzerado (quantpadroes, 0); // serve para zerar outros vetores
    unsigned int valormelhorsolucao = UINT_MAX;
    unsigned int valorsolucaotemp;  
    
    
    for(unsigned int cont = 1; cont <= maxiteracoesMS; cont++) {
        
        solucaotemp = vetorzerado;
        
        
        // Metodo de construcao da MS.
        MSconstrucao(solucaotemp, padroes, quantpadroes, demandas);

       

        
        // Busca local.        
        // Metodo Randomico nao ascendente/descedente.
        metodorandomiconaoascdesc(solucaotemp, padroes, quantpadroes, demandas, custoquantpadroesusados, custoquantpadroesdiferentesusados, maxiteracoessemmelhoraMRNAD);
        
        
        //refinarsolucao(solucaotemp, padroes, quantpadroes, demandas);
        
        //cout << "Rf" << endl;
        
       // testeRef = calcularvalorsolucao(solucaotemp, custoquantpadroesusados, custoquantpadroesdiferentesusados);
        
        /*if ((testeBL - testeRef) > 1 ) {
            cout << endl;
            cout << "BL: " << testeBL << endl;
            cout << "Ref: " << testeRef << endl;
        } */
       /* if (!demandaatendida(padroes, quantpadroes, demandas, solucaotemp)) {
            cout << "Demanda nao antendida!";
            system("PAUSE");
            
        } */
        
        
        
        
        valorsolucaotemp = calcularvalorsolucao(solucaotemp, custoquantpadroesusados, custoquantpadroesdiferentesusados);  
        if (valorsolucaotemp < valormelhorsolucao) {
            melhorsolucao = solucaotemp;
            valormelhorsolucao = valorsolucaotemp;
        }   
        
    }
    
    solucao = melhorsolucao; // copia os dados da melhor solucao para o vetor solucao.
}