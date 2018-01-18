#include <vector>
#include <climits>
#include <cstdlib>
#include "construcaoGRASP.h"
#include "util.h"

using namespace std;

// Calcula o valor de um padrao. 
unsigned int calcularvalorpadrao(unsigned int** padroes, unsigned int numpadrao, vector <long> demandas) {
    unsigned int quantitens = demandas.size();// numero de itens.
    unsigned int auxvalorpadrao = 0;
    for (unsigned int cont = 0; cont < quantitens; cont++) {
        auxvalorpadrao = auxvalorpadrao + padroes[numpadrao][cont] * demandas[cont];
    }
    return auxvalorpadrao; // Valor do padrao e o somatorio a quantidade escolhida de cada item * demanda dele.
}

// Classifica os padroes colocando o valor de cada um na segunda coluna da matrizpadroesclassificados.
void classificarpadroes(unsigned int** padroes, unsigned int quantpadroes, unsigned int** matrizpadroesclassificados, vector <long> demandas) {
    // colocando os respectivos numeros de padroes na primeira coluna da matriz.
    for (unsigned int cont = 0; cont < quantpadroes; cont++) {
        matrizpadroesclassificados[cont][0] = cont;
    }
    
    // calcula o valor de cada padrao e coloca o valor na segunda coluna da matrizpadroesclassificados.
    for (unsigned int cont = 0; cont < quantpadroes; cont++) {
        matrizpadroesclassificados[cont][1] = calcularvalorpadrao(padroes, cont, demandas); 
    }   
}

// Ordena a matrizpadroesclassificados de forma decrescente.
void ordenarmatrizpadroesclassificados(unsigned int** matrizpadroesclassificados, unsigned int quantpadroes) {
    unsigned int menorvalor;
    unsigned int linhamenorvalor = 0;// = 0 apenas para inicializar e não mostrar mensagem de erro ao compilar.
    unsigned int auxtroca;
    for (int cont1 = quantpadroes - 1; cont1 >= 0; cont1--) {// cont1 não precisa ir até o 0, mas sim até o 1 (tem que corrigir 15/05/16)
        menorvalor = UINT_MAX; 
        for (int cont2 = 0; cont2 <= cont1; cont2++) {
            if (matrizpadroesclassificados[cont2][1] < menorvalor) {
                menorvalor = matrizpadroesclassificados[cont2][1];
                linhamenorvalor = cont2;
            }
        }
        // faz a troca dos valores e dos numeros do padroes de acordo com a ordenacao.
        matrizpadroesclassificados[linhamenorvalor][1] = matrizpadroesclassificados[cont1][1];
        matrizpadroesclassificados[cont1][1] = menorvalor;
        auxtroca = matrizpadroesclassificados[linhamenorvalor][0];
        matrizpadroesclassificados[linhamenorvalor][0] = matrizpadroesclassificados[cont1][0];
        matrizpadroesclassificados[cont1][0] = auxtroca;     
    }
    
    /*for (int cont = 0; cont < quantpadroes; cont++) {
        cout << matrizpadroesclassificados[cont][0] << ' ' << matrizpadroesclassificados[cont][1] << endl;
    }
    cout << endl; */
    
}

// Metodo de construcao da GRASP.
void GRASPconstrucao(vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas, float alpha) {
    unsigned int** padroesclassificados;// primeira [0] coluna guarda o numero do padrao e a segunda [1] o beneficio dele. 
    vector <unsigned int> RCL;// Lista Restrita de Candidatos. 
    float condicaoRCL;// Recebe resultado da conta min + alpha(max - min).
    unsigned int cont = 0; 
    bool condicaoRCLpreenchida; // condicao de parada para preencher a rcl.
    bool condicaodemandaatendida;
    unsigned int indiceescolhidoRCL;
    unsigned int padraoescolhido;
    //bool primeiraexecucao = true;
    vector <long> auxdemandas;
    auxdemandas = demandas;
    
    
    padroesclassificados = alocarmemoriamatriz(quantpadroes, 2);// alocando memoria para a matriz padroesclassificados. 
    
    
    
    do {
            classificarpadroes(padroes, quantpadroes, padroesclassificados, auxdemandas);

           // auxdemandas.clear();
            auxdemandas = demandas;

            ordenarmatrizpadroesclassificados(padroesclassificados, quantpadroes);
            
            alpha = (float) (rand() % 11) / 10; 
            condicaoRCL = padroesclassificados[quantpadroes - 1][1] + alpha * (padroesclassificados[0][1] - padroesclassificados[quantpadroes - 1][1]);   
        // Colocando os elementos aceitos na lista RCL.
        do {
            if (cont < quantpadroes) {
                condicaoRCLpreenchida = padroesclassificados[cont][1] >= condicaoRCL;
                if (condicaoRCLpreenchida) {
                    RCL.push_back(padroesclassificados[cont][0]);
                    cont++;
                }    
            }
            else {
                condicaoRCLpreenchida = false;
            }
        } while (condicaoRCLpreenchida); 
        cont = 0;
        
        indiceescolhidoRCL = rand() % RCL.size();
        padraoescolhido = RCL[indiceescolhidoRCL];
        

        
        
        
        solucao[padraoescolhido]++;// incrimenta 1 no padrao escolhido;
        RCL.clear();
        
        condicaodemandaatendida = demandaatendida(padroes, quantpadroes, demandas, solucao);
        
        if (!condicaodemandaatendida) { // então atualiza o vetor de auxdemandas.
            atualizarauxdemandas(padroes, quantpadroes, auxdemandas, solucao);
        }
        
        
           
    } while (!condicaodemandaatendida); 
     
    
    
    desalocarmemoriamatriz(padroesclassificados, quantpadroes); // Desalocando memoria para a matriz.
}

