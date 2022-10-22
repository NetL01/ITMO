#include <iostream>

/*
*
*
* Односвязный список
*
*
*/
/* Узёл */

struct Node {
    int data;
    /* Указатель на след. узел */
    Node * pointer;

    Node ( int key ) {
        data = key;
        pointer = nullptr;
    }
};
struct list {
    /* указатель на узел головы */
    Node * Head;

    /* Указатель на узел хвоста */
    Node * Tail;

    list() {
        Head = nullptr;
        Tail = nullptr;
    }};

/* добавление в конец */
void add( int val){
    Node * n = new Node(val);
    n->pointer = nullptr;
    if (Head == nullptr){
        Head = n;
        Tail = n;

    }
}
/* Добавление по позиции */
void addToPosition(int val, int position){
    Node * curr = Head;
    for( int i = 0; i < position; i++){
        if (curr->pointer != nullptr){
            curr = curr->pointer
        }
        else{
            Node * n = new Node(val);

        }
    }
}

int search(int v){
    int pos = -1;
    for (Node * n= Head); n != nullptr; n = n->p){
    if (n->data==v){
        pos = i;
        break
    }
    return pos
}
}

void delete_pos(pos){
    Node * next = ls.pos.pointer.pointer;
    delete ls.pos.pointer;
    ls.pos.pointer = next;
}

list ls;

int main(){
    add(__3__);
    ls.add(7);
    ls.add(2);
    ls.add(123);
    ls.delete_pos(search(3));
}