#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BSIZE 1024
#define NDATA 17000
struct table
{
	int rank;
	char* name;
	char* platform;
	int year;
	char* genre;
	char * publisher;
	float NA_Sales;
	float EU_Sales;
	float JP_Sales;
	float Other_Sales;
	float Global_Sales;
};


int main()
{
	char filename[] = "vgsales.csv";
	char buffer[BSIZE];
	FILE *f;
	char *field;	//puntattore al primo char trovato
	int Rank;
	struct table data[NDATA];
	int counter = 0;

	f = fopen(filename,"r");
	if( f == NULL)
	{
		printf("Unable to open file '%s'\n",filename);
		exit(1);
	}
	
	/*strtok()
	Rompe la stringa in una serie di char utilizzando un separatore
	Restituisce un puntatore al primo char trovato
	Viene restituito un puntatore NULL se non sono presenti char
	
	atoi()
	converte la stringa in un int
	restituisce il numero convertito come intero
	se non può eseguire nessuna conversione, restituisce zero
	*/

	while(fgets(buffer,BSIZE,f))
	{
		field=strtok(buffer,",");
		data[counter].rank = atoi(field);
		field=strtok(NULL,",");
		data[counter].name = field;
		field=strtok(NULL,",");
		data[counter].platform = field;
		field=strtok(NULL,",");
		data[counter].year=atoi(field);
		field=strtok(NULL,",");
		data[counter].genre = field;
		field=strtok(NULL,",");
		data[counter].publisher = field;
		field=strtok(NULL,",");
		data[counter].NA_Sales = atof(field);
		field=strtok(NULL,",");
		data[counter].EU_Sales = atof(field);
		field=strtok(NULL,",");
		data[counter].JP_Sales = atof(field);
		field=strtok(NULL,",");
		data[counter].Other_Sales = atof(field);
		field=strtok(NULL,",");
		data[counter].Global_Sales = atof(field);
		if (counter % 1000==0){
				printf("RECORD--->%d, %s, %s, %d, %s, %s, %f, %f, %f, %f, %f\n",data[counter].rank,data[counter].name,data[counter].platform,data[counter].year,data[counter].genre,
				data[counter].publisher,data[counter].NA_Sales,data[counter].EU_Sales,
				data[counter].JP_Sales,data[counter].Other_Sales,data[counter].Global_Sales);

		}
		counter++;
	}

	fclose(f);
	printf("Record letti: %d\n",counter);

	return(0);
}
