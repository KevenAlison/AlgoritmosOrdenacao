#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<conio.h>
#include <stdbool.h>

int main()
{

    int vetorAleatorio[] = {3, 6, 2, 5, 4, 3, 7, 1, pow(10,9)};
    int vetorDecrescente[] = {7, 6, 5, 4, 3, 3, 2, 1};
    int vetorCrescente[] = {1,2,3,3,4,5,6,7};

    int valorG = pow(10,6);
    int vetorGrande[valorG];

    int i;
    for(i=0; i<valorG ; i++){
        vetorGrande[i]=rand();
    }


    size_t nVA = sizeof(vetorAleatorio)/sizeof(vetorAleatorio[0]);
    size_t nVD = sizeof(vetorDecrescente)/sizeof(vetorDecrescente[0]);
    size_t nVC = sizeof(vetorCrescente)/sizeof(vetorCrescente[0]);
    size_t nVG = sizeof(vetorGrande)/sizeof(vetorGrande[0]);


        selectionSort(vetorGrande, nVG);

        //insertionSort(vetorAleatorio, n);

        //bubbleSort(vetorAleatorio, n);

        //mergeSort(vetorDecrescente, n);

        //quickSort(vetorDecrescente, 0, n);

        //printVetor(vetorDecrescente, n);
        //printVetor(vetorCrescente, n);
        //printVetor(vetorAleatorio, n);
        printVetor(vetorGrande, nVG);



}

void printVetor(int* vetor[], int n){
    int i;
    for(i = 0; i<n; i++){
        printf("%d ", vetor[i]);

    }
}

void troca(int* vetor, int i, int j){
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

void selectionSort(int* vetor[], int n){
    int i, j, temp;
    for(i=0; i<n-1 ; i++){
        int menorIndex = i;
        for(j=i+1 ; j<n; j++){
            if(vetor[j]<vetor[menorIndex]){
                menorIndex = j;
            }
        }
        troca(vetor, i, menorIndex);
    }
}

void bubbleSort(int* vetor[], int n){
    int i, j, count;
    bool trocou = false;
    for(i=1; i<n-1 ; i++){
        trocou = false;
        for(j=0 ; j<n-i-1; j++){
            if(vetor[j]>vetor[j+1]){
                troca(vetor, j, j+1);
                trocou = true;
            }
        }
    }
    if(trocou==false){
        return;
    }
}

void insertionSort(int* vetor[], int n){
    int i, hole, val;
    for (i=1; i<=n-1; i++){
        val = vetor[i];
        hole=i;
        while (val < vetor[hole-1] && hole>0){
            vetor[hole] = vetor[hole-1];
            hole--;
        }
    vetor[hole] = val;
    }
}

void merge(int* v, int n, int* e, int n1, int* d, int n2){
    int indexV = 0;
    int index1 = 0;
    int index2 = 0;
    while(index1 < n1 && index2 < n2){
        if(e[index1] <= d[index2]){
            v[indexV] = e[index1];
            index1++;
        } else{
            v[indexV] = d[index2];
            index2++;
        }
        indexV++;
    }

    while(index1 < n1){
        v[indexV] = e[index1];
        index1++;
        indexV++;
    }

    while(index2 < n2){
        v[indexV] = d[index2];
        index2++;
        indexV++;
    }
}

void mergeSort(int* vetor[], int n){
 if(n>1){

        int meio = n/2;
        int i,j;
        int n1 = meio;
        int* v1 = (int*)malloc(n1*sizeof(int));
        for(i = 0; i < meio; i++){
            v1[i] = vetor[i];
        }

        int n2 = n-meio;
        int* v2 = (int*)malloc(n2*sizeof(int));
        for(j = meio; j < n; j++){
            v2[j-meio] = vetor[j];
        }

        mergeSort(v1,n1);
        mergeSort(v2,n2);
        merge(vetor,n,v1,n1,v2,n2);

        free(v1);
        free(v2);
    }
}

int particiona(int* vetor[], int ini, int fim){
    int pIndex = ini;
    int pivo = vetor[fim];
    int i;
    for(i = ini; i < fim; i++){
        if(vetor[i] <= pivo){
            troca(vetor,i,pIndex);
            pIndex++;
        }
    }
    troca(vetor,pIndex,fim);
    return pIndex;
}

void quickSort(int* vetor[], int ini, int fim){
    if(fim>ini){
        int indexPivo = particiona(vetor,ini,fim);
        quickSort(vetor,ini,indexPivo-1);
        quickSort(vetor,indexPivo+1,fim);   //indexPivo já está no seu local
    }
}

