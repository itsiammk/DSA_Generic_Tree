#include<bits/stdc++.h>
using namespace std;
#include "treeNode.h"
#define endl "\n"

TreeNode<int> * takeInputBetter(){
    int rootNode;
    cout<<"Enter root node: ";cin>>rootNode;
    TreeNode<int> * root = new TreeNode<int>(rootNode);
    queue< TreeNode<int> * > qNode;
    qNode.emplace(root);
    while(not qNode.empty()){
        TreeNode<int> * front = qNode.front();
        qNode.pop();
        int n;
        cout<<"Enter number of childrens for "<<front->data<<": ";
        cin>>n;
        for(int i=0;i<n;++i){
            cout<<"Enter children no. "<<i<<": ";
            int childNode;cin>>childNode;
            TreeNode<int> * childTreeNode = new TreeNode<int>(childNode);
            front->children.emplace_back(childTreeNode);
            qNode.emplace(childTreeNode);
        }
    }
    return root;
}

TreeNode<int> * takeInput(){
    int rootData;
    cout<<"Enter data: "; cin>>rootData;
    TreeNode<int> * root = new TreeNode<int>(rootData);

    int n;
    cout<<"Enter number of childrens for "<<rootData<<" : ";
    cin>>n;
    while(n--){
        TreeNode<int> * child =  takeInput();
        root->children.push_back(child);
    }
    return root;

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

    // TreeNode<int> * root = new TreeNode<int>(1);
    // TreeNode<int> * node1 = new TreeNode<int>(2);
    // TreeNode<int> * node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int> * root = takeInputBetter();
    printTree(root);

    return 0;
}