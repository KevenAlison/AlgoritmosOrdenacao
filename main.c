#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<conio.h>

int main()
{

    int vetorAleatorio[] = {3, 6, 2, 5, 4, 3, 7, 1, pow(10,9)};
    int vetorDecrescente[] = {7, 6, 5, 4, 3, 3, 2, 1};
    int vetorCrescente[] = {1,2,3,3,4,5,6,7};


    size_t n = sizeof(vetorAleatorio)/sizeof(vetorAleatorio[0]);



      //selectionSort(vetorAleatorio, n);

       // insertionSort(vetorAleatorio, n);

       // bubbleSort(vetorAleatorio, n);


    printVetor(vetorAleatorio, n);

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
    int i, j, temp;
    for(i=1; i<n-1 ; i++){
        for(j=0 ; j<n-2; j++){
            if(vetor[j]>vetor[j+1]){
                troca(vetor, j, j+1);
            }
        }
    }
}

void insertionSort(int* vetor[], int n){
    int i, hole, val;
    for (i=1; i<=n-1; i++){
        val = vetor[i];
        hole=i;
        while (val < vetor[hole-1]){
            vetor[hole] = vetor[hole-1];
            hole--;
        }
    vetor[hole] = val;
    }
}

void mergeSort(int* vetor[]){

}

