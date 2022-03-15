#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int lista_num[1000], i;
int quant_num;
int average;
int minimum;
int maximum;

void *media() { 
  int sum=0;
  for(i = 1; i <= quant_num; i++){
    sum= sum + lista_num[i]; 
  }
  average = sum / quant_num; 
}
void *min() { 
  minimum = lista_num[1]; 
  for(int i = 1; i < quant_num; i++)
  {
    if(minimum > lista_num[i])
    {
      minimum = lista_num[i]; 
    }
  }
} 
void *max() { 
  maximum = lista_num[1]; 
  for (int i = 1; i <= quant_num; i++) 
  {
    if(maximum < lista_num[i]) 
    {
      maximum = lista_num[i]; 
    }
  }
}

int main() {
  int nums;
  scanf("%d", &quant_num);
  int count = 0; 
  for (int i = 1; i < quant_num + 1; i++) 
  {
    nums = 0;
    scanf("%d", &nums);
    lista_num[i] = nums; 
  } 

  int t;
  pthread_t thread1; 
  pthread_t thread2; 
  pthread_t thread3; 
  
  t = pthread_create(&thread1, NULL, &media, NULL); 
  pthread_join(thread1,NULL); 
  
  t = pthread_create(&thread2, NULL, &min, NULL); 
  pthread_join(thread2,NULL); 
  
  t = pthread_create(&thread3, NULL, &max, NULL);
  pthread_join(thread3,NULL); 
  
  printf("The average value is %d",average);  
  printf("\nThe minimum value is %d",minimum); 
  printf("\nThe maximum value is %d",maximum); 
  return 0; 
}
