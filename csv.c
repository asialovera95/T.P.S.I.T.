/*Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui può essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define BSIZE 1024
#define DIM 20000

typedef struct game {
  int rank;
  char* name;
  char* platform;
  int year;
  char* genre;
  char* publisher;
  float nA_Sales;
  float eU_Sales;
  float jP_Sales;
  float other_Sales;
  float global_Sales;
} Game;

int main() {
  /* code */
  FILE *fp;
  Game data[DIM];

  fp = fopen("vgsales.csv", "r");

  if (fp == NULL){
    printf("Il file non esiste");
  }else{
    printf("Il file esiste");
  }

  readFile(data, DIM);



  fclose(fp);
}


void readFile(Game data[DIM], int nMax){    //nMax=DIM
  FILE *fp;
  //int k=0;
  char buffer[BSIZE];
  char* field;
  int counter=0;

  fp = fopen("vgsales.csv", "r");

/*
  while(k<nMax && (fscanf(fp, "%d %s %s %d %s %s %f %f %f %f %f", &game[k].rank, game[k].name, game[k].platform, &game[k].year, game[k].genre, game[k].publisher, &game[k].nA_Sales, &game[k].eU_Sales, &game[k].jP_Sales, &game[k].other_Sales, &game[k].global_Sales))!=EOF){
    scanf("%d %s %s %d %s %s %f %f %f %f %f", &game[k].rank, game[k].name, game[k].platform, &game[k].year, game[k].genre, game[k].publisher, &game[k].nA_Sales, &game[k].eU_Sales, &game[k].jP_Sales, &game[k].other_Sales, &game[k].global_Sales);
    k++;
  }
*/

//split
  while(fgets(buffer, BSIZE, fp)){
    field=strtok(buffer, ",");
    data[counter].rank = atoi(field);
    field= strtok(NULL, ",");
    data[counter].name=field;
    field=strtok(NULL, ",");
    data[counter].platform= field;
    field=strtok(NULL, ",");
    data[counter].year=atoi(field);
    field=strtok(NULL, ",");
    data[counter].genre=field;
    field=strtok(NULL, ",");
    data[counter].publisher=field;
    field=strtok(NULL, ",");
    data[counter].nA_Sales=atof(field);
    field=strtok(NULL, ",");
    data[counter].eU_Sales=atof(field);
    field=strtok(NULL, ",");
    data[counter].jP_Sales=atof(field);
    field=strtok(NULL, ",");
    data[counter].other_Sales=atof(field);
    field=strtok(NULL, ",");
    data[counter].global_Sales=atof(field);

    }



  }


}
