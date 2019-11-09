/* leggere e memorizzare N elementi interi positivi ed in seguito calcolarne il massimo */

#include <stdio.h>
#include <stdlib.h>

#define DIM 100

main(){
    int n;
    int vett[DIM];
    int k=0;
    int max=0;

    printf("quanti elementi vuoi: \n");
    scanf("%d", &n);

    int *p = malloc(n*sizeof(int);

    for(int i=0; i<n; i++){
        printf("Inserisci elemento [%d]: \n",i);
        scanf("%d", &vett[i]);
    }

    while(k<n){
        if(vett[i]>max){
            max= vett[i];
        }
        k++;
    }

    printf("Il masssimo dei numeri e': %d ",max);
}