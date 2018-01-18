#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <io.h>
#include "util.h"
#include <ctime>


using namespace std;

// Abre os arquivos.
void abrirarquivos(string nomeclasse, ofstream& arquivosetups, ofstream& arquivoobjetos, ofstream& arquivotempo, ofstream& arquivomediasetups, ofstream& arquivomediaobjetos, ofstream& arquivomediatempo, ofstream& arquivosolucao, ofstream& arquivopadroes, ofstream& arquivodescricao) {
    string caminho = "";
    string nomepastaclasse;
    
    nomepastaclasse = "resultados/" + nomeclasse;
    mkdir(nomepastaclasse.c_str());// criando a pasta com o nome da classe.
    
    caminho = "resultados/" + nomeclasse + "/setups.txt";
    arquivosetups.open(caminho.c_str(), ios::out | ios::trunc);
    if (!arquivosetups.is_open()) {
        cout << "Ocorreu falha ao abrir o setups.txt" << endl;
        cout << "Feche o programa e verifique isso!";
        system("PAUSE");
    }
    
    caminho = "resultados/" + nomeclasse + "/objetos.txt";
    arquivoobjetos.open(caminho.c_str(), ios::out | ios::trunc);
    if (!arquivoobjetos.is_open()) {
        cout << "Ocorreu falha ao abrir o objetos.txt" << endl;
        cout << "Feche o programa e verifique isso!";
        system("PAUSE");
    }
    
    caminho = "resultados/" + nomeclasse + "/tempo.txt";
    arquivotempo.open(caminho.c_str(), ios::out | ios::trunc);
    if (!arquivotempo.is_open()) {
        cout << "Ocorreu falha ao abrir o tempo.txt" << endl;
        cout << "Feche o programa e verifique isso!";
        system("PAUSE");
    }
    
    caminho = "resultados/" + nomeclasse + "/mediasetups.txt";
    arquivomediasetups.open(caminho.c_str(), ios::out | ios::trunc);
    if (!arquivomediasetups.is_open()) {
        cout << "Ocorreu falha ao abrir o mediasetups.txt" << endl;
        cout << "Feche o programa e verifique isso!";
        system("PAUSE");
    }
    
    caminho = "resultados/" + nomeclasse + "/mediaobjetos.txt";
    arquivomediaobjetos.open(caminho.c_str(), ios::out | ios::trunc);
    if (!arquivoobjetos.is_open()) {
        cout << "Ocorreu falha ao abrir o mediaobjetos.txt" << endl;
        cout << "Feche o programa e verifique isso!";
        system("PAUSE");
    }
    
    caminho = "resultados/" + nomeclasse + "/mediatempo.txt";
    arquivomediatempo.open(caminho.c_str(), ios::out | ios::trunc);
    if (!arquivomediatempo.is_open()) {
        cout << "Ocorreu falha ao abrir o mediatempo.txt" << endl;
        cout << "Feche o programa e verifique isso!";
        system("PAUSE");
    }
    
    caminho = "resultados/" + nomeclasse + "/solucao.txt";
    arquivosolucao.open(caminho.c_str(), ios::out | ios::trunc);
    if (!arquivosolucao.is_open()) {
        cout << "Ocorreu falha ao abrir o solucao.txt" << endl;
        cout << "Feche o programa e verifique isso!";
        system("PAUSE");
    }
    
    caminho = "resultados/" + nomeclasse + "/padroes.txt";
    arquivopadroes.open(caminho.c_str(), ios::out | ios::trunc);
    if (!arquivopadroes.is_open()) {
        cout << "Ocorreu falha ao abrir o padroes.txt" << endl;
        cout << "Feche o programa e verifique isso!";
        system("PAUSE");
    }
    
    caminho = "resultados/" + nomeclasse + "/descricao.txt";
    arquivodescricao.open(caminho.c_str(), ios::out | ios::trunc);
    if (!arquivodescricao.is_open()) {
        cout << "Ocorreu falha ao abrir o descricao.txt" << endl;
        cout << "Feche o programa e verifique isso!";
        system("PAUSE");
    }    
} 

