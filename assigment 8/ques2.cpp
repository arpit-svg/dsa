#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left =NULL;
        right =NULL;
    }
};
Node* buildBST(Node* root, int value) {
    if(root == NULL) {
        root = new Node(value);
        return root;
    }
    if(value > root->data) {
        root->right = buildBST(root->right, value);
    }
    else {
        root->left = buildBST(root->left, value);
    }
    return root;
}
Node* createBST(Node* root) {
    cout << "Enter the value for the node:" << endl;    
    int val;
    cin >> val;
    while(val != -1) {
        root = buildBST(root, val);
        cout << "Enter the value for the node:" << endl;
        cin >> val;
    }
    return root;
}
bool searchBST(Node* root, int target) {
    if(root == NULL) return false;
    if(root->data == target) return true;
    else if(target > root->data) return searchBST(root->right, target);
    else return searchBST(root->left, target);
}
int main(){
    Node* root=NULL;
    createBST(root);
    searchBST(root,4);


}
