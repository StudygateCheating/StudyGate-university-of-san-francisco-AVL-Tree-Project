

#include <iostream>

using namespace std;


// In this project, implement an AVL tree with one function
// -- AVL_Insert: insert a new node into AVL tree 
//
// In the main function, we will insert 10 nodes into AVL 
// Then, we will enumarate these nodes based on in-order traverse 
// The enumeration function has been implemented for you
// 
// Some functions are provided. You don't have to use them. 

class Node {

public:

    int SID = 0;

    Node* left = NULL;

    Node* right = NULL;

    Node* parent = NULL;

    int balanceFactor = 0;

    int height = -1;

};

void enumerate(Node* ptr) { // in-order traverse 

    if (ptr->left != NULL) {

        enumerate(ptr->left);

    }
    cout << ptr->SID << ' ';

    if (ptr->right != NULL) {

        enumerate(ptr->right);
    }
}

Node* insert(Node* root, Node* x) { // insert a node to a tree with root

    if (root == NULL) {

        root = x;
    }
    else {

        if (x->SID <= root->SID) {

            root->left = insert(root->left, x);
        }
        else {

            root->right = insert(root->right, x);
        }
    }

    return root;
}


class AVL {

public:

    Node* GetRoot(); // return root node pointer; not really used in testing 

    void AVL_Enumerate(); // enumerate nodes based on in-order traverse 

    void AVL_Insert(Node* x); // insert a new node x into AVL tree 

private:

    Node* root = NULL;
   
    
};
// in-order traversal
void AVL::AVL_Enumerate() {
//call enumerate for in-order traversal from header file
  enumerate(root);
}


int depth(Node* ptr) { // measure depth of a node 

    int counter = 0;

    while (ptr->parent != NULL) {

        ptr = ptr->parent;

        counter++;
    }

    return counter;
}



// insert a new node
    void AVL::AVL_Insert(Node* x){
       // call method  insert to insert node x in AVL tree
       root= insert(root, x) ;
        
    }
int isRoot(Node* ptr) { // check if node is root or not

    if (ptr->parent == NULL) {

        return 1;
    }
    else {

        return 0;
    }
}


int isLeaf(Node* ptr) { // check if node is leaf or not

    if (ptr->left == NULL && ptr->right == NULL) {

        return 1;
    }
    else {

        return 0;
    }
}





int findmax(Node* root) { // find max node from a tree with root 

    if (root->right == NULL) {

        return root->SID;
    }
    else {

        return findmax(root->right);
    }
}

Node* rotation_counterclock(Node* root) { // rotate tree at root counter clockwise 

    Node* temp = root->right;

    if (root->right->left != NULL) {

        root->right = root->right->left;
    }

    temp->left = root;

    root = temp;

    return root;
}


int main()
{
    Node tmp[10];

    for (int i = 0; i < 10; i++) {
    
        cin >> tmp[i].SID;
    }

    AVL x;

    for (int i = 0; i < 10; i++) {
    
        x.AVL_Insert(&tmp[i]);    
    }

    int operationChoice;

    cin >> operationChoice;

    if (operationChoice == 1) { // enumerate key 

        x.AVL_Enumerate();
    }
    else {

        cout << "Enter a valid choice";
    }

    return 0;
}