// Coloca o tamanho da barra base na sua variavel correspondente e coloca os itens, demandas em seus respectivos vetores.
void pegarinstancias(vector <unsigned int>& itens, vector <long>& demandas, unsigned int& comprimentobase, unsigned int numinstancia, string nomeclasse){
    ifstream arquivo;// ("classe09"); 
    
    itens.clear();
    demandas.clear();
    
    arquivo.open(nomeclasse.c_str());
    if (arquivo.is_open()) {
        string linha;
        unsigned int continstancias = 0;
        unsigned int contitens = 7;
        unsigned int contcomprimentobase = 7;
        unsigned int contdemandas = 17;
        unsigned int contlinha = 0;
        string auxitens;  
        string auxdemandas;
        string auxcomprimentobase;
        
        // percorre o arquivo ate encontra a instancia desejada.
        while ((continstancias < numinstancia) && (!arquivo.eof())) {
            getline(arquivo, linha);
            if (linha.length() == 10) {
                continstancias++;
            }
        }
        
        
        getline(arquivo, linha);
        while ((linha.length() != 10) && (!arquivo.eof())) {
            contlinha++;
            if (contlinha == 2){// Lendo o comprimento da barra base.
                while ((linha[contcomprimentobase]) != ' ') {// Lendo cada item
                    auxcomprimentobase = linha[contcomprimentobase] + auxcomprimentobase; 
                    contcomprimentobase--;
                }
                comprimentobase = atoi(auxcomprimentobase.c_str());
            }
            if (linha.length() == 18) {// 18 e por conta de como os dados estao no arquivo de instancia.
                while ((linha[contitens]) != ' ') {// Lendo cada item
                    auxitens = linha[contitens] + auxitens; 
                    contitens--;
                }
                while ((linha[contdemandas]) != ' ') {// Lendo cada demanda
                    auxdemandas = linha[contdemandas] + auxdemandas; 
                    contdemandas--;
                }
            }
            if ((auxitens != "") && (auxdemandas != "")) {
                unsigned int tempitens;// Guarda o valor da string para ser convertida em int.
                unsigned int tempdemandas;// Guarda o valor da string para ser convertida em int.
                tempitens = atoi(auxitens.c_str());
                tempdemandas = atoi(auxdemandas.c_str());
                
                itens.push_back(tempitens);
                demandas.push_back(tempdemandas);   
            }
            
            // Retornando os valores padroes das variaveis abaixo.
            contitens = 7;
            contdemandas = 17;
            auxitens.clear();
            auxdemandas.clear();
            
            //Lendo nova linha do arquivo.
            getline(arquivo, linha);
        }
        arquivo.close();
    }
    else {
        cout << "Arquivo nao pode ser aberto!" << endl; 
    }
}


// Aloca memoria para uma matriz conforme necessario.
unsigned int** alocarmemoriamatriz(unsigned int quantlinhas, unsigned int quantcolunas) {
    unsigned int** matriz;
    matriz = new unsigned int*[quantlinhas];
    for (unsigned int cont = 0; cont < quantlinhas; cont++){
        matriz[cont] = new unsigned int[quantcolunas];
    }
    return matriz;
}

// Desaloca a memoria de uma matriz.
void desalocarmemoriamatriz(unsigned int** matriz, unsigned int quantlinhas){
    for (unsigned int cont = 0; cont < quantlinhas; cont++){
            delete[] matriz[cont];
        }
    delete[] matriz;
}



// Retorna o comprimento do menor item.
unsigned int comprimentomenoritem(vector <unsigned int> itens) {
    unsigned int menor = itens[0];
    
    for (unsigned int indice = 1; indice < itens.size(); indice++) {
        if (itens[indice] < menor) {
              menor = itens[indice];
        }    
    }
    return menor;
}


// Copia um padrao da matriz padroes para um novo vetor (copiapadrao).
void copiarpadrao(unsigned int** padroes, unsigned int copiapadrao[], unsigned int indicepadrao, unsigned int quantitens) {
  for (unsigned int item = 0; item < quantitens; item++) {
      copiapadrao[item] = padroes[indicepadrao][item];
  }    
}

// Calcula quanto sobrou da barra base.
int calcularsobra(vector <unsigned int> itens, unsigned int padrao[], unsigned int comprimentobase) {
 unsigned int totalusado = 0;
 unsigned int totalitens = itens.size();
 for (unsigned int indice = 0; indice < totalitens; indice++) {
     totalusado = totalusado + padrao[indice] * itens[indice]; 
 }
 return comprimentobase - totalusado;
}

// Zera uma matriz, no caso a matriz de padroes.
void zerarmatriz(unsigned int** matriz, unsigned int quantpadroes, unsigned int quantitens){
    for(unsigned int linha = 0; linha < quantpadroes; linha++) {
        for(unsigned int coluna = 0; coluna < quantitens; coluna++) {
            matriz[linha][coluna] = 0;
        }
    }
}

