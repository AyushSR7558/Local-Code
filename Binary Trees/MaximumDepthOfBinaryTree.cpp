#include<iostream>
#include<math.h>
#include<stack>
using  namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};
int recursiveMaximumDepth(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(recursiveMaximumDepth(root -> left),recursiveMaximumDepth(root -> right));
}
void printStack(stack<Node*>st){
    while(!st.empty()){
        cout << st.top() -> val;
        st.pop();
    }
    cout << endl;
}
int levelOrderMaximumDepth(Node*root){
    stack<Node*> st;
    st.push(root);
    int count = 0;
    while(!st.empty()){
        int a = st.size();
        count++;
        for(int i = 0; i < a; i++){
            Node* temp = st.top();
            st.pop();
            if(temp -> left != NULL){
                st.push(temp -> left);
            }
            if(temp -> right != NULL){
                st.push(temp -> right);
            }
        }
    }
    return count;
}
int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> left -> left = new Node(5);
    root -> right -> right = new Node(6);
    cout << "The maximum Depth for the given tree wil be equal to " << levelOrderMaximumDepth(root);
    return 0;
}