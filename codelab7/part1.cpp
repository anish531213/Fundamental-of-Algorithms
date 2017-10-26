#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

struct Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void inorder(Node* root){
    // base case
    if (!root)
        return;

    inorder(root->left);
    cout  << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    // base case
    if (!root)
        return;
    
    cout  << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    // base case
    if (!root)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout  << root->data << " ";
}

void BFS_tree(Node* root){
    queue<Node*> myQueue;
    Node* temp;
    myQueue.push(root);
    while (!myQueue.empty()) {
        temp = myQueue.front();
        myQueue.pop();
        cout << temp->data << " ";
        if (temp->left)
            myQueue.push(temp->left);
        if (temp->right)
            myQueue.push(temp->right);
    }

}

void dfs(Node* n, string s) {
    if (!n->left and !n->right) {
        cout << s << " " << n->data << endl;
        return;
    }
    if (n->left) {
        dfs(n->left, s+" "+to_string(n->data));
    }
    if (n->right) {
        dfs(n->right, s+" "+to_string(n->data));
    }
}

void sumDfs(Node* n, string s, int k) {
    if (!n->left and !n->right) {
        if (k == n->data) 
            cout << s << " " << n->data << endl;
        return;
    }
    if (n->left) {
        sumDfs(n->left, s+" "+to_string(n->data), k-(n->data));
    }
    if (n->right) {
        sumDfs(n->right, s+" "+to_string(n->data), k-(n->data));
    }
}


void all_root_to_leaves(Node* root){
    dfs(root, "");
}
//This is extra credit. Only turn it in after completing other questions
void sumPath(Node* root, int k){
    sumDfs(root, "", k);
}

int main(){
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
// The calls for the above incomplete functions commented out purposefully. Please uncomment after you have completed all the above methods.
    cout << "****  Indorer DFS of the Tree  ****" << endl;
    inorder(root);
    cout << endl;

    cout << "\n****  Preorder DFS of the Tree  ****" << endl;
    preorder(root);
    cout << endl;

    cout << "\n****  Postorder DFS of the Tree  ****" << endl;
    postorder(root);
    cout << endl;

    cout << "\n****  BFS of the Tree  ****" << endl;
    BFS_tree(root);
    cout << endl;
    
    cout << "\n****  All Paths from Root to leaf  ****" << endl;
    all_root_to_leaves(root);
    cout << endl;
    
    cout << "****  Paths whose sum is equal to k  ****" << endl;
    sumPath(root, 11);
    cout << endl;
}


