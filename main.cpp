#include <iostream>
#include "linked_list.h"

using namespace std;

int main(){

    cout << "INIZIO DEL PROGRAMMA" << endl << endl;

    linkedlist::LinkedList * ll;
    ll = linkedlist::init();
    
    linkedlist::addtohead(ll, "lab1");
    linkedlist::insert( ll, "labnonpresente", "lab2");
    linkedlist::insert( ll, "lab1", "lab3");

    linkedlist::showlist(ll);



    linkedlist::destroy(ll);

    cout << "PROGRAMMA FINITO" << endl;

    return EXIT_SUCCESS;
}