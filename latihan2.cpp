#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree *left, *right;
};

tree *pohon, *root;

void deklarasi (){
    pohon = NULL;
}

void insertTree (tree **root, int nilai){
    tree *new_node;
    if((*root == NULL))
    {
        new_node = new tree;
        new_node->data = nilai;
        new_node->left = new_node->right = NULL;

        (*root) = new_node;
        (*root)->data = nilai;
        (*root)->left = (*root)->right = NULL;
    }   
    else if ((nilai < (*root)->data))
    {
        insertTree(&(*root)->left, nilai);
    }
    else  
    {
        insertTree(&(*root)->right, nilai);
    }
}

void printLeaf (tree *root){
    if (root == NULL)
    {
        return;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }
    printLeaf(root->left);
    printLeaf(root->right);    
}

void printInternalNode(tree *root, bool isRoot) {
    if (root == NULL) {
        return;
    }

    if (isRoot && root->left == NULL && root->right == NULL) {
        return;
    }

    if (!isRoot && (root->left != NULL || root->right != NULL)) {
        cout << root->data << " ";
    }

    printInternalNode(root->left, false);
    printInternalNode(root->right, false);
}


void printSibling (tree *root){
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->left->data << " " << root->right->data << " ";
        printSibling(root->left);
        printSibling(root->right);
    }
}

int main (){
    insertTree(&pohon, 50);
    insertTree(&pohon, 17);
    insertTree(&pohon, 12);
    insertTree(&pohon, 23);
    insertTree(&pohon, 9);
    insertTree(&pohon, 14);
    insertTree(&pohon, 19);
    insertTree(&pohon, 72);
    insertTree(&pohon, 54);
    insertTree(&pohon, 70);
    insertTree(&pohon, 67);

    cout << "Root : "<< pohon->data << endl;
    cout << "Leaf : "; printLeaf(pohon); cout << endl;
    cout << "Internal Node : "; printInternalNode(pohon, true); cout << endl;
    cout << "Sibling : "; printSibling(pohon); cout << endl;
}
