// PROGRAMA p04.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

typedef struct{
  int op1;
  int op2;
} ops;


void* sumT(void *arg){
  ops* args = (ops*) arg;
  printf("%d + %d = %d\n", args->op1, args->op2, args->op1 + args->op2);
	return NULL;
}
void* subT(void *arg){
  ops* args = (ops*) arg;
  printf("%d - %d = %d\n", args->op1, args->op2, args->op1 - args->op2);
  return NULL;
}
void* quocT(void *arg){
  ops* args = (ops*) arg;
  printf("%d / %d = %lf\n", args->op1, args->op2, (double) args->op1 / args->op2);
  return NULL;
}
void* prodT(void *arg){
  ops* args = (ops*) arg;
  printf("%d * %d = %d\n", args->op1, args->op2, args->op1 * args->op2);
  return NULL;
}

int main(){
	pthread_t threads[4];

  ops operands;
  printf("Insert two operands: ");
  scanf("%d %d", &operands.op1, &operands.op2);

  pthread_create(&threads[0], NULL, sumT, (void *)&operands);
  pthread_create(&threads[1], NULL, subT, (void *)&operands);
  pthread_create(&threads[2], NULL, quocT, (void *)&operands);
  pthread_create(&threads[3], NULL, prodT, (void *)&operands);

  int t;
	for(t=0; t<4; t++){
		pthread_join(threads[t], NULL);
	}
  printf("\n");

	pthread_exit(0);
	return 0;
}