//Exibe todos padrões.
void exibirpadroes(unsigned int** padroes, unsigned int quantpadroes, unsigned int quantitens){
    for(unsigned int linha = 0; linha < quantpadroes; linha++) {
                for(unsigned int coluna = 0; coluna < quantitens; coluna++) {
                    cout << padroes[linha][coluna] << ' ';
                }
                cout << endl;
    }
}

// Calculando o somatorio de cada item nos padroes escolhidos e atualizando sua demanda na auxdemandas.
void atualizarauxdemandas(unsigned int** padroes, unsigned int quantpadroes, vector <long>& auxdemandas, vector <unsigned int> solucao) {
    unsigned int quantitens = auxdemandas.size();
    long somatorio = 0;
    long temp;
    // Calculando o somatorio de cada item nos padroes escolhidos e atualizando sua demanda.
    for (unsigned item = 0; item < quantitens; item++) {
        for (unsigned int padrao = 0; padrao < quantpadroes; padrao++) {
            somatorio += solucao[padrao] * padroes[padrao][item];
        }
        temp = auxdemandas[item];
        if ((temp - somatorio) >= 0) {
            auxdemandas[item] -= somatorio;
        }
        else {// deu valor negativo, entao a demanda daquele item e zerada.
            auxdemandas[item] = 0;
        }
        somatorio = 0;
    } 
}

// Verifica se a demanda dos itens foram atendidas.
bool demandaatendida(unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas, vector <unsigned int> solucao) {
    unsigned int quantitens = demandas.size();
    unsigned int item = 0;
    long somatorio = 0;
    bool itemdemandaatendida;
    
    // Calculando o somatorio de cada item nos padroes escolhidos e verificando se atende a demanda de cada item.
    do {
        for (unsigned int padrao = 0; padrao < quantpadroes; padrao++) {
            somatorio += solucao[padrao] * padroes[padrao][item];
        }
        itemdemandaatendida = somatorio >= demandas[item];
        item++;
        somatorio = 0;
    } while ((itemdemandaatendida) && (item < quantitens));
    
    /*for (int cont = 0; cont < auxdemandas.size(); cont++) {
        cout << auxdemandas[cont] << ' ';
    }
    cout << endl; */
    
    return itemdemandaatendida;// se todos os itens diverem suas demandas atendidas, então o itemdemandaatendida vai ficar com true.
}

// Calcula a quantidade de padroes diferentes usados.
unsigned int calcularquantpadroesdiferentesusados(vector <unsigned int> solucao) {
    unsigned int total = 0;
    unsigned int tamanhovetor = solucao.size();
    for (unsigned int cont = 0; cont < tamanhovetor; cont++) {
        if (solucao[cont] > 0) {
            total++;
        }
    }
    return total;
}


// Calcula a quantidade de padroes usados.
unsigned int calcularquantpadroesusados(vector <unsigned int> solucao) {
    unsigned int total = 0;
    unsigned int tamanhovetor = solucao.size();
    for (unsigned int cont = 0; cont < tamanhovetor; cont++) {
        total += solucao[cont];
    }
    return total;
}

// Calcula a funcao objetivo.
unsigned int calcularvalorsolucao(vector <unsigned int> solucao, unsigned int custoquantpadroesusados, unsigned int custoquantpadroesdiferentesusados) {
    unsigned int total;
    
    total = (custoquantpadroesusados * calcularquantpadroesusados(solucao)) + (custoquantpadroesdiferentesusados * calcularquantpadroesdiferentesusados(solucao));
    return total;
}

