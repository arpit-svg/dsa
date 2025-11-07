#include<iostream>
using namespace std;
class node{
public:

    int data;
    node* left;
    node* right;
    node(int value){
        data=value;
        left=NULL;
        right=NULL;

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

bool searchBST(Node* root, int target) {
    if(root == NULL) return false;
    if(root->data == target) return true;
    else if(target > root->data) return searchBST(root->right, target);
    else return searchBST(root->left, target);
}
Node* buildTree() {
    int val;
    cin >> val;

    if(val == -1) {
        return NULL;
    } else {
        Node* root = new Node(val);
        root->left = buildTree();
        root->right = buildTree();
        return root;
    }
}
void preOrderTraversal(node* root) {
    if(root == NULL) return;
    cout << root->data << " "; 
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ,"<<endl;
    inorder(root->right);
}
void postorder(node* root){
    if(root===NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" , "<<endl;

}
