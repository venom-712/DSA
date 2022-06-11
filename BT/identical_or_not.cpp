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

    public:
        
        bool isIdentical(Node* r1, Node* r2){
            if((r1 == NULL && r2 != NULL) ||( r1 != NULL && r2 == NULL)){
                return false;
            }

            if(r1 == NULL && r2 == NULL){
                return true;
            }


            bool left = isIdentical(r1->left,r2->left);
            bool right = isIdentical(r1->right,r2->right);

            bool checkValue = r1->data == r2->data;

            if(left && right && checkValue){
                return true;
            }else{
                return false;
            }

        }
       
     
};

int main(){

    //        r1                 r2
    //         1                  1
    //       /   \              /   \
    //      2     3            2     3


    Node* r1 = NULL;
    r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);

    Node* r2 = NULL;
    r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);    


    BinaryTree b;
    if(b.isIdentical(r1,r2)){
        cout<<"Identical";
    }else{
        cout<<"Not Identical";
    }


    
   

    return 0;
}