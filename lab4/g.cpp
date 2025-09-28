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
    BstNode* Insert(BstNode* root,int head, int data, int pos) {
        if(!root){
            return nullptr;
        }
        if(root->data == head){
            if(pos){
                root->right = new BstNode(data);
            }else{
                root->left = new BstNode(data);
            }
        }
        Insert(root->right, head, data, pos);
        Insert(root->left, head, data, pos);
        return root;
    }
    int level(BstNode* root){
        if(!root){
            return 0;
        }
        return 1 + max(level(root->right), level(root->left));
        
    }
    int main(){
        int n1; cin >> n1;
        BstNode* root = new BstNode(1);
        int n = n1-1;
        while(n--){
            int x,y,z; cin >> x >> y >> z;
            Insert(root, x, y, z);
        }
        int lvl = level(root);
    }