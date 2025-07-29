#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val = data;
        right = NULL;
        left = NULL;
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
TreeNode* ceilsInBST(TreeNode* root, int val){
    TreeNode* temp = root;
    TreeNode* ceil = NULL;
    while(temp != NULL){
        if(temp -> val < val){
            temp = temp -> right;
        }else{
            if(ceil == NULL || temp -> val < ceil -> val){
                ceil = temp;
            }
            temp = temp -> left;
        }
    }
    return ceil;
}
TreeNode* floorInBST(TreeNode* root, int val){
    TreeNode* temp = root;
    TreeNode* floor = NULL;

    while(temp != NULL){
        if(temp -> val > val){
            temp = temp -> left;
        }else{
            if(floor == NULL || temp -> val > floor -> val){
                floor = temp;
            }
            temp = temp -> right;
        }
    }
    if(floor == NULL){
        floor = new TreeNode(-1);
        return floor;
    }

    return floor;
}
int main(){
    TreeNode* root = NULL;

    int values[] = {20 , 0 ,50 , 70, 90 ,30};

    for(int val : values){
        root = insert(root, val);
    }
    TreeNode* ceil = floorInBST(root,80);
    cout << ceil -> val << endl;
    return 0;
}