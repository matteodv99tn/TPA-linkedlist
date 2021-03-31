#include "linked_list.h"
#include <iostream>

using namespace linkedlist;       

// Funzione per l'inizializzazione di una LinkedList
LinkedList * linkedlist::init(){

    // Creo la nuova struct
    LinkedList * tbr = new LinkedList;
    
    // Testa che non punta a niente e dimensione nulla
    tbr->head = NULL;
    tbr->tail = NULL;
    tbr->size = 0;

    // Restituisco l'oggetto
    return tbr;

}

// Funzione ricorsiva per l'eliminazione dei nodi
void removeNodes(Node * current){

    // Se il nodo non punta a nulla, allora si era raggiunta la fine della lista:
    // questa è la condizione di fine della ricorsione
    if (current == NULL) return;

    removeNodes(current->nextnode);
    
    delete current->nextnode;

    return;
}

// Funzione per la distruzione della lista
void linkedlist::destroy(LinkedList * list){

    // Rimuovo i nodi della lista in maniera ricorsiva
    removeNodes( list->head );

    // Elimino le proprietà della lista e la lista stessa
    delete list->head;
    delete list;   

} 

// Funzione per aggiungere un noto in cima alla lista
void linkedlist::addtohead(LinkedList * list , char * newlabel){
    
    // Definisco il nuovo nodo
    Node * newnode = new Node;

    // Assegno l'etichetta al nodo e dico che il suo nodo successivo dovrà coincidere con la testa della lista attuale
    newnode->label = newlabel;
    newnode->nextnode = list->head;
    
    // Se la lista ha dimensione nulla, allora il nodo in testa è anche quello in coda
    if( list->size == 0 ) list->tail = newnode;

    // Incremento la dimensione della lista e impongo che il nuovo nodo coincida con la testa della lista
    list->size += 1;
    list->head = newnode;

}

// Funzione per visualizzare la lista
void linkedlist::showlist(LinkedList * list){

    Node * current = list->head;

    std::cout << "Contenuti nella linked list: " << list->size << std::endl;

    while(current != NULL){

        std::cout << " > " << current->label << std::endl;
        current = current->nextnode;

    }

}

// Funzione che permette di individuare se un'etichetta è presente (o meno) in una lista
bool linkedlist::labelinlist(LinkedList * list, const char * reflabel){

    // Cast in stringa dell'array di caratteri in ingresso alla funzione
    std::string refstr = std::string(reflabel);
    // Definizione del nodo corrente
    Node * current = list->head;

    while(current != NULL){ // Finchè il nodo non punta a niente:

        // Cast della label del nodo in stringa
        std::string curstr = std::string( current->label );

        // Verifico l'uguaglianza tra etichetta del nodo e quella di riferimento
        // Se essa è verifica allora restituisco valore affermativo (e termino di fatto la ricerca)
        if(curstr == refstr) return true;
        
        // Se non si ha corrispondenza, allora si passa ad analizzare il nodo successivo
        current = current->nextnode;
    
    }

    // Se non ho trovato alcuna corrispondenza nella lista
    // allora significa che l'etichetta di riferimento non è presente nella lista
    return false;
}

// Funzione che permette di aggiungere un nodo alla fine della lista
void linkedlist::append(LinkedList * list, const char * newlabel){

    // Genero l'istanza del nuovo nodo e gli assegno l'etichetta
    Node * newnode = new Node;
    newnode->label = newlabel;

    if(list->size == 0){ // Se la lista ha dimensione nulla

        // Testa e coda della lista devono coincidere
        list->head = newnode;
        list->tail = newnode;

    } else { // Se invece la lista conteneva già degli altri elementi

        // Pongo il nuovo nodo alla coda della lista utilizzando l'apposita informazione della linkedlist
        // Aggiorno di conseguenza la coda
        list->tail->nextnode = newnode;
        list->tail = newnode;

    }
    
    // Incremento la dimensione della lista
    list->size += 1;

}

