#include <vector>
#include "util.h"
#include "MRNAD.h"
#include "pertubacao.h"

using namespace std;

// Metodo Randomico nao ascendente/descedente.
void ILS(vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas, unsigned int custoquantpadroesusados, unsigned int custoquantpadroesdiferentesusados, unsigned int maxiteracoesILS, unsigned int maxiteracoessemmelhoraMRNAD) {
    vector <unsigned int> melhorsolucao;
    vector <unsigned int> solucaopertubada;
    vector <unsigned int> solucaopertubadabuscalocal;
    unsigned int valormelhorsolucao;
    unsigned int valorsolucaopertubadabuscalocal;
    
    // Busca Local
    melhorsolucao = solucao;
    metodorandomiconaoascdesc(melhorsolucao, padroes, quantpadroes, demandas, custoquantpadroesusados, custoquantpadroesdiferentesusados, maxiteracoessemmelhoraMRNAD);
    valormelhorsolucao = calcularvalorsolucao(melhorsolucao, custoquantpadroesusados, custoquantpadroesdiferentesusados);
    // Fim Busca Local
    
    for(unsigned int contiteracoes = 1; contiteracoes <= maxiteracoesILS; contiteracoes++) {
        //Pertubacao
        solucaopertubada = melhorsolucao;
        // funcao para efetuar a pertubacao na solucao. Faz parte da ILS.
        pertubacao(solucaopertubada, quantpadroes);
        // Fim da pertubacao
        
        // Busca Local    
        solucaopertubadabuscalocal = solucaopertubada;
        metodorandomiconaoascdesc(solucaopertubadabuscalocal, padroes, quantpadroes, demandas, custoquantpadroesusados, custoquantpadroesdiferentesusados, maxiteracoessemmelhoraMRNAD);
        // Fim Busca Local
 

        valorsolucaopertubadabuscalocal = calcularvalorsolucao(solucaopertubadabuscalocal, custoquantpadroesusados, custoquantpadroesdiferentesusados);
        if (valorsolucaopertubadabuscalocal < valormelhorsolucao) {
            melhorsolucao = solucaopertubadabuscalocal;
            valormelhorsolucao = valorsolucaopertubadabuscalocal;
        }
        
    }
    
    solucao = melhorsolucao;// atualizando o valor da solucao que veio da GRASP.
    
} 