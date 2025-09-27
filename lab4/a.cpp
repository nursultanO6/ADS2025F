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
int main(){
    int n, q; cin >> n >> q;
    BstNode* root = nullptr;
    for(int i = 0;i < n; i++){
        int a; cin >> a;
        root = Insert(root, a);
    }

    while(q--){
        string s; cin >> s;
        BstNode* temp = root;
        bool tr = 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                if(temp->left){
                    temp = temp->left;
                }else{
                    cout << "NO" << endl;
                    tr = 0;
                    break;
                }
            }else{
                if(temp->right){
                    temp = temp->right;
                }else{
                    cout << "NO" << endl;
                    tr = 0;
                    break;
                }
            }
        }
        if(tr){
            cout << "YES" << endl;
        }
    }
}