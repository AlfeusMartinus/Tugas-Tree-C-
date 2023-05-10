// KELOMPOK 1
// 1. Alfeus Martinus
// 2. Jovanka Alexandro
// 3. Muhammad Tsaqiif Ash-Shidiq
// 4. Naufal Hadi Darmawan
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

void removeNode (binaryTree **root, int remove){
    if (*root == NULL)
    {
        cout << "Tree Kosong" << endl;
        return;
    }
    else  
    {
        if (remove < (*root)->data)
        {
            removeNode(&(*root)->left, remove);
        }
        else if (remove > (*root)->data)
        {
            removeNode(&(*root)->right, remove);
        }
        else  
        {
            binaryTree *temp;
            if ((*root)->left == NULL && (*root)->right == NULL)
            {
                temp = *root;
                *root = NULL;
                delete temp;
                cout << "Menghapus leaf node" << endl;
                return;
            }
            else if ((*root)->left == NULL)
            {
                temp = *root;
                *root = (*root)->right;
                delete temp;
                cout << "Node Berhasil Terhapus" << endl;
                return;
            }
            else if ((*root)->right == NULL)
            {
                temp = *root;
                *root = (*root)->left;
                delete temp;
                cout << "Node Berhasil Terhapus" << endl;
                return;
            }
            else
            {
                temp = (*root)->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                (*root)->data = temp->data;
                removeNode(&(*root)->right, temp->data);
            }
        }
    }
}

int countNode(binaryTree *root)
{
    if (root != NULL)
    {
        return 1 + countNode(root->left) + countNode(root->right);
    }
}

int main (){
    int choose;
    do
    {
        cout << "\t\033[1m============================\033[0m" << endl;
        cout << "\t\t\033[1mPROGRAM TREE\033[0m" << endl;
        cout << "\t\033[1m============================\033[0m\n\n" << endl;

        cout << "\033[1m\tMENU\033[0m" << endl;
        cout << "\033[1m======================\033[0m" << endl;
        cout << "[1] Input Data" << endl;
        cout << "[2] Penelusuran" << endl;
        cout << "[3] Cari Data" << endl;
        cout << "[4] Hapus Semua Data" << endl;
        cout << "[5] Hapus Node" << endl;
        cout << "[6] Hitung Jumlah Node" << endl;
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
            cout << "Pre Order \t: ";
            preOrder(pohon);
            cout << endl;
            cout << "In Order \t: ";
            inOrder(pohon);
            cout << endl;
            cout << "Post Order \t: ";
            postOrder(pohon);
            cout << endl;
            system("PAUSE");
            system("CLS");
            break;
        case 3:
            int find;
            system("CLS");
            cout << "Masukan data yang akan dicari : "; cin >> find;
            findTree(&pohon, find);
            cout << endl;
            system("PAUSE");
            system("CLS");
            break;
        case 4:
            system("CLS");
            deleteTree();
            system("PAUSE");
            system("CLS");
            break;
        case 5:
            int chooseNode;
            system("CLS");
            inOrder(pohon); cout << endl;
            cout << "Masukan node yang akan di hapus : "; cin >> chooseNode;
            removeNode(&pohon, chooseNode);
            system("PAUSE");
            system("CLS");
            break;
        case 6:
            system("CLS");
            cout << "Banyak Node pada Tree Sebanyak : " << countNode(pohon) << endl;
            system("PAUSE");
            system("CLS");
            break;
        default:
            break;
        }
    } while (choose != 7);
    return 0;  
}
