#include<bits/stdc++.h>
using namespace std;
#include "treeNode.h"
#define endl "\n"

void printLeveWise(TreeNode<int> * root){
    if(not root) return ;
    queue<TreeNode<int>*> qu;
    qu.emplace(root);
    while(not qu.empty()){
        cout<<qu.front()->data<<": ";
        for(int i=0;i<qu.front()->children.size();i++){
            cout<<qu.front()->children[i]->data<<",";
            qu.emplace(qu.front()->children[i]);
        }cout<<endl;
        qu.pop();
    }
}

void printTree(TreeNode<int> * root){
    if(root == NULL) return;

    cout<<root->data<<" : ";
    for(int i=0 ; i < root->children.size() ; ++i){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0 ; i < root->children.size() ; ++i){
        printTree(root->children[i]);
    }
}

int main(){

    TreeNode<int> * root = new TreeNode<int>(1);
    TreeNode<int> * node1 = new TreeNode<int>(2);
    TreeNode<int> * node2 = new TreeNode<int>(3);
    TreeNode<int> * node3 = new TreeNode<int>(4);
    TreeNode<int> * node4 = new TreeNode<int>(5);
    root->children.push_back(node1);
    root->children.push_back(node2);
    node1->children.push_back(node3);
    node1->children.push_back(node4);

    printTree(root);
    cout<<endl;
    printLeveWise(root);

    return 0;
}