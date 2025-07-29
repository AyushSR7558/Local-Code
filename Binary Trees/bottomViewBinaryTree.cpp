#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
vector<int>bottomView(TreeNode* root){
    if(root == NULL){
        return {};
    }
    queue<pair<TreeNode*,int>> q; // This will store the Node with the corresponding vetical level
    map<int,int> mp; // This will store the vertical level with its corresponding val
    vector<int> ans; // This will store the final ans to be returned

    q.push(make_pair(root,0));
    
    while(!q.empty()){
        TreeNode* Node = q.front().first;
        int vertical = q.front().second;
        q.pop();
        if(Node -> left != NULL){
            q.push(make_pair(Node -> left, vertical - 1));
        }
        if(Node -> right != NULL){
            q.push(make_pair(Node -> right, vertical + 1));
        }
        mp[vertical] = Node -> val;
    }

    for(auto value : mp){
        ans.push_back(value.second);
    }
    return ans;
}
void printVector(vector<int> arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    vector<int>ans = bottomView(root);
    printVector(ans);
    
    delete root -> right -> right;
    delete root -> left -> right;
    delete root -> right;
    delete root -> left;
    delete root;

    return 0;
    
}