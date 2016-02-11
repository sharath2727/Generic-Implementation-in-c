/*
Code      : Generic LinkedList - Push operation
*/

#include<stdio.h>
#include<stdlib.h>


struct node{
  void *data;
  struct node *next;
};

void push(struct node **head, void *new_data,size_t element_size){
  
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = malloc(element_size);
  new_node->next =(*head);

  int i;
  for(i=0;i<element_size;i++){
    *(char *)(new_node->data + i) = *(char *)(new_data + i);
  }

  *head = new_node;    
}


void printList(struct node *head, void (*fun_ptr)(void *)){

  while(head!=NULL){
    (*fun_ptr)((head)->data);
    head = head->next;
  }
  printf("\n");

}

void printInt(void *data){
  printf("%d-->",*(int *)data);
}


//Driver to test the program

int main(void){
  struct node *start = NULL;
  unsigned element_size = sizeof(int);
  int i;
  int arr[] = {10,20,30,40,50};
  int size = sizeof(arr)/sizeof(arr[0]);

  for(i=0;i<size;i++)
    push(&start,&arr[i],element_size);
 
  printList(start,printInt); 
  return 0;
}