// Funzione che rimuove il noto di etichetta "ref" dalla lista; 
// per verificare l'avvenuta esecuzione del comando è possibile utilizzare il valore booleano in uscita dalla funzione:
// true: rimozione avvenuta con successo
// false: rimozione non avvenuta
bool linkedlist::remove(LinkedList * ll, const char * ref){
    
    // Se la lista non contiene elementi, termina immediatamente la funzione con esito negativo
    if( ll->size == 0 ) return false;

    // Definizione del nodo corrente
    Node * currentnode = ll->head;

    // Controllo che il primo elemento non sia quello da eliminare
    if( std::string(currentnode->label) == std::string(ref) ){
        
        // In caso affermativo campio la testa, elimino il nodo, decremento la dimensione della lista e restituisco esito positivo
        ll->head = currentnode->nextnode;
        ll->size -= 1;
        delete currentnode;
        return true;

    }

    // Per ogni nodo nella lista
    while(currentnode->nextnode != NULL){
        
        // Controllo se l'etichetta del nodo successivo coincide con quella di riferimento
        if( std::string(currentnode->nextnode->label) == std::string(ref) ){

            // In caso affermativo salvo il riferimento al nodo che dovrà essre eliminato dalla lista
            Node * temp = currentnode->nextnode->nextnode;

            // Se il nodo da eliminare è quello in coda, aggiorno il puntatore della coda della lista al nodo corrente
            if( currentnode->nextnode == ll->tail ) 
                ll->tail = currentnode;

            // Elimino il nodo "bersaglio" e imposto il nodo successivo a quello attuale al valore puntato da quello eliminato.
            delete currentnode->nextnode;
            currentnode->nextnode = temp;

            // Decremento la dimensione della lista:
            ll->size -= 1;

            // Ritorno esito positivo di avvenuta cancellazione
            return true;

        }

        // Passo ad analizzare il nodo successivo
        currentnode = currentnode->nextnode;

    }


    // Se si è arrivati a questo punto significa che l'etichetta non era presente nella lista
    // e dunque ritorno un esito negativo alla funzione
    return false;

}

// Inserisce un nodo successivamente al nodo di etichetta "targetlabel"; se l'etichetta non è presente aggiunge in fondo
void linkedlist::insert(LinkedList * ll, const char * targetlabel, const char * newlabel){

    // Creo l'istanza del nuovo nodo
    Node * newnode = new Node;
    newnode->label = newlabel;

    // Creo il nodo corrente per la ricerca del nodo di riferimento
    Node * currentnode = ll->head;

    // Incremento a priori la lunghezza della linked list in quanto ho la garanzia di aggiungere un nodo
    ll->size += 1;

    // Ciclo sui nodi della struttura
    while ( currentnode != NULL ){

        // Se si ha la corrispondenza tra etichetta di riferimento e del nodo corrente
        if ( std::string(currentnode->label) == std::string(targetlabel) ) {
            
            // Inserisco opportunamente il nuovo nodo
            newnode->nextnode = currentnode->nextnode;
            currentnode->nextnode = newnode;

            // Se il nuovo nodo si trova a puntare ad un nodo NULL, allora si trova in coda: aggiorno la coda della lista
            if(newnode->nextnode == NULL) ll->tail == newnode;

            // Termino l'esecuzione della funzione
            return;

        }

        // Passo ad analizzare il nodo successivo
        currentnode = currentnode->nextnode;

    }

    // Arrivati a questo punto non esisteva il nodo cercato nella lista, quindi aggiungo alla fine e aggiorno il dato nella linkedlist
    ll->tail->nextnode = newnode;
    newnode->nextnode = NULL;
    ll->tail = newnode;

}
 
// Rimuove l'ultimo elemento della lista
void linkedlist::pop(LinkedList * ll){

    // Non eseguire niente se la lista è vuota
    if( ll->size == 0) return;

    // Controllo il caso in cui la lista abbia solo un elemento (l'unico da rimuovere)
    if( ll->size == 1) {

        // Cancello l'unico nodo, pongo NULL testa e coda, azzero la dimensione e termino la funzione
        delete ll->head;
        ll->head = NULL;
        ll->tail = NULL;
        ll->size = 0;
        return;
    }

    // Creo l'istanza del nuovo nodo
    Node * currentnode = ll->head;

    // Scorro fino al penultimo elemento della lista
    while( currentnode->nextnode != NULL) currentnode = currentnode->nextnode;
    
    // Elimino l'ultimo elemento e aggiorno la coda della lista
    delete currentnode->nextnode;
    ll->tail = currentnode;

    // Decremento la dimensione della lista
    ll->size -= 1;

}


