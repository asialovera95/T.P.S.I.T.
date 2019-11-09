/*crea una lista e la stampa*/
#include <stdio.h>
#include <stdlib.h>
struct El{      /*struttura fatta da due campi, poi c'è un puntatore. struttura autorefernziale( si riferisce a se stessa)*/
    int valore;
    struct El* next;
};

typedef struct El ElementoDiLista;
typedef ElementoDiLista* ListaDiElementi;

//--------------------------------------------
/*stampa una lista, funzione ricorsiva*/
/*
void stampaLista(ListaDiElementi l) {
  if(l==NULL)
    return;

  printf("%d ", l->val);
  stampaLista(l->next);
}
*/
//--------------------------------------------

/* esercizio 2 */
void stampaLista ( ListaDiElementi l ){
    if (l == NULL ) printf (" //\ n" );
    else{
        printf ( "%d -> " ,l - > valore );
        stampaLista (l -> next );
    }
}

/* esercizio 3*/

int lunghezzaListaIterativa ( ListaDiElementi l){
    int lung = 0;
    while (l != NULL ){
        l=l -> next ;
        lung ++;
    }
    return lung ;
}

int lunghezzaListaRicorsiva ( ListaDiElementi l){
    if (l == NULL ) return 0;
    else return lunghezzaListaRicorsiva (l -> next )+1;
}


int main(){
    int n;
    struct El* lista; //puntatore alla primo elemento della lista. per andare al puntatore successivo bisogna andare a vedere cosa c'è nel campo next
    struct El* l;
    lista=NULL; /* COMMENTO: (la lista è vuota) inizializzo il puntatore a NULL */

    do{
        printf("Inserisci un naturale o -1 per terminare\n"); //lista numeri naturali, per bloccare il do while metto un numero negativo
        scanf("%d",&n);
            if (n>=0){
                if (lista==NULL) /* COMMENTO: verifico se il puntatore lista assume il valore NULL */
                {
                    /* COMMENTO: assegno direttamente alla lista la dimensione dell'oggetto (struttura El) richiesta dalla malloc e restituisce un puntatore all'oggetto
                    -- alloco in memoria per una struttura */
                    lista = (struct El*) malloc(sizeof(struct El));
                    l = lista;
                }
                else /* COMMENTO: se la lista ha già dei contenuti. E' diverso da NULL*/
                {
                    /*assegno al puntatore l dell'elemento attuale un puntatore che punta all'elemento successivo*/
                    l->next = (struct El*) malloc(sizeof(struct El)); //creo/alloco uno spazio successivo dopo al primo valore (***)
                    l = l->next; // riga 44
                }
                l->valore = n; /* assegno n al campo valore dell'elemento corrente*/
                l->next = NULL; /* assegno al campo next dell'elemento corrente il valore NULL */
            }
    } while (n>=0);  /* I (il primo giro) del do while |5- NULL|  (***)
                        II (al secondo giro) |8- . |
                                                 |
                                                 ----> |5- NULL|*/

        l=lista; /* assegno alla variabile di appoggio l il puntatire al primo elemento della lista */
        printf("numeri inseriti: ");
        while (l!=NULL){
            printf("%d - %p \n",l->valore, l->next);
            l=l->next; /* il puntatore corrente è assegnato al puntatore all'elemento successivo */
        }
        printf("\n");
        return 0;
}
