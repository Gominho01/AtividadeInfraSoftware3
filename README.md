# AtividadeInfraSoftware3

## Proposito do código

>O código vai pedir para você digitar a quantidade de números que será inserida em um array, em seguida ele vai pedir para ser inserido os números e vai criar 3 threads, uma para pegar o maior valor inserido, outra pegar o menor, e uma que pega a média entre os números inseridos, e finaliza printando no terminal os valores recebidos das threads.

## Funções mínimas do makefile

> Tem 3 funções essenciais pedidas nessa tarefa, o make que compila o código e gera o binário, o make run pra compilar o código e o make clear para apagar o binário gerado.

## Funções no código

```c 
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
```
Essas são as funções para pegar o maximo, minimo e média
## Criação das Threads
```c
  pthread_t thread1; 
  pthread_t thread2; 
  pthread_t thread3; 
  
  t = pthread_create(&thread1, NULL, &media, NULL); 
  pthread_join(thread1,NULL); 
  
  t = pthread_create(&thread2, NULL, &min, NULL); 
  pthread_join(thread2,NULL); 
  
  t = pthread_create(&thread3, NULL, &max, NULL);
  pthread_join(thread3,NULL); 
```
> pthread_create cria a thread

>  pthread_join impede a execução de uma thread até a thread alvo acabar sua execução
  
## Prints
```c
 printf("The average value is %d",average);  
 printf("\nThe minimum value is %d",minimum); 
 printf("\nThe maximum value is %d",maximum); 
```
