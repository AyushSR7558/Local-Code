#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* right;
    Node* left;

    Node(int data){
        val = data;
        right = NULL;
        left = NULL;
    }
};
int heightNode(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(heightNode(root -> left), heightNode(root -> right));
}
bool bruteCheckForBalanceBinaryTree(Node* root){
    if(root == NULL){
        return true;
    }
    int leftHeight = heightNode(root -> left), rightHeight = heightNode(root -> right);

    if(abs(leftHeight - rightHeight) > 1)return false;

    bool leftCheck = bruteCheckForBalanceBinaryTree(root -> left);
    bool rightCheck = bruteCheckForBalanceBinaryTree(root -> right);
    return leftCheck && rightCheck;
}
int heightOptimizedNode(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = heightOptimizedNode(root -> left);
    int rightHeight = heightOptimizedNode(root -> right);

    if(leftHeight < 0 || rightHeight < 0)return -1;
    
    if(abs(leftHeight - rightHeight) > 1)return -1;
    
    return 1 + max(leftHeight, rightHeight);
}
bool OptimizedCheckForBalanceBinaryTree(Node* root){
    return (heightOptimizedNode(root) != -1);
}
int main(){
Node* root = new Node(10);
root->left = new Node(20);
root->right = new Node(30);

root->left->left = new Node(40);
root->left->left->left = new Node(50);
root->left->left->left->left = new Node(60);

    cout << OptimizedCheckForBalanceBinaryTree(root);
}