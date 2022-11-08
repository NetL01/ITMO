struct Node {
    struct Node * next;
};

void reverse(struct Node **head){
    struct Node * current, * next, * prev = nullptr;
    current = * head;
    while (current) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    *head = prev;
}
/*
struct Node {
    struct Node * next;
};

void reverse(struct Node **head){
    struct Node * tmp, * next, * prev = nullptr;
    tmp = * head;
    while (tmp) {
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *head = prev;
}
 */