// Refina a solucao tirando alguns padroes desnecessarios.
void refinarsolucao (vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas) {
    unsigned int** matrizsolucaoordenada;
    //unsigned int padrao;
    unsigned int cont = 0;
    unsigned int numpadrao;
    vector <unsigned int> solucaotemporaria;
    bool auxdemandaatendida;
    
    matrizsolucaoordenada = alocarmemoriamatriz(quantpadroes, 2);
    
    solucaotemporaria = solucao;
    /*for (long cont = 1; cont < maxrefinacao; cont++) {
        padrao = rand() % quantpadroes;
        if (solucaotemporaria[padrao] > 0) {
            solucaotemporaria[padrao]--;
            auxdemandaatendida = demandaatendida(padroes, quantpadroes, demandas, solucaotemporaria);
            if (!auxdemandaatendida) {
                solucaotemporaria[padrao]++; // Desfaz a operacao.
            }
        }
    } */
    
    // colocando os numeros dos padroes e suas quantidade dentro da matriz solucao para ela ser ordenada depois.
    for (unsigned int padrao = 0; padrao < quantpadroes; padrao++) {
             matrizsolucaoordenada[padrao][0] = padrao;
             matrizsolucaoordenada[padrao][1] = solucao[padrao];
        }
    
    // ordenando a matriz solucaoordenada.
    ordenarmatrizsolucaoordenada(matrizsolucaoordenada, quantpadroes);
    // testando se e possivel tirar padroes. Se o decremento de um padrao nao faz diferenca, entao continue tentando decrementa-lo ate nao poder mais. Depois passa para o proximo padrao.
    do {
  
        numpadrao = matrizsolucaoordenada[cont][0];
        if (solucaotemporaria[numpadrao] > 0) {
            solucaotemporaria[numpadrao]--;
            auxdemandaatendida = demandaatendida(padroes, quantpadroes, demandas, solucaotemporaria);
            if (!auxdemandaatendida) {
                solucaotemporaria[numpadrao]++; // Desfaz a operacao.
                cont++;
            }
        }
        else { // passa para o proximo padrao.
            cont++;
        }
        
        
    } while (cont < quantpadroes);
    
    desalocarmemoriamatriz(matrizsolucaoordenada, quantpadroes);// arrumado/////
    

    solucao = solucaotemporaria;

}


// ordena a matriz solucaoordenada para fazer o refinamento na solucao.
void ordenarmatrizsolucaoordenada(unsigned int** matrizsolucaoordenada, unsigned int quantpadroes) {
    unsigned int maiorvalor;
    int linhamaiorvalor;
    unsigned int auxtroca;
    
    
    for (int cont1 = quantpadroes - 1; cont1 >= 0; cont1--) {
        maiorvalor = 0; 
        for (int cont2 = 0; cont2 <= cont1; cont2++) {
            if (matrizsolucaoordenada[cont2][1] >= maiorvalor) {
                maiorvalor = matrizsolucaoordenada[cont2][1];
                linhamaiorvalor = cont2;
            }
        }
        // faz a troca dos valores e dos numeros do padroes de acordo com a ordenacao.
        matrizsolucaoordenada[linhamaiorvalor][1] = matrizsolucaoordenada[cont1][1];
        matrizsolucaoordenada[cont1][1] = maiorvalor;
        auxtroca = matrizsolucaoordenada[linhamaiorvalor][0];
        matrizsolucaoordenada[linhamaiorvalor][0] = matrizsolucaoordenada[cont1][0];
        matrizsolucaoordenada[cont1][0] = auxtroca;     
    }
    
    /*for (int cont = 0; cont < quantpadroes; cont++) {
        cout << matrizsolucaoordenada[cont][0] << ' ' << matrizsolucaoordenada[cont][1] << endl;
    }
    cout << endl; 
    system("pause");*/
}


// imprimi o valor da solucao.
void imprimirsolucao (vector <unsigned int> solucao) {
    for (unsigned int cont = 0; cont < solucao.size(); cont++) {
        cout << solucao[cont] << ' '; 
    }
    cout << "Padroes diferentes: " << calcularquantpadroesdiferentesusados(solucao) << ' ' << "Padroes:" << calcularquantpadroesusados(solucao);
}


// convertendo o horario (hora, minutos e segundos) para segundos.
unsigned long converterhorarioparasegundos(struct tm* horario) {
    int hora, minutos, segundos;
    unsigned long totalsegundos;
    
    hora = horario->tm_hour;
    minutos = horario->tm_min;
    segundos = horario->tm_sec;
            
   totalsegundos = (hora * 3600) + (minutos * 60) + segundos; 
  
   return totalsegundos;
}

// calcula a media dos dados de long que estao em um arquivo.
double calcularmediadadosarquivo(string nomearquivo) {
    ifstream arquivo;
    double quantdados = 0;
    string strdados;
    unsigned long intdados;
    double somatoriodados = 0;
    double mediasomatoriodados;
    arquivo.open(nomearquivo.c_str()); 
    if (arquivo.is_open()) {
        while (!arquivo.eof()) {
            getline(arquivo, strdados);
            if (strdados != "") { // tem que fazer o teste, pois a ultima linha esta em branco.
                quantdados++;
                intdados = atoi(strdados.c_str());
                somatoriodados += intdados;
            }
        }
        mediasomatoriodados = somatoriodados / quantdados;
        arquivo.close();
    }
    else {
        cout << "Ocorreu falha ao abrir o "  << nomearquivo << endl;
        cout << "Feche o programa e verifique isso!";
        system("PAUSE");
        exit(1);
    }
    
    return mediasomatoriodados;
}