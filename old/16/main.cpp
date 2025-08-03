#include <iostream>
#include <string>
#include "secondary.h"

using namespace std;

void find_exeption(Tree* tree, int value){
    try{
        cout << tree->find_next(value) << endl;
    }
    catch(invalid_argument e){
        cout << e.what() << endl;
    }
}

int main(){
    Tree tree;
    tree.add(20);
    tree.add(45);
    tree.add(12);
    tree.add(5);
    tree.add(13);
    tree.add(36);
    tree.add(26);
    tree.add(1);
    tree.add(123);
    
    cout << tree.to_string() << endl;

    find_exeption(&tree, 123);
    find_exeption(&tree, 36);
    find_exeption(&tree, 7);
    find_exeption(&tree, 1);
    find_exeption(&tree, -3);

    for(int v: tree){
        cout << v << " ";
    }
    cout << endl;
    
}