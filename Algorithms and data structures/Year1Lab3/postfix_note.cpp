
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node *prev;

    Node(int val) : value(val), prev(nullptr) {}
};

struct Stack {
    Node *tail;

    Stack() : tail(nullptr) {}

    bool is_empty() {
        return tail == nullptr;
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
            return INT_MIN;
        }
        int result = tail->value;
        tail = tail->prev;
        return result;
    }
};

int main() {
    Stack stack;
    string line;
    getline(cin, line);
    /* vector<int> answer; */
    for (int i = 0; i < line.size();i++){
        if(isdigit(line[i])){
            int num = line[i] - '0';
            stack.add(num);
        } else {
            if (line[i] == '+'){
                stack.add(stack.delete_node() + stack.delete_node());
            }
            if (line[i] == '*'){
                stack.add(stack.delete_node() * stack.delete_node());
            }
            if (line[i] == '-'){
                int one = stack.delete_node();
                int two = stack.delete_node();
                stack.add(two-one);
            }
        }
    }
    cout << stack.delete_node() << endl;
    return 0;
}