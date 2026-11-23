#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int estaOrdenado(int v[], int n) {
	int i;
    for ( i = 0; i < n - 1; i++) {
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

int main() {
    srand(time(NULL));
    int n = 8, i;;
    int v[8];
    for (i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }
    long long t = bogosort(v, n);
    printf("Embaralhamentos: %lld\n", t);
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
