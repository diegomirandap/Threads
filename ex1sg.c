/*
// Diego Miranda - 2210996
// Felipe Cancella - 2210487

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX 100000

int main(void) {
  int i, vet[MAX], sum = 0;
  struct timeval t1, t2;

  // Inicializa o vetor com o valor 5
  for (i = 0; i < MAX; i++) {
    vet[i] = 5;
  }
  // Inicia a medição de tempo
  gettimeofday(&t1, NULL);

  // multiplica por 2 e adiciona o índice em cada item do vetor
  for (i = 0; i < MAX; i++) {
    vet[i] = vet[i] * 2 + i;
  }

  // Para a medição de tempo
  gettimeofday(&t2, NULL);

  // Calcula a soma de todos os elementos do vetor
  for (i = 0; i < MAX; i++) {
    sum += vet[i];
  }
  printf("\n-----\nSoma: %d \n-----\n", sum);

  printf("\n-----\nTempo de exec: %lu usec ou %0.6f sec\n-----\n",
         t2.tv_usec - t1.tv_usec, (t2.tv_usec - t1.tv_usec) * 0.000001);
}*/