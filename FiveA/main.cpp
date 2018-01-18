#include <iostream>
#include <cstdlib> 
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <io.h>
#include "util.h"
#include "padroes.h"
#include "GRASP.h"



#define MAXINSTANCIAS 100 
//#define QUANTPADROESINICIALMENTE 20
#define QUANTCLASSES 18


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // ******Declarando as variaveis.******
    time_t datahorasegundos;
    struct tm *horario;
    srand ((unsigned)time(NULL)); // passando o tempo como sementa para a funcao rand().
    ofstream arquivosetups, arquivoobjetos, arquivotempo, arquivomediasetups, arquivomediaobjetos, arquivomediatempo, arquivosolucao, arquivopadroes, arquivodescricao;
    double mediasetups, mediaobjetos, mediatempo;
    unsigned long totalsegundos, totalsegundosantes, totalsegundosdepois;
    
    stringstream strnumclasse;
   
      
    vector <unsigned int> itens;
    vector <long> demandas;
    unsigned int comprimentobase;// Comprimento da barra base.
    unsigned int quantpadroes; // *************quantidade padroes inicialmente.****************
    unsigned int quantitens;
    unsigned int** padroes;
   
    vector <unsigned int> solucao; // vai guardar o resultado da GRASP.
    
    string nomeclasse;
    unsigned int quantobjetosutilizados;
    unsigned int quantpadroesdiferentesutilizados;
    unsigned int custoquantpadroesusados; 
    unsigned int custoquantpadroesdiferentesusados;
    unsigned int maxiteracoesGRASP;
    unsigned int maxiteracoesILS;
    unsigned int maxiteracoessemmelhoraMRNA;
    //unsigned int maxiteracoesMS;
    float alpha;
    // ******Fim declaracao variaveis.******
    
    
    
    
    
    // ******Lendo dados do usuario******
    cout << "Custo de cada setup: ";
    cin >> custoquantpadroesdiferentesusados;
    cout << endl;
    cout << "Custo de cada objeto: ";
    cin >> custoquantpadroesusados;
    cout << endl;
      
    
    /*cout << "Nome da classe: ";
    cin >> nomeclasse;
    cout << endl;*/
    
    cout << "Maximo iteracoes GRASP: ";
    cin >> maxiteracoesGRASP;
    cout << endl;
    
    /*cout << "Maximo iteracoes MS: ";
    cin >> maxiteracoesMS;
    cout << endl;*/
    
    cout << "Maximo iteracoes ILS: ";
    cin >> maxiteracoesILS;
    cout << endl;
    
    cout << "Maximo iteracoes sem melhora da Metodo randomico nao ascendente/descedente: ";
    cin >> maxiteracoessemmelhoraMRNA;
    cout << endl;
    
  //  cout << "Alpha: ";
   // cin >> alpha;
   // cout << endl;
    // ******Fim lendo dados do usuario******
    
    system("rmdir /S /Q resultados");// apaga a pasta "resultados". 
    
    mkdir("resultados");// cria a pasta resultados.
    for (int numclasse = 1; numclasse <= QUANTCLASSES; numclasse++) { 
        
        
        strnumclasse.str("");// para limpar o conteúdo que já tem (ele armazena e o .clear nao funciona).
        strnumclasse << numclasse; 
        
    
        if (numclasse < 10) {
            nomeclasse = "classe0" + strnumclasse.str();
            
        }
        else {
            nomeclasse = "classe" + strnumclasse.str();
        }
           
        
       
        cout << endl << "*********** " << nomeclasse << " iniciada! "<< "***********"  << endl << endl;
        abrirarquivos(nomeclasse, arquivosetups, arquivoobjetos, arquivotempo, arquivomediasetups, arquivomediaobjetos, arquivomediatempo, arquivosolucao, arquivopadroes, arquivodescricao); // abrindo os arquivos.
        

        // ******Executando a GRASP para todas as instancias selecionadas******
        for (unsigned int numinstancia = 1; numinstancia <= MAXINSTANCIAS; numinstancia++) {    
            pegarinstancias(itens, demandas, comprimentobase, numinstancia, nomeclasse);// Guarda os itens e suas demandas nos respectivos vetores.
            
            time(&datahorasegundos);
            horario = localtime(&datahorasegundos);
            totalsegundosantes = converterhorarioparasegundos(horario);

            quantitens = itens.size();

            // *************quantidade padroes inicialmente.****************
            quantpadroes = quantitens * 8;//4;

            // é gerada uma matriz de padroes e a quantidade de padroes pode ser atualiza para atender a demanda.
            padroes = gerarpadroes(quantpadroes, itens, comprimentobase);

         //   exibirpadroes(padroes, quantpadroes, quantitens);

            GRASP(solucao, padroes, quantpadroes, demandas, custoquantpadroesusados, custoquantpadroesdiferentesusados, maxiteracoesGRASP, maxiteracoesILS, maxiteracoessemmelhoraMRNA, alpha);   
            //MS(solucao, padroes, quantpadroes, demandas, custoquantpadroesusados, custoquantpadroesdiferentesusados, maxiteracoesMS, maxiteracoessemmelhoraMRNA);
       

            time(&datahorasegundos);
            horario = localtime(&datahorasegundos);
            totalsegundosdepois = converterhorarioparasegundos(horario);

            quantpadroesdiferentesutilizados = calcularquantpadroesdiferentesusados(solucao);
            quantobjetosutilizados = calcularquantpadroesusados(solucao);
            totalsegundos = totalsegundosdepois - totalsegundosantes;


            // Armazenando os dados nos arquivos.
            arquivosetups << quantpadroesdiferentesutilizados << "\n"; 
            arquivoobjetos << quantobjetosutilizados << "\n";
            arquivotempo << totalsegundos << "\n";
            for (unsigned int cont = 0; cont < quantpadroes; cont++) {
                arquivosolucao << solucao[cont] << " ";
            }
            arquivosolucao << "\n";
            
            arquivopadroes << "Instancia " << numinstancia << endl << endl;
            for (unsigned int padrao = 0; padrao < quantpadroes; padrao++) {
                for (unsigned int item = 0; item < quantitens; item++) {
                    arquivopadroes << padroes[padrao][item] << ' ';
                }
                arquivopadroes << endl;
            }
            arquivopadroes << endl;
            // Fim armazenamento dos dados nos arquivos.
            

            // limpando os vetores e matrizes para poderem ser usados novamente.
            solucao.clear();
            desalocarmemoriamatriz(padroes, quantpadroes);
            // fim da limpeza.

            //Exibindo qual instacia ja foi concluida.
            cout << "            Instancia " << numinstancia << " concluida!" << endl;

        }
        // ******Fim execucao GRASP.******
         


        // ******Fechando os arquivos.******
        arquivosetups.close();
        arquivoobjetos.close();
        arquivotempo.close();
        arquivosolucao.close();
        arquivopadroes.close();
        // ******Fim fechamento de arquivos.******
        

        // Armazenando os dados nos arquivos.
        mediasetups = calcularmediadadosarquivo("resultados/" + nomeclasse + "/setups.txt");
        mediaobjetos = calcularmediadadosarquivo("resultados/" + nomeclasse + "/objetos.txt");
        mediatempo = calcularmediadadosarquivo("resultados/" + nomeclasse + "/tempo.txt");
        cout << nomeclasse << ": " << mediasetups << ' ' << mediaobjetos << ' ' << mediatempo << endl;

        arquivomediasetups << mediasetups << "\n";
        arquivomediaobjetos << mediaobjetos << "\n";
        arquivomediatempo << mediatempo << "\n";
        arquivodescricao << "Custo setup = " << custoquantpadroesdiferentesusados << "\n" << "Custo Objeto = " << custoquantpadroesusados << "\n"
                << "Quantidade de padroes usados = 8 * Quantidade de itens" << "\n" << "GRASP = " << maxiteracoesGRASP << "\n"
                << "ILS = " << maxiteracoesILS << "\n" << "MRNA piora contiguas = " << maxiteracoessemmelhoraMRNA;
        // Fim armazenamento dos dados nos arquivos.
        

        // ******Fechando os arquivos.******
        arquivomediasetups.close();
        arquivomediaobjetos.close(); 
        arquivomediatempo.close();
        arquivodescricao.close();
        // ******Fim fechamento de arquivos.******
        
    }
    
    cout << "Todas as classes foram resolvidas com sucesso!" << endl << endl;
    cout << '\a'; 
    system("PAUSE");
    
    return 0;
}

