#include <vector>
#include <cstdlib>
#include "util.h"
#include "padroes.h"

using namespace std;


// Verifica se os padroes contem todos os itens da demanda;
bool padroessaovalidos(unsigned int** padroes, unsigned int quantpadroes, vector <unsigned int> itens) {
    unsigned int quantitens = itens.size();
    unsigned int item = 0;
    bool temitem;
    do {
        temitem = false;
        for (unsigned int padrao = 0; padrao < quantpadroes; padrao++) {
            if (padroes[padrao][item] > 0) {
                temitem = true;
            }  
            padrao++;
        }
        item++;
    } while ((item < quantitens) && (temitem));
    
    return temitem;// retorna verdadeiro se os padroes atendem contem os itens.
}


// padroes[indicepadrao][itens].
unsigned int** gerarpadroes(unsigned int& quantpadroes, vector <unsigned int> itens, unsigned int comprimentobase){
    unsigned int** padroes;
    unsigned int compmenoritem = comprimentomenoritem(itens);
    int sobra = compmenoritem;//sobra = compmenoritem + 1;
    unsigned int uintsobra;// para fazer a comparacao da sobra com o compmenoritem usando tipos iguais.
    unsigned int quantitens = itens.size();
    unsigned int auxrand = quantitens;
    unsigned int item = 0; 
    unsigned int copiapadrao[quantitens];
   // bool condicao;// verifica se a sobra é maior ou igual o menor item.
    bool padroesvalidos;
    
    long padroesinvalidos = 0;
    
    
     
    
    padroes = alocarmemoriamatriz(quantpadroes, quantitens);// alocando memoria para a quantidade de padroes.
    

    do {// cria padroes ate eles serem validos.
        zerarmatriz(padroes, quantpadroes, quantitens);// zera a matriz de padroes. 
        for (unsigned int indicepadrao = 0; indicepadrao < quantpadroes; indicepadrao++){
            do {
                item = rand() % auxrand; 
                padroes[indicepadrao][item]++; 
                copiarpadrao(padroes, copiapadrao, indicepadrao, quantitens);
                sobra = calcularsobra(itens, copiapadrao, comprimentobase);
                if (sobra < 0) {// desfaz o que foi feito retirando o acrescimo do ultimo item.
                    padroes[indicepadrao][item]--; 
                    sobra = compmenoritem;//sobra = compmenoritem + 1; 
                }
                uintsobra = sobra; // observar por conta do type-casting
                //condicao = sobra >= compmenoritem; 
            }while (uintsobra >= compmenoritem);  
        }
        
        padroesvalidos = padroessaovalidos(padroes, quantpadroes, itens);
        
        if (!padroesvalidos) {
            padroesinvalidos++;
            if (padroesinvalidos > 30000) {
                //exibirpadroes(padroes, quantpadroes, quantitens);
                //cout << "Quant padroes: " << quantpadroes << " Num padroes invalidos: " << padroesinvalidos << endl;
                desalocarmemoriamatriz(padroes, quantpadroes);
                quantpadroes++;
                padroes = alocarmemoriamatriz(quantpadroes, quantitens);
                padroesinvalidos = 0;
            }
        }
        
    }while (!padroesvalidos);
    
    //exibirpadroes(padroes, quantpadroes, quantitens);
    
    return padroes;
}