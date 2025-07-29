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

    if(val < root -> val){
        root -> left = insert(root -> left, val);
    }else{
        root -> right = insert(root -> right, val);
    }
    return root;
}
pair<int,int> minAndMax(TreeNode* root){
    pair<int,int>ans;
    TreeNode* temp = root;
    //We will traverse for the min element in the BST
    while(temp != NULL){
        ans.first = temp -> val;
        temp = temp -> left;
    }
    temp = root;
    while(temp != NULL){
        ans.second = temp -> val;
        temp = temp -> right;
    }
    return ans;
}
int main(){
    TreeNode* root = NULL;

    int values[] = {20 , 0 ,50 ,30, 70, 90 ,30};

    for(int val : values){
        root = insert(root, val);
    }

    pair<int,int>ans = minAndMax(root);

    cout << "Min of the given BST is " << ans.first << endl;

    cout << "Max of the given BST is " << ans.second << endl;
    
    return 0;
}