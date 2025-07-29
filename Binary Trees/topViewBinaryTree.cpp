#include<iostream>
#include<queue>
#include<map>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data){
        val = data;
        right = NULL;
        left = NULL;
    }
};
vector<int> TopView(TreeNode* root){
    queue<pair<TreeNode*,int>> qp;
    map<int,int>mp;
    vector<int>ans;
    if(root != NULL){
        qp.push({root,0});
    }
    while(!qp.empty()){
        int sizeOfQueue = qp.size();
        for(int i = 0; i < sizeOfQueue; i++){
            pair<TreeNode*, int>temp = qp.front();
            qp.pop();
            TreeNode* Node = temp.first;
            int vertical = temp.second;
            if(!mp.count(vertical)){
                mp[vertical] = (Node -> val);
            }
            if(Node -> left != NULL){
                qp.push(make_pair(Node -> left,vertical - 1));
            }
            if(Node -> right != NULL){
                qp.push(make_pair(Node -> right,vertical + 1));
            }
        }
    }
    for(auto a : mp){
        ans.push_back(a.second);
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

    vector<int>ans = TopView(root);
    printVector(ans);
    return 0;
    
}