#include <vector>
#include <cstdlib>
#include <ctime>
#include "util.h"

using namespace std;

// pega um vizinho da solucao corrente.
void pegarvizinho(vector <unsigned int>& vizinho, vector <unsigned int> solucao) {
    unsigned int padraoseradecrementado;
    unsigned int padraoseraincrementado;
    unsigned int quantpadroes;
    bool trocou = false;
    unsigned int guardavalorpadraoseradecrementado; // guarda quantos padroes tem de um determinado padrao na solucao.
    //unsigned int guardavalorpadraoseraincrementado;  // guarda quantos padroes tem de um determinado padrao na solucao.
    unsigned int incremento;
    quantpadroes = solucao.size();
    
    
    //vizinho = solucao;
    
    /* do {
        do {
            padraoseradecrementado = rand() % quantpadroes;
            padraoseraincrementado = rand() % quantpadroes;
        } while (padraoseradecrementado == padraoseraincrementado); // garante nao pegar o mesmo padrao para fazer a troca.

        if (vizinho[padraoseradecrementado] > 0) {
            vizinho[padraoseradecrementado]--;
            vizinho[padraoseraincrementado]++;

            trocou = true;
        }
        //imprimirsolucao(vizinho);
    } while (!trocou); */
    
    vizinho = solucao;
    do { 
        //vizinho = solucao;
        do {
            padraoseradecrementado = rand() % quantpadroes;
            padraoseraincrementado = rand() % quantpadroes;
        }while (padraoseradecrementado == padraoseraincrementado); // garante nao pegar o mesmo padrao para fazer a troca.
            
        if (vizinho[padraoseradecrementado] > 0) {     
            guardavalorpadraoseradecrementado = vizinho[padraoseradecrementado];
            vizinho[padraoseradecrementado] = 0; 
            //guardavalorpadraoseraincrementado = vizinho[padraoseraincrementado];
            
           // if (guardavalorpadraoseraincrementado > 0) {
                /*if ((guardavalorpadraoseradecrementado == 1) || (guardavalorpadraoseradecrementado == 2)) {// se decrementei 1 ou 2, entao vou incrementar 1.
                    vizinho[padraoseraincrementado]++;
                    trocou = true;
                } 
                else { // decremento foi maior do que 1    */
                   /* if (guardavalorpadraoseradecrementado == 3) { // apagar aqui
                        incremento = 4;
                    } */
                    incremento = guardavalorpadraoseradecrementado;// / 2 + 2;// maxincremente pega o resultado INTEIRO da expressao, pois ele e um inteiro.                  
                    vizinho[padraoseraincrementado] += incremento;
                    trocou = true;
                //}
            //}
        }
            
            
    }while (!trocou); 
    
   /* vizinho = solucao;
        unsigned int padrao1, padrao2, valorpadrao1, valorpadrao2;
        do {
            padrao1 = rand() % quantpadroes;
            padrao2 = rand() % quantpadroes;
        }while (padrao1 == padrao2); // garante nao pegar o mesmo padrao para fazer a troca.
        
        valorpadrao1 = vizinho[padrao1];
        valorpadrao2 = vizinho[padrao2];
        
        if (valorpadrao1 > 0) {
            if (valorpadrao1 > 1) {
                vizinho[padrao1] -= 2;
            }
            else {
                vizinho[padrao1]--;
            }
        } 
        else {
            vizinho[padrao1]++;
        }
        
        if (valorpadrao2 > 0) {
            if (valorpadrao2 > 1) {
                vizinho[padrao2] -= 2;
            }
            else {
                vizinho[padrao2]--;
            }
        } 
        else {
            vizinho[padrao2]++;
        }
            
      */  
}

// Metodo Randomico nao ascendente/descedente.
void metodorandomiconaoascdesc(vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas, unsigned int custoquantpadroesusados, unsigned int custoquantpadroesdiferentesusados, unsigned int maxiteracoessemmelhora) {
    vector <unsigned int> vizinho;
    unsigned int cont = 1;
    bool vizinhovalido;
    unsigned int valorsolucao;
    unsigned int valorvizinho;
    vector <unsigned int> auxsolucao;
    vector <unsigned int> vizinhoantes;
    unsigned int contsolucaoigual = 0;
     
    auxsolucao = solucao;
    refinarsolucao(auxsolucao, padroes, quantpadroes, demandas); 
    valorsolucao = calcularvalorsolucao(auxsolucao, custoquantpadroesusados, custoquantpadroesdiferentesusados);
    
    while (cont <= maxiteracoessemmelhora) {
       // if (calcularquantpadroesdiferentesusados(solucao) == 1) {// serve para quando for só trocar o vizinho[x] > 0.
       //     break;
       // } 
        pegarvizinho(vizinho, solucao);
        vizinhovalido = demandaatendida(padroes, quantpadroes, demandas, vizinho);
        if (vizinhovalido) {
            vizinhoantes = vizinho; 
            refinarsolucao(vizinho, padroes, quantpadroes, demandas);   
            valorvizinho = calcularvalorsolucao(vizinho, custoquantpadroesusados, custoquantpadroesdiferentesusados); 
            
            if (valorvizinho <= valorsolucao) {
                
                
                //garante que nao fique preso em um local plano
                if (valorvizinho == valorsolucao) {
                    contsolucaoigual++;
                    if (contsolucaoigual > 100) {
                        break;
                    }
                }
                else {
                        contsolucaoigual = 0;
                } 
                // fim que nao fique preso em um local plano
                
               // solucao = vizinho;
                solucao = vizinhoantes;
                valorsolucao = valorvizinho;
                cont = 1;
            }
            else {
                cont++;
            }
            
            
        }
        else {
            cont++;
        }
    }
    refinarsolucao(solucao, padroes, quantpadroes, demandas); 
} 

