#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node *prev = nullptr;

    Node(int val) : value(val) {}
};

struct Stack {
    Node *tail = nullptr;



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
    int num;
    cin >> num;

    vector<int> answer;

    Stack stack;
    for (int i = 0; i < num; i++) {
        char plus;
        int value;
        cin >> plus;
        if (plus == '+') {
            cin >> value;
            stack.add(value);
        }
        if (plus == '-') {
            answer.push_back(stack.delete_node());
        }
    }

    for (auto ans: answer) cout << ans << "\n";

    return 0;
}