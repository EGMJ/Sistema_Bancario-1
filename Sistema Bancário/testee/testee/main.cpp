#include <iostream>
#include <conio2.h>
#include "fila.h"
using namespace std;

struct TPessoa
{
    int un_tempo;
    char status;
};

void leitura(int &n,int &m,int &x,int &y,int &t)//Faz a entrada dos dados solicitados ao usuário
{
    cout << "Caixas para pessoas com necessidades especiais: ";
    cin >> n;
    cout << "Caixas para propositos gerais: ";
    cin >> m;
    cout << "Quantas pessoas entram no caixa por unidade de tempo: ";
    cin >> x;
    cout << "Quantas pessoas ja estao nas filas: ";
    cin >> y;
    cout << "Quantidade de unidades de tempo para a simulacao: ";
    cin >> t;
}

bool distribuicao(TFila<TPessoa> *&ce, TFila<TPessoa> *&cg, int n, int m, int &menor)//Distribui as pessoas nas filas
{

    TPessoa *novo  = new TPessoa; //Aloca um espaço para uma nova pessoa
    int aux, esp, indice;
    aux = rand() % 100; //Sorteia se ela possui necessidades especiais ou não
    if (aux<5)
    {
        esp=rand()%100;
        if (esp>30)//Se esp maior que 30, ela levara 7ut para ser atendida
        {
            novo->un_tempo= 7;
        }
        else
        {
            novo->un_tempo= 10; //Se não levará 10
        }
        novo->status ='E';//Define o status como especial
        while(true){ //Enquanto true verifica qual a fila possui o menor tamanho
            for (int i=0; i<n; i++)
            {
                if(ce[i].qtd==0){ //Verifica se alguma fila estiver vazia, insere nela
                    InsereFimF(ce[i], *novo);
                    return false;
                }else{
                if (ce[i].qtd<menor)// Se a fila não estiver vazia, verifica qual possui o menor tamanho
                {
                    menor=ce[i].qtd;
                    indice=i;

                }

            }

            }
            InsereFimF(cg[indice],*novo);//Insere a pessoa na fila com o menor tamanho
            menor=1000;
            return false;
        }

    }
    else
    {
        if (aux>45)
        {
            novo->un_tempo= 1;
        }
        else
        {
            novo->un_tempo= 2;
        }
        novo->status ='N';
        while(true){        //Verifica enquanto verdadeiro a lista de menor tamanho
            for (int i=0; i<m; i++)
            {
                if(cg[i].qtd==0){   //Verifica as lista que estão vazias
                    InsereFimF(cg[i], *novo);//Caso alguma esteja vazia insere nela
                    return false;   //Finaliza o loop
                }else{
                if (cg[i].qtd<menor)    //Se não estiver vazia, procura a de menor quantidade
                {
                    menor=cg[i].qtd;
                    indice=i;

                }

            }

            }
            InsereFimF(cg[indice],*novo);   //Insere na de menor quantidade
            menor=1000;
            return false;
        }






        //laço para retirar o primeiro da fila depois do atendimento
        for(int i=0;i<m;i++){
            TElemento<TPessoa> *save=new TElemento<TPessoa>;
            save=cg[i].inicio;
            if(save->dado.un_tempo==1){
                RemoveInicioF(cg[i]);
            }
        }

    }

}
int main()
{
    srand (time(NULL));
    int n,m,x,y,t;
    int menor=1000;
    leitura(n,m,x,y,t);
    TFila<TPessoa> *ce, *cg;
    ce = new TFila <TPessoa> [n];
    cg = new TFila <TPessoa> [m];
    for (int i=0; i<n; i++)     //Laço para inicializar as filas especias
    {
        InicializaF(ce[i]);
    }
    for (int i=0; i<m; i++)     //Laço para inicializar as filas gerais
    {
        InicializaF(cg[i]);
    }
    for (int i=y; i>0; i--)     //Distribui as pessoas que já estão nas filas
    {
        distribuicao(ce,cg,n,m,menor);
    }
    for(int i=0;i<t;i++){       //Vai passando as unidades de tempo
        for(int j=0;j<x;j++){   //Insere x pessoas a cada unidade de tempo
        distribuicao(ce,cg,n,m,menor);
        }
    }

    // Exibição das filas
    for (int i=0; i<n; i++)
    {
        cout<<endl<<"caixa especial "<<i+1<<": "<<ce[i].qtd<<endl;
    }
    for (int i=0; i<m; i++)
    {
        cout<<endl<<"caixa geral "<<i+1<<": "<<cg[i].qtd<<endl;
    }

    return 0;
}
