#include <stdio.h>
#include <stdlib.h>

int *arr = NULL;
int size = 0;

void add(int item){
    arr = (int*) realloc(arr, (size+1) * sizeof(int));
    arr[size] = item;
    //printf("Address %d = %p\n",item,&arr[size]);
    size++;    
}

void insert(int index, int item){
  int i;
  arr = (int*) realloc(arr, (++size) * sizeof(int));
  for (i = size; i >= index; i--) arr[i] = arr[i-1];
  arr[index] = item;
}

int GetSize (){
  return size;
}

int remove(int index){
  int i;
  int temp = arr[index];
  for (i = index; i <= size-1; i++){
    arr[i] = arr[i+1];
  }
  arr = (int*) realloc(arr, (--size) * sizeof(int));
  return temp;
}

void set(int index, int item){
  arr[index] = item;  
}

int get(int index){
  return arr[index];
}

void prtArr(){
  int i;
  for (i = 0; i < size+2; i++){
       printf("array[%d] = %d || address = %p\n", i, (arr[i]), &arr[i]);   
    }
}

int main(){
    int i;
    
    //CHECK ADD()
    for (i = 0; i < 10; i++){
      add(i);
    }
  prtArr();
    printf("\n");
    
    //CHECK INSERT()
    insert(5, 17);
    insert(6, 171);
    insert(7, 1717);
    prtArr();
    printf("\n");
    
     //CHECK SIZE()
     printf("Array size = %d\n\n", GetSize());
     
     //CHECK REMOVE()
     for (i = 0; i < 5; i++){
      remove(0);
    }
     prtArr();
    printf("\n");
    
     //CHECK SET()
     for (i = size/2; i < size; i++){
      set(i, i*4);
    }
     prtArr();
    printf("\n");
    
     //CHECK GET()
     printf("Get arr[0] = %d\n\n", get(0));
    return 0; 
}