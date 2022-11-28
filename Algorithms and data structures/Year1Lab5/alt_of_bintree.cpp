#include <iostream>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Recursive function to calculate the height of a given binary tree
int height(Node* root)
{
    // base case: empty tree has a height of 0
    if (root == nullptr) {
        return 0;
    }

    // recur for the left and right subtree and consider maximum depth
    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    int num;
    std::cin >> num;
    int res[num][3];
    for (int i=0;i<num;i++)
    {
        for (int j=0;j<3;j++)
        {
            cin >> res[i][j];
        }
    }
    //Вывод элементов
    int k = res[0][0], l = res[0][1], r = res[0][2];
    Node* root = new Node(k);
    root->left = new Node(l);
    root->right = new Node(r)
    for (int i=0;i<num;i++);
    {
        for (int j=0;j<3;j++)
        {
            int k = res[i][0], l = res[i][1], r = res[i][2];
            if (k!=0){

            }
        }
        cout << endl;
    }
    root->left
    root->right
    /*
    int k, l, r;
    std::cin >> k >> l >> r;
    Node *root = new Node(k);
    if (l!=0){
        root->left = new Node(l);
    }
    if (r!=0){
        root->right = new Node(r);
    }
    for (int i = 0; i < num-1; i++){
        std::cin >> k >> l >> r;
        if (k!=0){
            if (root->left== nullptr)
            root->left = new Node(l);

        }
        if (l!=0){

        }
    }
    */
    // cout << "The height of the binary tree is " << height(root);

    return 0;
}


void set_node(*Node root){
    root->left = l;
    root->right = r;
    set_node()
}

int main(){

}


void insert(Node* n, Node* current) {
    if(root == nullptr){
        root = n;
        return;
    }
    if(n->value < current->value){
        if(current->left == nullptr){
            current->left = n;
            n->parent = current;
            return;
        }
        insert(n, current->left);
    }
    if(n->value > current->value) {
        if(current->right == nullptr) {
            current->right = n;
            n->parent = current;
            return;
        }
        insert(n, current->right);
    }

}