#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char value;
    Node *prev;

    Node(int val) : value(val), prev(nullptr) {}
};

struct Stack {
    Node *tail;

    Stack() : tail(nullptr) {}

    bool is_empty() {
        return tail == nullptr;
    }
    int seek() {
        if (tail == nullptr) return INT_MIN;
        return tail->value;
    }
    /*
    int seek() {
        if (tail == nullptr) return INT_MIN;
        return tail->value;
    }
    */

    void add(int value) {
        Node *pos = new Node(value);
        if (is_empty()) {
            tail = pos;
            return;
        }
        pos->prev = tail;
        tail = pos;
    }

    int delete_node() {
        if (is_empty()) {
            cout << "node is empty" << endl;
            return INT_MIN;
        }
        int result = tail->value;
        tail = tail->prev;
        return result;
    }
};

int main() {
    string line;
    Stack stack;
    while (getline(cin, line)){
        for (int i = 0; i < line.size(); i++){
            /* cout << "i = " << i << endl; */
            if (line[i] == '('){
                stack.add('(');
            }
            if (line[i] == ')'){
                if (stack.seek() == '('){
                    stack.delete_node();
                }
                else {
                    stack.add(')');
                }
            }
            if (line[i] == '['){
                stack.add('[');
            }
            if (line[i] == ']'){
                if (stack.seek() == '['){
                    stack.delete_node();
                }
                else {
                    stack.add(']');
                }
            }
        }
        if (stack.is_empty()){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        /* очищение */
        while (!stack.is_empty()){
            stack.delete_node();
        }

    }
    return 0;
}