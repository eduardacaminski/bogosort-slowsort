#include <stdio.h>
#include <stdlib.h>
#include <time.h>



long long chamadas = 0; 

void slowSort(int v[], int i, int j) {
    int m, temp;
    chamadas++;
    if (i >= j) {
        return;
    }

    m = (i + j) / 2;           

    slowSort(v, i, m);         
    slowSort(v, m + 1, j);     

    if (v[j] < v[m]) {         
        temp = v[j];           
        v[j] = v[m];
        v[m] = temp;
    }

    slowSort(v, i, j - 1);     
}



void slow(int v[], int n) {
    slowSort(v, 0, n - 1);
}



double cronometrar(void (*functionPtr)(int[], int), int vetor[], int tamanho, int runs) {
    int i, j;
    clock_t start, end;
    double total = 0;
    int vet[tamanho];

    for (i = 0; i < runs; i++) {
        for (j = 0; j < tamanho; j++) {
            vet[j] = vetor[j];
        }
        start = clock();
        (*functionPtr)(vet, tamanho);
        end = clock();
        total += end - start;
    }

    return total / CLOCKS_PER_SEC;
}

void randomVet(int vetor[], int tamanho) {
    int i;
    srand(0);
    for (i = 0; i < tamanho; i++) {
        vetor[i] = rand();
    }
}



#define SIZE 200

int main() {
    int vet[SIZE], n, runs;
    double tempo;

    randomVet(vet, SIZE);

    printf("n runs tempo_medio_s chamadas\n");
    for (n = 10; n <= SIZE; n += 10) {
       
        if (n <= 60) runs = 200;
        else if (n <= 100) runs = 50;
        else if (n <= 150) runs = 10;
        else runs = 3;

        chamadas = 0;
        tempo = cronometrar(&slow, vet, n, runs) / runs;
        printf("%d %d %.9f %lld\n", n, runs, tempo, chamadas / runs);
        fflush(stdout);
    }
    return 0;
}
