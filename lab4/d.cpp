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
int level(BstNode* root){
    if(!root){
        return 0;
    }
    return 1 + max(level(root->right), level(root->left));
    
}
void sum(vector<int>& sums, BstNode* root, int i){
    if(!root){
        return;
    }
    sums[i] += root->data;
    i++;
    sum(sums, root->right, i);
    sum(sums, root->left, i);
}
int main(){
    int n; cin >> n;
    BstNode* root = nullptr;
    while(n--){
        int a; cin >> a;
        root = Insert(root,a);
    }
    int lvl = level(root);
    vector<int> sums(lvl, 0);
    sum(sums, root,0);
    cout << lvl << endl;
    for(int i = 0; i < lvl; i++){
        cout << sums[i] << " ";
    }

}