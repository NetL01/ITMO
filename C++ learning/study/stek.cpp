struct Node {
    Node * prev;
    Node * next;
    int data;
};
struct list {
    list * head;
    list * tail;

    list() {
        head = tail = nullptr;
        void listAdd(int x){
            Node * temp = new Node;
            temp = head;
            temp -> Data = x;
            temp -> prev = head -> prev;
            head = head->next;
        }
    }
};


void List

