#include <iostream>
#include "secondary.h"

using namespace std;

int main(){
    LinkedList linkedlist;
    cout << linkedlist.to_string() << endl;

    linkedlist.add_at(0, 3.14);
    cout << linkedlist.to_string() << endl;

    linkedlist.add_at(1, 256);

    cout << linkedlist.to_string() << endl;
    
    linkedlist.add_at(1, 12);

    cerr << "Error" << endl;

    cout << linkedlist.to_string() << endl;
    
    linkedlist.add_at(56, 81);

    linkedlist.remove_value(256);
    linkedlist.remove_value(12);
    
    cout << linkedlist.to_string() << endl;
    
    LinkedList ExampleList2 = linkedlist;

    cout << ExampleList2.to_string() << endl;
    
    linkedlist.clear();

    cout << linkedlist.to_string() << endl;

}