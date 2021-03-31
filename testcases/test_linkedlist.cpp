#include "catch2.hpp"
#include "linked_list.h"

TEST_CASE("Verifica sull'inizializzazione della linked list", "[linkedlist]"){

    linkedlist::LinkedList *ll = linkedlist::init();

    REQUIRE( ll->head == NULL );
    REQUIRE( ll->tail == NULL );
    REQUIRE( ll->size == 0 );

    linkedlist::destroy(ll);  

}

TEST_CASE("Verifica della funzione \"addtohead\"", "[linkedlist]"){
    
    linkedlist::LinkedList *ll = linkedlist::init();

    linkedlist::addtohead(ll, "labelref");

    REQUIRE ( ll->head != NULL );
    REQUIRE ( ll->head == ll->tail );
    REQUIRE ( ll->size == 1 );
    REQUIRE ( ll->head->label == "labelref" );
    REQUIRE ( ll->head->nextnode == NULL);

    linkedlist::destroy(ll);  

}

TEST_CASE("Verifica della funzione \"append\"", "[linkedlist]"){
    
    linkedlist::LinkedList *ll = linkedlist::init();

    linkedlist::append(ll, "labelref");

    REQUIRE ( ll->head != NULL );
    REQUIRE ( ll->head == ll->tail );
    REQUIRE ( ll->size == 1 );
    REQUIRE ( ll->head->label == "labelref" );
    REQUIRE ( ll->head->nextnode == NULL);

    linkedlist::destroy(ll);  

}

TEST_CASE("Verifica del funzionamento dei puntatori head e tail"){

    linkedlist::LinkedList * ll = linkedlist::init();

    linkedlist::addtohead(ll, "lab1");
    linkedlist::addtohead(ll, "lab2");
    linkedlist::addtohead(ll, "lab3");
    
    REQUIRE ( ll->tail->label == "lab1" );
    REQUIRE ( ll->head->label == "lab3" );
    REQUIRE ( ll->tail->nextnode == NULL );
    REQUIRE ( ll->size == 3);

    linkedlist::destroy( ll );

}

TEST_CASE("Verifica di ricerca in una lista", "[linkedlist]"){

    linkedlist::LinkedList *ll = linkedlist::init();

    linkedlist::addtohead(ll, "lab1");
    linkedlist::addtohead(ll, "lab2");

    REQUIRE ( linkedlist::labelinlist(ll, "lab1" ) == true );
    REQUIRE ( linkedlist::labelinlist(ll, "lab2") == true );
    REQUIRE ( linkedlist::labelinlist(ll, "lab3") == false );

    linkedlist::destroy(ll);

}

TEST_CASE("Verifica del funzionamento del comando \"remove\"", "[linkedlist]") {

    linkedlist::LinkedList * ll = linkedlist::init();

    linkedlist::append( ll , "lab1");
    linkedlist::append( ll , "lab2");
    linkedlist::append( ll , "lab3");
    linkedlist::append( ll , "lab4");

    bool opres;

    // Test di rimozione di una stringa non presente
    opres = linkedlist::remove( ll , "NotInList");
    REQUIRE ( opres == false );

    // Test di rimozione dell'elemento in testa alla lista
    opres = linkedlist::remove( ll , "lab1");
    REQUIRE ( opres == true );
    REQUIRE ( ll->size == 3 );
    REQUIRE ( ll->head->label == "lab2");

    // Test di rimozione dell'elemento in coda alla lista
    opres = linkedlist::remove( ll , "lab4");
    REQUIRE ( opres == true );
    REQUIRE ( ll->size == 2 );
    REQUIRE ( ll->tail->label == "lab3");

    // Test di rimozione di un ulteriore elemento
    opres = linkedlist::remove( ll , "lab3");
    REQUIRE ( opres == true );

    // A questo punto la lista deve contenere un elemento e testa e coda devono coincidere
    REQUIRE ( ll->size == 1 );
    REQUIRE ( ll->head == ll->tail );
    REQUIRE ( ll->head->label == "lab2");

    linkedlist::destroy( ll );

}

TEST_CASE("Verifica del funzionamento del comando \"insert\"", "[linkedlist]"){

    linkedlist::LinkedList * ll = linkedlist::init();

    linkedlist::addtohead( ll, "lab1");

    // Verifica che inserisce "lab2" in coda alla lista e aggiorna correttamente i dati nella linked list
    linkedlist::insert( ll, "labnonpresente", "lab2");
    REQUIRE ( ll->size == 2 );
    REQUIRE ( ll->tail->label == "lab2" );

    // Inserisco "lab3" tra "lab1" e "lab2" e controllo che venga correttamente inserita
    linkedlist::insert( ll, "lab1", "lab3");
    REQUIRE ( ll->size == 3 );
    REQUIRE ( ll->head->label == "lab1" );
    REQUIRE ( ll->tail->label == "lab2" );
    REQUIRE ( ll->head->nextnode->label == "lab3" );

    linkedlist::destroy( ll );

}

TEST_CASE("Verifica del funzionamento del comando \"pop\"", "[linkedlist]"){

    linkedlist::LinkedList * ll = linkedlist::init();

    linkedlist::append( ll, "lab1" );
    linkedlist::append( ll, "lab2" );

    REQUIRE( ll->size == 2 );

    linkedlist::pop( ll );
    REQUIRE ( ll->size == 1 );
    REQUIRE ( ll->tail->label == "lab2" );
    
    linkedlist::pop( ll );
    REQUIRE ( ll->size == 0 );
    REQUIRE ( ll->head == NULL );
    REQUIRE ( ll->tail == NULL );
}























