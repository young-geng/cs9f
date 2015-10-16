#include <iostream>
#include "dll.h"

using namespace std;

int main () {
    const int N = 8;
    const int K = 2;
    DLLnode *list = new DLLnode(N);
    for (int j=N - 1; j>0; j--) {
        list = list->Insert(new DLLnode (j));
    }
    list->Print ();
    while (!list->LengthIs1 ()) {
        for (int j=0; j<K; j++) {
           list = list->Next ();
        }
        DLLnode *t = list;
        list = list->Delete();
        delete t;
    }
    cout << "Only one person remains: ";
    list->Print ();
    return 0;
}

