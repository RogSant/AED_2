#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insercao(int n, int v[]) { //Algoritmo retirado do livro "Algoritmos em linguagem C" de Paulo feofiloff, pagina 60
    int i, j, x;
    for (j = 1; /*A*/ j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x;
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
    Insercao(k, v);
    clock_t end = clock();
    t += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f seg", t); //Até aqui ordena int em ordem aleatórtis

    int j[k], z = k;
    for(int x = 0; x < k; x++) {
        j[x] = v[z-1];
        z--;
    };

    t = 0.0;
    clock_t comeco = clock();
    Insercao(k, j);
    clock_t fim = clock();
    t += (double)(fim - comeco) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f seg", t); //Aqui ordena int em ordem decrescente
    return 0;
}
