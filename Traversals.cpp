/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int val){
            data = val;
            left = right = NULL;
        }
};

static int idx = -1;
Node* buildTree(vector<int> pre){
    idx++;
    if(pre[idx] == -1){
        return NULL;
    }
    
    Node* root = new Node(pre[idx]);
    root->left = buildTree(pre);
    root->right = buildTree(pre);
    
    return root;
}

void preOrder(Node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL)
        return;
        
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL)
        return;
        
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
}


int main()
{
    vector<int> pre = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    
    Node* root = buildTree(pre);
    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;
    
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    return 0;
}