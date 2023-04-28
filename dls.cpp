#include <bits/stdc++.h>
using namespace std;

struct Node {
    struct Node* left;
    struct Node* right;
    int data;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void DLS(Node* root, int limit,int find,bool &helper) {

    if (root == NULL) {
        return;
    }
    if(root->data==find){
        cout<<"Found"<<"\n";
        helper=true;
        return;
    }
    if (limit == 0) {
        return;
    }
    DLS(root->left, limit - 1,find,helper);
    DLS(root->right, limit - 1,find,helper);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    bool helper=false;
    int limit = 1;
    int find=5;
    DLS(root, limit,find,helper);
    if(helper==false){
        cout<<"Not found"<<"\n";
    }

    return 0;
}
