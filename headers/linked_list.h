#ifndef _LINKED_LIST_H_

    #define _LINKED_LIST_H_

    namespace linkedlist {

        // Struttura del nodo della linked list
        struct Node{

            const char * label;     // Etichetta del nodo
            Node * nextnode;        // Puntatore al nodo successivo

        };

        // Struttura della linked list
        struct LinkedList{

            Node * head;        // Testa della linked list
            Node * tail;        // Coda della linked list

            unsigned int size;  // numero di elementi nella lista

        };

        // Funzione per l'inizializzazione di una LinkedList
        LinkedList * init();
        
        // Funzione per l'eliminazione della lista
        void destroy(LinkedList * list);

        // Funzione per aggiungere un noto in cima alla lista
        void addtohead(LinkedList * list , char * newlabel);

        // Funzione per visualizzare i contenuti della lista
        void showlist(LinkedList * ll);
        
        // Funzione che permette di individuare se un'etichetta è presente (o meno) in una lista
        bool labelinlist(LinkedList * list, const char * reflabel); 
        
        // Funzione che permette di aggiungere un nodo alla fine della lista
        void append(LinkedList * list, const char * newlabel);
        
        // Funzione che rimuove il noto di etichetta "ref" dalla lista; 
        // per verificare l'avvenuta esecuzione del comando è possibile utilizzare il valore booleano in uscita dalla funzione:
        // true: rimozione avvenuta con successo
        // false: rimozione non avvenuta
        bool remove(LinkedList * ll, const char * ref);

        // Inserisce un nodo successivamente al nodo di etichetta "targetlabel"; se l'etichetta non è presente aggiunge in fondo
        void insert(LinkedList * ll, const char * targetlabel, const char * newlabel);

        // Rimuove l'ultimo elemento della lista
        void pop(LinkedList * ll);
    }






#endif