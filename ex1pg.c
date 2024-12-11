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
#define NUM_THREADS 10
#define MAX 100000


int vet[MAX];

void* soma (void* i){
  int ini=0, fim=9999, cont;
  cont = (long int) i;
  cont = (int) cont;
  cont *= 10000;
  ini+=cont;
  fim+=cont;

  for (cont=ini; cont<=fim; cont++){
    vet[cont] = vet[cont]*2+cont;
  }
  pthread_exit(NULL);
}


int main(void){
  int i, ini=0, fim=9999, sum=0;
  struct timeval t1, t2;
  pthread_t threads[NUM_THREADS];



  for(i=0;i<MAX;i++){
    vet[i]=5;
  }

  //Vamos criar nova tarefa 10 vezes
  gettimeofday(&t1,NULL);

  for(i=0;i < NUM_THREADS;i++)
  {
  printf("Creating thread %d\n", i);
  pthread_create(&threads[i], NULL, soma, (void *)i);
  }


  //Espera cada uma das 10 threads terminarem
  for(i=0; i < NUM_THREADS; i++)
    pthread_join(threads[i],NULL);


  gettimeofday(&t2,NULL);


  for(i=0;i<MAX;i++){
    sum+=vet[i];
  }
  printf("\n-----\nSoma: %d \n-----\n",sum);

  printf("\n-----\nTempo de exec: %ld usec ou %0.6f sec\n-----\n",t2.tv_usec-t1.tv_usec,(t2.tv_usec-t1.tv_usec)*0.000001);

}