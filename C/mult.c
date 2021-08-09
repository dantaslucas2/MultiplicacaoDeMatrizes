#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //int dimensao = 10000;
    for (int dimensao = 0; dimensao < 40000; dimensao+=500)
    {
        double **matriz = (double **)malloc (dimensao * sizeof (double*)) ;
        double *vetor = (double *)malloc (dimensao * sizeof (double)) ;
        double *vetor_resultado = (double *)malloc (dimensao * sizeof (double)) ;

        //double vetor[dimensao];
        //double matriz[dimensao][dimensao];
        clock_t inicio, fim;
        clock_t inicioinit, fiminit;

        for (int coluna=0; coluna < dimensao; coluna++)
        matriz[coluna] = (double *)malloc (dimensao * sizeof (double));

        //Inicializando vetor
        for (int i = 0; i < dimensao; i++)
        {
            vetor[i] =  (100000000000 / (double) RAND_MAX) * (double) rand();
        }

        //Inicializando Matriz
        for (int i = 0; i < dimensao; i++)
        {
            for (int o = 0; o < dimensao; o++)
            {
                matriz[i][o] = (100000000000 / (double) RAND_MAX) * (double) rand();
            }
        }

        double result = 0;
        inicio=clock();

        //Linha-coluna
        for (int o = 0; o < dimensao; o++)
        {
            for (int i = 0; i < dimensao; i++)
            {
                result += matriz[o][i] * vetor[i]; 
                //printf("Result = matriz[%d][%d] * vetor[%d] =  %f + %f \n",o,i,i,matriz[o][i], vetor[i]);
            }
            vetor_resultado[o] = result;
            result = 0;
            //printf("Adicionando vetor_resultado[%d]= %f\n",o,vetor_resultado[o]);
        }
        fim=clock();
        float tempo1 = (float)(fim - inicio)/CLOCKS_PER_SEC;

        inicioinit=clock();
        //Coluna-linha
        for (int o = 0; o < dimensao; o++)
        {
            for (int i = 0; i < dimensao; i++)
            {
                result += matriz[o][i] * vetor[i]; 
                //printf("Result = matriz[%d][%d] * vetor[%d] =  %f + %f \n",o,i,i,matriz[o][i], vetor[i]);
            }
            vetor_resultado[o] = result;
            result = 0;
            //printf("Adicionando vetor_resultado[%d]= %f\n",o,vetor_resultado[o]);
        }
        fiminit=clock();
        float tempo2 = (float)(fiminit - inicioinit)/CLOCKS_PER_SEC;

        
        printf("Tempo de execução 1: %f, Tempo de execução 2: %f, dimensão = %d \n", tempo1, tempo2, dimensao);
        for (int linha=0; linha < dimensao; linha++) free (matriz[linha]);
        free (matriz);
        free (vetor);
        free (vetor_resultado);
        
        
    }
    return 0;
}