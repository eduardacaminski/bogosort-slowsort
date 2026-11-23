#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int estaOrdenado(int v[], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void embaralhar(int v[], int n) {
    int i;
    for (i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

long long bogosort(int v[], int n) {
    long long tentativas = 0;
    while (!estaOrdenado(v, n)) {
        embaralhar(v, n);
        tentativas++;
    }
    return tentativas;
}


long long totalEmbaralhamentos = 0;

void bogo(int v[], int n) {
    totalEmbaralhamentos += bogosort(v, n);
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



#define SIZE 12

int main() {
    int vet[SIZE], n;
    int runs;
    double tempo;
    double fat = 1;

    randomVet(vet, SIZE);

    printf("n runs tempo_medio_s embaralhamentos_medios n_fatorial\n");
    for (n = 1; n <= SIZE; n++) {
        fat *= n;
       
        if (n <= 8) runs = 200;
        else if (n == 9) runs = 100;
        else if (n == 10) runs = 40;
        else if (n == 11) runs = 12;
        else runs = 4;

        totalEmbaralhamentos = 0;
        tempo = cronometrar(&bogo, vet, n, runs) / runs;
        printf("%d %d %.9f %.1f %.0f\n", n, runs, tempo,
               (double) totalEmbaralhamentos / runs, fat);
        fflush(stdout);
    }
    return 0;
}
