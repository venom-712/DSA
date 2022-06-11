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
        pair<bool,int> checkSum(Node* root){
            if(root == NULL){
                return {true,0};
            }
            if(root->left == NULL && root->right == NULL){
                return {true,root->data};
            }

            pair<bool,int> leftAns = checkSum(root->left);
            pair<bool,int> rightAns = checkSum(root->right);

            bool left = leftAns.first;
            bool right = rightAns.first;
            bool check = root->data == (leftAns.second + rightAns.second);

            pair<bool,int> ans;
            if(left && right && check){
                ans.first = true;
                ans.second = 2 * root->data;
            }else{
                ans.first = false;
            }
            return ans;

        }
};

int main(){

    //        17
    //       /  \
    //     7      3
    //    / \       
    //   5   2  

    // root->data = sumOf(leftSubtree) + sumOf(rightSubtree)
  

    Node* root = NULL;
    root = new Node(17);
    root->left = new Node(7);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(2);
    
    BinaryTree b;

    if(b.checkSum(root).first){
        cout<<"Valid";
    }else{
        cout<<"Invalid";
    }
    

    return 0;
}