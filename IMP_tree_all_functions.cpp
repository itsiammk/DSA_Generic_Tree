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
void printLevelWise(TreeNode<int> * root){
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
int totalNodes(TreeNode<int> * root){
    if(not root) return 0;
    int size = 1;
    for(int i=0;i<root->children.size();i++){
        size += totalNodes(root->children[i]);
    }
    return size;
}
int sumNodes(TreeNode<int> * root){
    if(not root) return 0;
    int sum = root->data;
    for(int i=0;i<root->children.size();i++){
        sum += sumNodes(root->children[i]);
    }
    return sum;
}
int largestData(TreeNode<int> * root){
    int largest = INT_MIN;
    largest = max(largest, root->data);
    for(int i=0;i<root->children.size();i++){
        largest = max(largest, largestData(root->children[i]));
    }
    return largest;
}
int heightOfTree(TreeNode<int> * root){
    int height = 1;
    for(int i=0;i<root->children.size();i++){
        height = heightOfTree(root->children[i])+1;
    }
    return height;
}
void printDepth(TreeNode<int> * root, int depth){
    if(depth == 0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printDepth(root->children[i], depth-1);
    }
}
void printLeafNodes(TreeNode<int> * root){
    if(root->children.size()==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printLeafNodes(root->children[i]);
    }
}
int totalLeafNodes(TreeNode<int> * root){
    int sum=0;
    if(root->children.size()==0){
        return 1;
    }
    for(int i=0;i<root->children.size();i++){
        sum += totalLeafNodes(root->children[i]);
    }
    return sum;
}
void preorderPrint(TreeNode<int> * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorderPrint(root->children[i]);
    }
}
void postorderPrint(TreeNode<int> * root){
    if(root == NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postorderPrint(root->children[i]);
    }
    cout<<root->data<<" ";
}
int countNodesGreater(TreeNode<int>* root, int val){
    // if(not root)return 0;
    int sum = 0;
    if(root->data > val){
        sum+= 1;
    }
    for(int i=0;i<root->children.size();i++){
        sum += countNodesGreater(root->children[i], val);
    }
    return sum;
}


int main(){

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> * root = takeInputBetter();
    // printLevelWise(root);
    // cout<<"Total Nodes: "<<totalNodes(root);
    // cout<<endl;
    // cout<<"Sum of all Nodes: "<<sumNodes(root);
    // cout<<endl;
    // cout<<"Largest Data Node: "<<largestData(root);
    // cout<<endl;
    // cout<<"Height of Tree: "<<heightOfTree(root);
    // cout<<endl;
    // cout<<"Depth Nodes :  ";
    // printDepth(root, 2);
    // cout<<endl;
    // cout<<"Leaf Nodes are : ";
    // printLeafNodes(root);
    // cout<<endl;
    // cout<<"Total leaf Nodes: "<<totalLeafNodes(root);
    // cout<<endl;
    // cout<<"PreOrder Print: ";
    // preorderPrint(root);
    // cout<<endl;
    // cout<<"PostOrder Print: ";
    // postorderPrint(root);
    // cout<<endl;
    cout<<"\nTotal nodes greater are: "<<countNodesGreater(root, 10)<<endl;
    delete root;

    return 0;
}