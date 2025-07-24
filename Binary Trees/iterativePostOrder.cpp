#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}
void inOrder(Node* root){
    if(root == NULL){
        return ;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}
void postOrder(Node* root){
    if(root == NULL){
        return ;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}
vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>>ans;
    if(root == NULL)return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            if(temp -> left != NULL){
                q.push(temp -> left);
            }
            if(temp -> right != NULL){
                q.push(temp -> right);
            }
            level.push_back(temp -> data);
            q.pop();
        }
        ans.push_back(level);
    }
    return ans;
}
void BFS(Node* root){
    vector<vector<int>>BFS = levelOrder(root);
    for(int i = 0; i < BFS.size(); i++){
        for(int j = 0; j < BFS[i].size(); j++){
            cout << BFS[i][j] << " ";
        }
    }
    cout << endl;
}
void iterativePreorder(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        cout << temp -> data << " ";
        if(temp -> right){
            st.push(temp -> right);
        }
        if(temp -> left){
            st.push(temp -> left);
        }
    }
}
void iterativeInOrder(Node* root){
    stack<Node*> st;
    Node* temp = root;
    if(root == NULL) return;
    while(temp != NULL || !st.empty()){
        while(temp != NULL){
            st.push(temp);
            temp = temp -> left;
        }
        temp = st.top();
        st.pop();
        cout << temp -> data << " ";
        temp = temp -> right;
    }
}
void iterativePostOrder(Node* root){
    stack<Node*>st1,st2;
    st1.push(root);
    while(!st1.empty()){
        Node* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp -> left != NULL){
            st1.push(temp -> left);
        }
        if(temp -> right != NULL){
            st1.push(temp -> right);
        }
    }
    while(!st2.empty()){
        cout << st2.top() -> data << " ";
        st2.pop();
    }
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
    iterativePostOrder(root);
}