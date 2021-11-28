#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

#define hijos 3

int main()
{
  int tid, i; 
  
  for (i = 1; i <= hijos ; i++){
    tid = fork(); 
    if (tid ==0){
      break;
    }
  }

  if (tid!=0){
    printf("Soy el proceso padre %d, i = %d \n", getpid(), i);
  }
  else{
    printf("Soy el proceso hijo, %d, i = %d \n", getpid(), i);
  }
  

  sleep(30); 
  return 0;  
}