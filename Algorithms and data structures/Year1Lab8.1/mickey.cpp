using namespace std;
#include <vector>
#include <iostream>




struct Node {
    int data;
    char symbol;
    Node *parent;
    Node *left;
    Node *right;


    Node(int Data, char Symbol) : data(Data), symbol(Symbol), parent(nullptr), left(nullptr), right(nullptr) {}
};

Node *Root_of_data;
Node *Root_of_symbol;

Node *NewRoot(int data, char symbol) {
    Node *p = new Node(data, symbol);
    return p;
}

void Rotate(Node *p, Node *&Root) {
    if (p == Root) return;
    Node *father = p->parent;
    if (father->left == p) {
        if (father->parent != nullptr) {
            Node *grandfather = father->parent;
            if (p->left != nullptr) {
                Node *p_pointer = p->left;
                if (grandfather->left == father) grandfather->left = p;
                else grandfather->right = p;
                p->left = father;
                father->left = p_pointer;
                p_pointer->parent = father;
                p->parent = grandfather;
                father->parent = p;
            } else {
                if (grandfather->left == father) grandfather->left = p;
                else grandfather->right = p;
                p->left = father;
                father->left = nullptr;
                p->parent = grandfather;
                father->parent = p;
            }
        }
        if (father == Root) {
            if (p->left != nullptr) {
                Node *p_pointer = p->left;
                Root = p;
                Root->left = father;
                father->left = p_pointer;
                p_pointer->parent = father;
                father->parent = Root;
                Root->parent = nullptr;
            } else {
                Root = p;
                Root->left = father;
                father->left = nullptr;
                Root->parent = nullptr;
                father->parent = Root;
            }
        }
    }
    if (father->right == p) {
        if (father->parent != nullptr) {
            Node *grandfather = father->parent;
            if (p->right != nullptr) {
                Node *p_pointer = p->right;
                if (grandfather->right == father) grandfather->right = p;
                else grandfather->left = p;
                p->right = father;
                father->right = p_pointer;
                p_pointer->parent = father;
                p->parent = grandfather;
                father->parent = p;
            } else {
                if (grandfather->right == father) grandfather->right = p;
                else grandfather->left = p;
                p->right = father;
                father->right = nullptr;
                p->parent = grandfather;
                father->parent = p;
            }
        }
        if (father == Root) {
            if (p->right != nullptr) {
                Node *p_pointer = p->right;
                Root = p;
                Root->right = father;
                father->right = p_pointer;
                p_pointer->parent = father;
                Root->parent = nullptr;
                father->parent = Root;
            } else {
                Root = p;
                Root->right = father;
                father->right = nullptr;
                Root->parent = nullptr;
                father->parent = Root;
            }
        }
    }
}

void LRV_function(std::vector<Node *> &v, Node *Root) {
    if (Root != nullptr) {
        LRV_function(v, Root->left);
        LRV_function(v, Root->right);
        v.push_back(Root);
    }
}

int main() {
    int N1, Q1;
    cin >> N1 >> Q1;

    int array_of_numbers[N1];
    for (int i = 0; i < N1; i++) {
        cin >> array_of_numbers[i];
    }

    int changing_of_numbers[Q1];
    for (int i = 0; i < Q1; i++) {
        cin >> changing_of_numbers[i];
    }

    int N2, Q2;
    cin >> N2 >> Q2;

    char array_of_symbols[N2];
    for (int i = 0; i < N2; i++) {
        cin >> array_of_symbols[i];
    }

    int changing_of_symbols[Q2];
    for (int i = 0; i < Q2; i++) {
        cin >> changing_of_symbols[i];
    }
    Node *Tree_of_data[N1];
    for (int i = 0; i < N1; i++) {
        Tree_of_data[i] = NewRoot(array_of_numbers[i], '0');
    }
    for (int i = 0; i <= N1 / 2 - 1; i++) {
        if (i * 2 + 1 < N1) {
            Tree_of_data[i]->left = Tree_of_data[2 * i + 1];
            Tree_of_data[2 * i + 1]->parent = Tree_of_data[i];
        }
        if (i * 2 + 2 < N1) {
            Tree_of_data[i]->right = Tree_of_data[2 * i + 2];
            Tree_of_data[2 * i + 2]->parent = Tree_of_data[i];
        }
    }
    Root_of_data = Tree_of_data[0];

    Node *Tree_of_symbol[N2];
    for (int i = 0; i < N2; i++) {
        Tree_of_symbol[i] = NewRoot(0, array_of_symbols[i]);
    }
    for (int i = 0; i <= N2 / 2 - 1; i++) {
        if (i * 2 + 1 < N1) {
            Tree_of_symbol[i]->left = Tree_of_symbol[2 * i + 1];
            Tree_of_symbol[2 * i + 1]->parent = Tree_of_symbol[i];
        }
        if (i * 2 + 2 < N1) {
            Tree_of_symbol[i]->right = Tree_of_symbol[2 * i + 2];
            Tree_of_symbol[2 * i + 2]->parent = Tree_of_symbol[i];
        }
    }
    Root_of_symbol = Tree_of_symbol[0];

    for (int i = 0; i < Q1; i++) {
        Rotate(Tree_of_data[changing_of_numbers[i] - 1], Root_of_data);
    }

    for (int i = 0; i < Q2; i++) {
        Rotate(Tree_of_symbol[changing_of_symbols[i] - 1], Root_of_symbol);
    }

    std::vector<Node *> data;
    std::vector<Node *> symbol;

    std::vector<char> result_vector;

    LRV_function(data, Root_of_data);
    LRV_function(symbol, Root_of_symbol);

    for (int i = 0; i < N1; i++) {
        char symb = symbol[i]->symbol;
        for (int j = 0; j < data[i]->data; j++) {
            result_vector.push_back(symb);
        }
    }

    for (auto symb: result_vector) cout << symb;

    return 0;
}