/*
Code: Generic Implementation of Stack
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  void *data;
  int loglength;
  int alloclength;
  int elementsize;
}Stack;


void StackNew(Stack *s,size_t element_size){

  s->elementsize = element_size;
  s->loglength   = 0;
  s->alloclength = 4;
  s->data        = malloc(s->alloclength*s->elementsize);
};

void StackPush(Stack *s, void *elemAddr){
  
  void *destAddr;
  
  if(s->loglength == s->alloclength){
    s->alloclength *= 2;
    s->data = realloc(s->data,s->alloclength*s->elementsize);
  } 
  destAddr = (char *)s->data + s->loglength*s->elementsize;
  mempcpy((char *)destAddr,(char *)elemAddr,s->elementsize);
  s->loglength += 1;
}

void StackPop(Stack *s, void *elemAddr){

  const void *sourceAddr;
  if(s->loglength > 0 ){
    s->loglength -= 1;
    sourceAddr = (char *)s->data + s->loglength*s->elementsize;
    mempcpy((char *)elemAddr, (char *)sourceAddr, s->elementsize);
  }
}  

void StackDispose(Stack *s){

  free(s->data); // realloc(s->data,0);
  printf("Heap allocation freed up\n");
}

int StackEmpty(Stack *s){
  return s->loglength == 0;
}



int main(void){

  int a[]={10,20,30,40,50,60};
  int array_size = sizeof(a)/sizeof(a[0]);
  int element_size = sizeof(int);
  int i;
  Stack stackInt;
 
  StackNew(&stackInt,element_size);
  for(i=0;i<array_size;i++){
    StackPush(&stackInt,&a[i]);
  }
  int value; 
  while(!StackEmpty(&stackInt)){
    StackPop(&stackInt, &value);
    printf("Popped Value: %d\n",value);
  }

  StackDispose(&stackInt);
  return 0;
}
  
