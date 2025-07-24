#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this -> data = data;
        right = NULL;
        left = NULL;
    }
};
int checkHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(checkHeight(root -> left), checkHeight(root -> right));
}
int DiameterHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = checkHeight(root -> left);
    int rightHeight = checkHeight(root -> right);
    return max({DiameterHeight(root -> left), DiameterHeight(root -> right),leftHeight + rightHeight});
}

int maxDiameter = 0;

int heightAndUpdateDiameter(Node* root) {
    if (root == NULL) return 0;

    int leftHeight = heightAndUpdateDiameter(root->left);
    int rightHeight = heightAndUpdateDiameter(root->right);

    // Update the maximum diameter seen so far
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);

    // Return the height of the current subtree
    return 1 + max(leftHeight, rightHeight);
}
int main(){
Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left  -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(8);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    root -> right -> right -> left = new Node(9);
    root -> right -> right -> right = new Node(10);
    cout << DiameterHeight(root);
}