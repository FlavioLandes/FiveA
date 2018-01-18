#ifndef UTIL_H
#define UTIL_H



#endif /* UTIL_H */

#include <fstream>
#include <vector>

using namespace std;

// Abri os arquivos.
void abrirarquivos(string nomeclasse, ofstream& arquivosetups, ofstream& arquivoobjetos, ofstream& arquivotempo, ofstream& arquivomediasetups, ofstream& arquivomediaobjetos, ofstream& arquivomediatempo, ofstream& arquivosolucao, ofstream& arquivopadroes, ofstream& arquivodescricao);

// Coloca o tamanho da barra base na sua variavel correspondente e coloca os itens, demandas em seus respectivos vetores.
void pegarinstancias(vector <unsigned int>& itens, vector <long>& demandas, unsigned int& comprimentobase, unsigned int numinstancia, string nomeclasse);

// Aloca memoria para uma matriz conforme necessario.
unsigned int** alocarmemoriamatriz(unsigned int quantlinhas, unsigned int quantcolunas);

// Desaloca a memoria de uma matriz.
void desalocarmemoriamatriz(unsigned int** matriz, unsigned int quantlinhas);

// Retorna o comprimento do menor item.
unsigned int comprimentomenoritem(vector <unsigned int>);

// Copia um padrao da matriz padroes para um novo vetor (copiapadrao).
void copiarpadrao(unsigned int** padroes, unsigned int copiapadrao[], unsigned int indicepadrao, unsigned int quantitens);


// Calcula quanto sobrou da barra base.
int calcularsobra(vector <unsigned int> itens, unsigned int padrao[], unsigned int comprimentobase);


// Zera uma matriz, no caso a matriz de padroes.
void zerarmatriz(unsigned int** matriz, unsigned int quantpadroes, unsigned int quantitens);


//Exibe todos padrões.
void exibirpadroes(unsigned int** padroes, unsigned int quantpadroes, unsigned int quantitens);


// Calculando o somatorio de cada item nos padroes escolhidos e atualizando sua demanda na auxdemandas.
void atualizarauxdemandas(unsigned int** padroes, unsigned int quantpadroes, vector <long>& auxdemandas, vector <unsigned int> solucao);

// Verifica se a demanda dos itens foram atendidas.
bool demandaatendida(unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas, vector <unsigned int> solucao);


// Calcula a quantidade de padroes diferentes usados.
unsigned int calcularquantpadroesdiferentesusados(vector <unsigned int> solucao);


// Calcula a quantidade de padroes usados.
unsigned int calcularquantpadroesusados(vector <unsigned int> solucao);

// Calcula a funcao objetivo.
unsigned int calcularvalorsolucao(vector <unsigned int> solucao, unsigned int custoquantpadroesusados, unsigned int custoquantpadroesdiferentesusados);


// Refina a solucao tirando alguns padroes desnecessarios.
void refinarsolucao (vector <unsigned int>& solucao, unsigned int** padroes, unsigned int quantpadroes, vector <long> demandas);


// ordena a matriz solucaoordenada para fazer o refinamento na solucao.
void ordenarmatrizsolucaoordenada(unsigned int** matrizsolucaoordenada, unsigned int quantpadroes);


// imprimi o valor da solucao.
void imprimirsolucao (vector <unsigned int> solucao);


// convertendo o horario (hora, minutos e segundos) para segundos.
unsigned long converterhorarioparasegundos(struct tm* horario);


// calcula a media dos dados de long que estao em um arquivo.
double calcularmediadadosarquivo(string nomearquivo);