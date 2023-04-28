#include <bits/stdc++.h>
using namespace std;

struct Node{
    struct Node* left;
    struct Node* right;
    int data;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void DFS(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left!=NULL){
        DFS(root->left);
    }

    if(root->right!=NULL){

        DFS(root->right);
    }


}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    DFS(root);
};