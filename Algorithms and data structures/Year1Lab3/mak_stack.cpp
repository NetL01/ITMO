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

    int seek() {
        if (tail == nullptr) return INT_MIN;
        return tail->value;
    }

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
    int num;
    cin >> num;

    vector<int> answer;

    Stack stack;
    Stack mak_stack;
    for (int i = 0; i < num; i++) {
        string plus;
        int value;
        cin >> plus;
        if (plus == "+") {
            cin >> value;
            if (value >= mak_stack.seek()){
                mak_stack.add(value);
            }
            stack.add(value);
        }
        if (plus == "-") {
            if (stack.seek() == mak_stack.seek()) {
                mak_stack.delete_node();
            }
            stack.delete_node();
        }
        if (plus == "max"){
            answer.push_back(mak_stack.seek());
        }
    }

    for (auto ans: answer) cout << ans << "\n";

    return 0;
}