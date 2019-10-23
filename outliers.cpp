#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

using namespace std;


void troca(double* a, double* b){ 
    double t = *a; 
    *a = *b; 
    *b = t; 
} 

int separa (double *arr, int low, int high){ 
    double pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++){ 
    
        if (arr[j] <= pivot){ 
            i++;    // increment index of smaller element 
            troca(&arr[i], &arr[j]); 
        } 
    } 
    troca(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(double *arr, int low, int high){ 
    if (low < high){ 
        /* pi is separaing index, arr[p] is now 
           at right place */
        int pi = separa(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main(){
    
    char file_name[MAX];
    double **v, limiar;
    int n, k, i, j, cont=0;
    FILE *entrada;

    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNão encontrei o arquivo!\n");
        exit(EXIT_FAILURE);
    }
    fscanf(entrada, "%d %d %lf", &n, &k, &limiar);
    v = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
    {
        v[i] = (double *)malloc(n * sizeof(double));
        for (j = 0; j < n; j++)
            fscanf(entrada, "%lf", &v[i][j]);
    }
    fclose(entrada);




    // CODE
    for(i=0; i<n; i++){ //entra linha por linha
        
        quickSort(v[i], 0, n-1); //coloca linha i em ordem crescente (sem i=j)

        if(v[i][k+1]>limiar){ //vai até posição k e checa se é maior que L
            cont++; //caso seja maior, aumenta contagem de outliers
        }   
    }
    cout << cont << endl; //imprime qntd de outliers

    for (i = 0; i < n; i++)
        free(v[i]);
    free(v);
    
    return 0;
}