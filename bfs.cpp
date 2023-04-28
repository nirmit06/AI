#include <bits/stdc++.h>
using namespace std;

struct Node{
    struct Node* left;
    struct Node* right;
    int data;

    Node (int val){
        data=val;
        left=right=NULL;
    }
};

int main(){
    struct Node* root=new Node(1);root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int sz=q.size();

        for(int i=0;i<sz;i++){
            cout<<q.front()->data<<" ";

            if(q.front()->left)
            q.push(q.front()->left);

            if(q.front()->right)
            q.push(q.front()->right);
            q.pop();
        }
    }
}