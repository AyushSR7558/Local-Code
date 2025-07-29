#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};
TreeNode* insert(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }
    if(root -> val > val){
        root -> left = insert(root -> left,val);
    }else{
        root -> right = insert(root -> right, val);
    }
}
int main(){

}