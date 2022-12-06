#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;


int x=1;
struct Node {
    int key;
    Node *right;
    Node *left;

    Node(int key) : key(key), right(nullptr), left(nullptr) {}
};

struct BinSearchTree {
    Node *Root;

    BinSearchTree() : Root(nullptr) {};

    void Build(Node *a, int &x)
    {
        if (a== nullptr)
        {
            return;
        }
        Build(a->left,x);
        a->key=x;
        x++;
        Build(a->right,x);
    }

};


int main() {
    int n;
    cin >> n;
    int l[n+1];
    int r[n+1];
    Node *arr[n+1];
    arr[0]= nullptr;
    BinSearchTree Tree;
    for (int i=1;i<=n;i++)
    {
        cin >> l[i] >> r[i];
        arr[i]=new Node(0);
    }
    for (int i=1;i<=n;i++)
    {
        arr[i]->left=arr[l[i]];
        arr[i]->right=arr[r[i]];
    }
    Tree.Root=arr[1];
    Tree.Build(Tree.Root,x);
    for (int i=1;i<=n;i++)
    {
        cout << arr[i]->key << " ";
    }
    return 0;
}