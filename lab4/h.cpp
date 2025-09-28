#include<iostream>
#include<vector>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
    int data; 
    BstNode* left;
    BstNode* right;

    BstNode(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
BstNode* Insert(BstNode* root,int data) {
    if(root == NULL) { // empty tree
        return new BstNode(data);   
    }
    // if data to be inserted is lesser, insert in left subtree. 
    else if(data <= root->data) {
        root->left = Insert(root->left,data);
    }
    // else, insert in right subtree. 
    else {
        root->right = Insert(root->right,data);
    }
    return root;
}
void Check(BstNode* root, int& sum){
    if(!root){
        return;
    }
    Check(root->right, sum);
    sum += root->data;
    cout << sum << " ";
    Check(root->left, sum);
}
int main(){
    int n; cin >> n;
    BstNode* root = nullptr;
    int sum = 0;
    while(n--){
        int a; cin >> a;
        root = Insert(root, a);
    }
    Check(root, sum);
}