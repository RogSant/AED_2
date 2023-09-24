#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Separa (int p, int r, int v[]) { //Algoritmo retirado do livro "Algoritmos em linguagem C" de Paulo feofiloff, pagina 85
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++)
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    v[r] = v[j], v[j] = c;
    return j;
}

void Quicksort (int p, int r, int v[]) { //Algoritmo retirado do livro "Algoritmos em linguagem C" de Paulo feofiloff, pagina 87
    int j;
    if (p < r) {
        j = Separa (p, r, v);
        Quicksort (p, j - 1, v);
        Quicksort (j + 1, r, v);
    }
}

int main() {
    int k, i;
    double t;
    printf("Qual o tamanho do vetor?: ");
    scanf("%d", &k);
    int v[k];
    for(i = 0; i < k; i++) {
        v[i] = rand();
    }
    t = 0.0;
    clock_t begin = clock();
    Quicksort(0, k, v);
    clock_t end = clock();
    t += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f seg\n", t); //Até aqui ordena inteiros aleatórios

    int j[k], z = k;
    for(int x = 0; x < k; x++) {
        j[x] = v[z-1];
        z--;
    };

    printf("\n");

    t = 0.0;
    clock_t comeco = clock();
    Quicksort(0, k, j);
    clock_t fim = clock();
    t += (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f seg\n", t); // Aqui ordena int em ordem decrescente
    return 0;
}
