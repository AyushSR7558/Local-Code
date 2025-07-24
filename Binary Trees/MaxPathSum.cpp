#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
int MaxPathSum(Node* root,int& maxi){
    if(root == NULL){
        return 0;
    }
    int leftSum = MaxPathSum(root -> left,maxi);
    int rightSum = MaxPathSum(root -> right,maxi);
    if(leftSum < 0)leftSum = 0;
    if(rightSum < 0)rightSum = 0;
    maxi = max(maxi,root -> data + leftSum + rightSum);
    return root -> data + max(leftSum, rightSum);
}
int main(){
       Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> left -> left = new Node(5);
    root -> right -> right = new Node(6);
    int maxi = 0;
    MaxPathSum(root,maxi);
    cout << "The maximum Depth for the given tree wil be equal to " << maxi;
    return 0;
}