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

// esercizio 2
void stampaLista ( ListaDiElementi l ){
    if (l == NULL ) printf (" \n" );
    else{
        printf ( "%d -> " ,l - > valore );
        stampaLista (l -> next );
    }
}


// esercizio 3
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


// esercizio 4
void deallocaLista(ListaDiElementi 1){
    if(l != NULL){
        deallocaLista(l -> next);
        free (l);
        /*Il prototipo della funzione free in C è: void free(void *); 
        Quindi la funzione ha come argomento il puntatore all'inizio dell'area di memoria precedentemente allocata, 
        che adesso si vuole rendere disponibile perchè non più utilizzata. La funzione inoltre non ha alcun valore di ritorno*/
    }
}

// esercizio 5
void ordinaLista(ListaDiElementi l) { 
    ListaDiElementi l1,tmp,prec_tmp;

    if ((l==NULL)||(l->next==NULL)) return l;
    else l1 = ordinaLista(l->next); 
    // l1 e’ di sicuro non vuota

    tmp = l1; 
    prec_tmp = l; 

    //l’ordine delle condizioni in && e’ importante!
    while ((tmp!=NULL)&&(tmp->info <l->info)) { 
        prec_tmp=tmp; 
        tmp=tmp->next; 
    }

    // devo piazzare il primo elemento di l dentro a l1 
    if (tmp==NULL){ //inserimento in coda  
        l->next=NULL; 
        prec_tmp ->next=l;
        return l1;
    }else{
        if (tmp==l1){ //inserimento in testa 
            l->next=l1; 
            return l; 
        }else{ //inserimento in mezzo 
            l->next = tmp; 
            prec_tmp ->next = l; 
            return l1; 
        }
    }
} 

// Esercizio 6
void merge ( ListaDiElementi l1 , ListaDiElementi l2 ){
    ListaDiElementi risultato = NULL ;
    ListaDiElementi new = NULL ;
    int primavolta = 1;
    /* scorre le due liste simultaneamente */
    while (( l1 != NULL )&&( l2 != NULL )) {
        if ( primavolta ){
            new = ( ListaDiElementi ) malloc ( sizeof ( ElementoDiLista ));
            risultato = new ;
            primavolta =0;
        }
        else{
            new -> next = ( ListaDiElementi ) malloc ( sizeof ( ElementoDiLista ));
            new = new -> next ;
        }

        if (l1 -> info <l2 -> info ){ 
            new - > info =l1 - > info ; 
            l1 =l1 - > next ; 
        }
        else{ 
            new - > info =l2 - > info ; 
            l2 =l2 - > next ; 
        }
    }

    /* uno (e solo uno) dei seguenti due cicli viene eseguito */
    while ( l1 != NULL ){
        new -> next = ( ListaDiElementi ) malloc ( sizeof ( ElementoDiLista ));
        new = new -> next ;
        new -> info = l1 -> info ;
        l1 = l1 - > next ;
    }

    while ( l2 != NULL ){
        new -> next = ( ListaDiElementi ) malloc ( sizeof ( ElementoDiLista ));
        new = new -> next ;
        new -> info = l2 -> info ;
        l2 = l2 - > next ;
    }

    /* mette NULL in fondo alla lista */
    if ( new != NULL ) new -> next = NULL ;
    return risultato ;
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

        //chiamate alle funzioni
        stampaLista(ListaDiElementi);
        deallocaLista(ListaDiElementi);
        ordinaLista(ListaDiElementi);
        merge(ListaDiElementi, ListaDiElementi);
        
        return 0;

}

