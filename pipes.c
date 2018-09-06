#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define LEER 0
#define ESCRIBIR 1

void escribir(int descr[2], char *frase);
void leer();

int main(){
    int descr_one[2]; /*Descriptores de E/S de la tubería*/
    int descr_two[2]; /*Descriptores de E/S de la tubería*/
    int bytesleidos;
    char mensaje[100];
    char *frase;

    printf("Ejemplo de tuberia entre padre e hijo.\n");
    pipe(descr_one);
    pipe(descr_two);

    if (fork() == 0){ //Proceso hijo
        frase="El padre prueba al hijo si la transferencia es buena";
        escribir(descr_one,frase);
        leer(descr_two, mensaje, bytesleidos);
    }else{ //Proceso Padre
        leer(descr_one, mensaje, bytesleidos);
        frase="***El hijo prueba al padre si la transferencia es buena***";
        escribir(descr_two,frase);
    }//if - else
    return 0;
}//main

void escribir(int descr[2], char *frase){
    close(descr[LEER]);
    write(descr[ESCRIBIR], frase, strlen(frase));
    close(descr[ESCRIBIR]);
}//leer
    
void leer(int descr[2], char mensaje[100], int bytesleidos){
    close(descr[ESCRIBIR]);
    bytesleidos = read(descr[LEER], mensaje, 100);
    mensaje[bytesleidos]='\0';
    printf("Bytes leídos: %d\n", bytesleidos);
    printf("Mensaje del Padre: %s\n", mensaje);
    close(descr[LEER]);
}//escribir