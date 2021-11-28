#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>  //biblioteca para compartir la memoria
#include<sys/wait.h> //biblioteca para que el proceso espere 
#include<sys/types.h>
#include <sys/ipc.h>

//wait: Espera lo necesario (Se detiente hast que termine su hijo)
// sleep: Espera algunos segundos 

int main(){
    long id, id_mem_com;
    int status,i,j,hijo; 
    int* shm; 

  //  malloc(sizeoff(int)); //apuntador entero 

    id_mem_com = shmget(5678, 2, IPC_CREAT| 0666); 
    //chmod -> cambia permisos a los archivos y a los directorios

    shm = shmat(id_mem_com, NULL, 0); 
    *shm = 0; //Entrar al contenido del apuntador 
    id = fork(); 
    if (id !=0) { //proceso padre
        printf("Proceso padre %d\n", getpid());
        hijo = wait(&status);
        printf("El valor de la variable compartida shm = %d \n", *shm);
        printf("hijo = %d, id= %ld\n", hijo, id);
    }
    else{
        sleep(3); 
        printf("Soy el hijo, voy a incrementar una variable compartida\n"); 
        *shm = (*shm) + 1;
    }
    
    return 0; 
}