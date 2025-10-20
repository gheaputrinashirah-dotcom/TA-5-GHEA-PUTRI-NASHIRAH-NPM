#include <iostream>
using namespace std;

struct Node {
    int npm;
    Node* left;
    Node* right;
    Node(int n) : npm(n), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int npm) {
    if (!root) return new Node(npm);
    if (npm < root->npm)
        root->left = insertNode(root->left, npm);
    else if (npm > root->npm)
        root->right = insertNode(root->right, npm);
    return root;
}

bool searchNode(Node* root, int npm) {
    if (!root) return false;
    if (root->npm == npm) return true;
    if (npm < root->npm)
        return searchNode(root->left, npm);
    return searchNode(root->right, npm);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->npm << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->npm << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->npm << " ";
}

int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->npm;
}

int findMax(Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->npm;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

long long sumNodes(Node* root) {
    if (!root) return 0;
    return root->npm + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih, npm;

    do {
        cout << "\n=== DATA NPM MAHASISWA (BST) ===\n";
        cout << "1. Insert NPM\n";
        cout << "2. Search NPM\n";
        cout << "3. Inorder\n";
        cout << "4. Preorder\n";
        cout << "5. Postorder\n";
        cout << "6. NPM terkecil\n";
        cout << "7. NPM terbesar\n";
        cout << "8. Jumlah data NPM\n";
        cout << "9. Total penjumlahan semua NPM\n";
        cout << "10. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan NPM: ";
            cin >> npm;
            root = insertNode(root, npm);
            cout << "Data NPM berhasil ditambahkan!\n";
        } 
        else if (pilih == 2) {
            cout << "Masukkan NPM yang dicari: ";
            cin >> npm;
            cout << (searchNode(root, npm) ? "NPM ditemukan!\n" : "NPM tidak ditemukan!\n");
        } 
        else if (pilih == 3) {
            cout << "Traversal Inorder: ";
            inorder(root);
            cout << "\n";
        } 
        else if (pilih == 4) {
            cout << "Traversal Preorder: ";
            preorder(root);
            cout << "\n";
        } 
        else if (pilih == 5) {
            cout << "Traversal Postorder: ";
            postorder(root);
            cout << "\n";
        } 
        else if (pilih == 6) {
            cout << "NPM terkecil: " << findMin(root) << "\n";
        } 
        else if (pilih == 7) {
            cout << "NPM terbesar: " << findMax(root) << "\n";
        } 
        else if (pilih == 8) {
            cout << "Jumlah data NPM: " << countNodes(root) << "\n";
        } 
        else if (pilih == 9) {
            cout << "Total semua NPM: " << sumNodes(root) << "\n";
        }

    } while (pilih != 10);

    cout << "Program selesai.\n";
    return 0;
}