/*// nova busca local
void BuscaLocalFB(vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas) {
    unsigned int** matrizsolucaoordenada;
    //unsigned int padrao;
    unsigned int cont = 0;
    unsigned int contdecrescente;
    unsigned int numpadrao;
    vector <unsigned int> solucaotemporaria;
    bool auxdemandaatendida;
    double quantdecremento = 0; 
    double quantincremento = 0;
    
    matrizsolucaoordenada = alocarmemoriamatriz(quantpadroes, 2);
    
    solucaotemporaria = solucao;

    
    // colocando os numeros dos padroes e suas quantidade dentro da matriz solucao para ela ser ordenada depois.
    for (long padrao = 0; padrao < quantpadroes; padrao++) {
             matrizsolucaoordenada[padrao][0] = padrao;
             matrizsolucaoordenada[padrao][1] = solucao[padrao];
        }
    
    // ordenando a matriz solucaoordenada.
    ordenarmatrizsolucaoordenada(matrizsolucaoordenada, quantpadroes);
    
    // testando se e possivel tirar padroes. Se o decremento de um padrao nao faz diferenca, entao continue tentando decrementa-lo ate nao poder mais. Depois passa para o proximo padrao.
    do {
        contdecrescente = quantpadroes; 
  
        //numpadrao = matrizsolucaoordenada[cont][0];
        if (matrizsolucaoordenada[cont][1] > 0) {
            quantdecremento = matrizsolucaoordenada[cont][1];
            matrizsolucaoordenada[cont][1] = 0;
            
            if ((quantdecremento == 1) || (quantdecremento == 2)) {// se decrementei 1 ou 2, entao vou incrementar 1.
                    
                    do {
                        matrizsolucaoordenada[contdecrescente][1]++;
                        for(unsigned int conttemp = 0; conttemp < quantpadroes; conttemp++) {
                            unsigned int conttemp2 = 0;
                            while (matrizsolucaoordenada[conttemp2][0] != conttemp) {
                                conttemp2++;
                            }
                            solucaotemporaria[conttemp] = matrizsolucaoordenada[conttemp2][1];
                        }

                        auxdemandaatendida = demandaatendida(padroes, quantpadroes, demandas, solucaotemporaria);
                        if (!auxdemandaatendida) {
                            matrizsolucaoordenada[contdecrescente][1]--;
                            solucaotemporaria[matrizsolucaoordenada[contdecrescente][0]]--;
                            contdecrescente--;
                        }
                    }while ((!auxdemandaatendida) && (contdecrescente >= 0));
            } 
            else { // decremento foi maior do que 1    
                    do {
                        matrizsolucaoordenada[contdecrescente][1] += quantdecremento / 2 + 2;

                        for(unsigned int conttemp = 0; conttemp < quantpadroes; conttemp++) {
                            unsigned int conttemp2 = 0;
                            while (matrizsolucaoordenada[conttemp2][0] != conttemp) {
                                conttemp2++;
                            }
                            solucaotemporaria[conttemp] = matrizsolucaoordenada[conttemp2][1];
                        }

                        auxdemandaatendida = demandaatendida(padroes, quantpadroes, demandas, solucaotemporaria);
                        if (!auxdemandaatendida) {
                            matrizsolucaoordenada[contdecrescente][1] -= quantdecremento / 2 + 2;
                            solucaotemporaria[matrizsolucaoordenada[contdecrescente][0]] -= quantdecremento / 2 + 2;
                            contdecrescente--;
                        }
                    }while ((!auxdemandaatendida) && (contdecrescente >= 0));
                   
            }
        }
        else { // passa para o proximo padrao.
            cont++;
        }
        
        
    } while (cont < quantpadroes);
    
    desalocarmemoriamatriz(matrizsolucaoordenada, quantpadroes);// arrumado/////
    

    solucao = solucaotemporaria;

} */


