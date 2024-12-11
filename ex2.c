// Diego Miranda - 2210996
// Felipe Cancella - 2210487

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#define NUM_THREADS 2
#define MAX 10000

int vet[MAX];

void *soma(void *i) {
  int sum = 0, cont;

  for (cont = 0; cont < MAX; cont++) {
    vet[cont] = vet[cont] * 2;
    vet[cont] += 2;
  }
  pthread_exit(NULL);
}

int main(void) {
  int i,j,stat=0;
  struct timeval t1, t2;
  pthread_t threads[NUM_THREADS];
  
  for (i = 0; i < MAX; i++) {
    vet[i] = 5;
  }

  gettimeofday(&t1, NULL);

  // Vamos criar nova tarefa 2 vezes
  for (i = 0; i < NUM_THREADS; i++) {
    printf("Creating thread %d\n", i);
    pthread_create(&threads[i], NULL, soma, (void *)i);
  }

  // Espera cada uma das 2 threads terminarem
  for (i = 0; i < NUM_THREADS; i++)
    pthread_join(threads[i], NULL);

  gettimeofday(&t2, NULL);

  j=vet[0];
  for (i = 0; i < MAX; i++) {
    if (vet[i] != j){
      stat=1; //indicador de concorrencia
    }
  }
  if (stat==1)
    printf("\n-----\nHouve concorrencia!\n-----\n");
  else
    printf("\n-----\nNao houve concorrencia!\n-----\n");
  
  printf("\n-----\nTempo de exec: %ld usec ou %0.6f sec\n-----\n",
         t2.tv_usec - t1.tv_usec, (t2.tv_usec - t1.tv_usec) * 0.000001);
  
}
