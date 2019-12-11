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

    //malloc chiede al sistema di allocare un'area di memoria della dimensione specificata
    //restituisce l'indirizzo di area di memoria allocata
    //se l'allocazione non è possibile restituisce NULL
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

    printf("Il massimo dei numeri e': %d ",max);
}
