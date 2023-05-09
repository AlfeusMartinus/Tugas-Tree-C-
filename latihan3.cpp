#include <iostream>
using namespace std;

struct binaryTree
{
    int data;
    binaryTree *left, *right;
};

binaryTree *pohon, *root;

void deklarasi (){
    pohon = NULL;
}

void insertTree (binaryTree **root, int nilai){
    binaryTree *new_node;
    if((*root == NULL))
    {
        new_node = new binaryTree;
        new_node->data = nilai;
        new_node->left = new_node->right = NULL;

        (*root) = new_node;
        (*root)->data = nilai;
        (*root)->left = (*root)->right = NULL;
        cout << "Data baru " << new_node->data << " sudah ditambahkan" << endl;
    }
    else if ((nilai < (*root)->data))
    {
        insertTree(&(*root)->left, nilai);
        cout << "Data " << nilai << " sudah ditambahkan di sebelah kiri" << endl;
    }
    else
    {
        insertTree(&(*root)->right, nilai);
        cout << "Data " << nilai << " sudah ditambahkan di sebelah kanan" << endl;
    }
}

void preOrder (binaryTree *root){
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder (binaryTree *root){
    if (root != NULL)
    {
        inOrder(root->left);
        cout << (root->data) << " ";
        inOrder(root->right);
    }
}

void postOrder(binaryTree *root){
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << (root->data) << " ";
    }
}

void findTree (binaryTree **root, int cari){
    int level = 0;
    binaryTree *temp;
    temp = new binaryTree;
    temp = (*root);

    while (temp != NULL)
    {
        level++;
        if (temp->data == cari)
        {
            cout << "Data " << cari << " ditemukan" << endl;
            return;
        }
        else if (temp->data > cari)
        {
            temp = temp->left;
        }
        else 
        {
            temp = temp->right;
            level--;
        }
    }
    cout << "Data " << cari << " tidak ditemukan" << endl;
    return;
}

void deleteTree (){
    pohon = NULL;
    cout << "Tree Sudah Terhapus" << endl;
}

int main (){
    int choose;
    do
    {
        cout << "\t============================" << endl;
        cout << "\t\tPROGRAM TREE" << endl;
        cout << "\t============================\n\n" << endl;

        cout << "MENU" << endl;
        cout << "[1] Input Data" << endl;
        cout << "[2] preOrder" << endl;
        cout << "[3] inOrder" << endl;
        cout << "[4] postOrder" << endl;
        cout << "[5] Cari Data" << endl;
        cout << "[6] Hapus Semua Data" << endl;
        cout << "[7] Keluar\n" << endl;
        cout << "Silahkan masukkan pilihan : "; cin >> choose;
        switch (choose)
        {
        case 1:
            int data;
            system("CLS");
            cout << "Masukan data : "; cin >> data;
            insertTree(&pohon, data);
            system("PAUSE");
            system("CLS");
            break;
        case 2:
            system("CLS");
            cout << "Pre Order : ";
            preOrder(pohon);
            cout << endl;
            system("PAUSE");
            system("CLS");
            break;
        case 3:
            system("CLS");
            cout << "In Order : ";
            inOrder(pohon);
            cout << endl;
            system("PAUSE");
            system("CLS");
            break;
        case 4:
            system("CLS");
            cout << "Post Order : ";
            postOrder(pohon);
            cout << endl;
            system("PAUSE");
            system("CLS");
            break;
        case 5:
            int find;
            system("CLS");
            cout << "Masukan data yang akan dicari : "; cin >> find;
            findTree(&pohon, find);
            cout << endl;
            system("PAUSE");
            system("CLS");
            break;
        case 6:
            system("CLS");
            deleteTree();
            system("PAUSE");
            system("CLS");
            break;
        default:
            break;
        }
    } while (choose != 7);
    return 0;  
}