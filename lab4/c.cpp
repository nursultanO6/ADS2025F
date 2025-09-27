#include<iostream>
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


// To insert data in BST, returns address of root node 
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
BstNode* search(BstNode* root, int q){
    BstNode* temp = root;
    if(!root)return NULL;
    if(root->data > q){
        return search(root->left, q);
    }else if(root->data < q){
        return search(root->right, q);
    }else{
        return root;
    }

}

void cnt(BstNode* root){
    if(!root){
       return;
    }
    cout << root->data << " ";
    cnt(root->left);
    cnt(root->right);

}
int main(){
    int n; cin >> n;
    BstNode* root = nullptr;
    while(n--){
        int a;cin >> a;
        root = Insert(root, a);
    }
    int q; cin >> q;
    BstNode* temp = search(root, q);
    cnt(temp);
}