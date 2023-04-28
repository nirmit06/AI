#include<bits/stdc++.h>
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

int mx_mn(Node* root,bool mx){

    if(root->left==NULL && root->right==NULL){
        return root->data;
    }

    if(mx){
        int bestval=INT_MIN;

        if(root->left){
            bestval=max(bestval,mx_mn(root->left,false));
        }

        if(root->right){
            bestval=max(bestval,mx_mn(root->right,false));
        }
        return bestval;
    }
    else{
        int bestval=INT_MAX;

        if(root->left){
            bestval=min(bestval,mx_mn(root->left,true));
        }

        if(root->right){
            bestval=min(bestval,mx_mn(root->right,true));
        }
        return bestval;
    }
}
int main(){
    struct Node* root=new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    bool mx=true;
    int ans=mx_mn(root,mx);
    cout<<"The best value is:"<<ans<<"\n";

}