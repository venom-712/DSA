#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


class BinaryTree{
    public:
        int height(Node* root){
            if(root == NULL){
                return 0;
            }
            int lh = height(root->left);
            int rh = height(root->right);
            return max(lh,rh) + 1;
        }

        int diameter(Node* root){
            if(root == NULL){
                return 0;
            }

            int opt1 = diameter(root->left);
            int opt2 = diameter(root->right);
            int opt3 = height(root->left) + height(root->right) + 1;

            int ans = max(max(opt1,opt2),opt3);
            return ans;

        }
};

int main(){

    Node* root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);

    BinaryTree b;
    cout<<"Diameter of tree is : "<<b.diameter(root)<<endl;

    return 0;
}