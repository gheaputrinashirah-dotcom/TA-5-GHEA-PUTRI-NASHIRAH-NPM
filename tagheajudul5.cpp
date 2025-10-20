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
    if (npm < root->npm) root->left = insertNode(root->left, npm);
    else if (npm > root->npm) root->right = insertNode(root->right, npm);
    return root;
}

bool searchNode(Node* root, int npm) {
    if (!root) return false;
    if (root->npm == npm) return true;
    if (npm < root->npm) return searchNode(root->left, npm);
    return searchNode(root->right, npm);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->npm << " ";
    inorder(root->right);
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumNodes(Node* root) {
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
        cout << "4. Jumlah data NPM\n";
        cout << "5. Total penjumlahan semua NPM\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan NPM: ";
            cin >> npm;
            root = insertNode(root, npm);
        } else if (pilih == 2) {
            cout << "Masukkan NPM yang dicari: ";
            cin >> npm;
            cout << (searchNode(root, npm) ? "NPM ditemukan!\n" : "NPM tidak ditemukan!\n");
        } else if (pilih == 3) {
            cout << "Traversal Inorder: ";
            inorder(root);
            cout << "\n";
        }  else if (pilih == 8) {
            cout << "Jumlah data NPM: " << countNodes(root) << "\n";
        } else if (pilih == 9) {
            cout << "Total semua NPM: " << sumNodes(root) << "\n";
        }
    } while (pilih != 10);
    
    return 0;
}
