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
    private: 
        int height(Node* root){
            if(root == NULL){
                return 0;
            }
            int lh = height(root->left);
            int rh = height(root->right);
            return max(lh,rh) + 1;
        }

        int balancedHeight(Node* root,bool &ans){
            if(root == NULL){
                ans = false;
                return 0;
            }

            int lh = balancedHeight(root->left,ans);
            int rh = balancedHeight(root->right,ans);
            ans = lh - rh <= 1;
            return 1 + max(lh,rh);
        }

    public:
        bool isBalanced(Node* root){
            if(root == NULL){
                return true;
            }

            bool left = isBalanced(root->left);
            bool right = isBalanced(root->right);
            bool diff = abs(height(root->left) - height(root->right)) <= 1;

            if(left && right && diff){
                return true;
            }
            return false;
        }


        bool isBalancedOptimised(Node* root){
            if(root == NULL){
                return true;
            }

            bool ans;
            int h = balancedHeight(root,ans);
            return ans;
        }

        // pair of <isBalanced,height> ,i.e., <bool,int>
        pair<bool,int> BalancedUsingPair(Node* root){
            if(root == NULL){
                return {true,0};
            }

            bool left = BalancedUsingPair(root->left).first;
            bool right = BalancedUsingPair(root->right).first;
            int lh = BalancedUsingPair(root->left).second;
            int rh = BalancedUsingPair(root->right).second;
            bool diff = abs(lh - rh) <= 1;

            if(left && right && diff){
                return {true,max(lh,rh) + 1};
            }else{
                return {false,max(lh,rh) + 1};
            }
        }

       
     
};

int main(){


    //         1
    //       /   \
    //     2       3
    //    / \       \
    //   4   5       6
    //      / 
    //     7
    //    /
    //   8

    Node* root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->left->left = new Node(8);

    BinaryTree b;
    // if(b.isBalancedOptimised(root)){
    //     cout<<"Balanced";
    // }else{
    //     cout<<"Not Balanced";
    // }
    pair<bool,int> ans;
    ans = b.BalancedUsingPair(root);
    if(ans.first){
        cout<<"Balanced";
    }else{
        cout<<"Not Balanced";
    }


    
   

    return 0;
}