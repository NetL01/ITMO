#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int val) : value(val), next(nullptr) {}
};

struct Stack {
    Node *tail;
    Node *head;

    Stack() : head(nullptr), tail(nullptr) {}

    bool is_empty() {
        return head == nullptr;
    }

    void add(int value) {
        Node *pos = new Node(value);
        if (is_empty()) {
            tail = pos;
            head = pos;
            return;
        }
        tail->next = pos;
        tail = pos;
    }

    int delete_node() {
        if (is_empty()) {
            return 12314124124;
        }
        int result = head->value;
        head = head->next;
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