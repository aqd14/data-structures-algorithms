//
// Created by Quoc Anh Do on 10/21/19.
//

#include <iostream>
#include <queue>

struct Node;

void InOrderTraversal(Node *, std::queue<int> &);

void PreOrderTraversal(Node *, std::queue<int> &);

// Binary Tree's node
struct Node {
    int value;
    Node *left, *right;

    explicit Node(int value) {
        this->value = value;
        left = right = nullptr;
    }
};

// The main function to call when we want to convert a BST to a Min Heap
void ConvertBST2Heap(Node *root, std::queue<int> &q) {
    InOrderTraversal(root, q);
    PreOrderTraversal(root, q);
}

// Run inorder traversal for the BST tree and store all the nodes into queue
void InOrderTraversal(Node *root, std::queue<int> &q) {
    if (root == nullptr) return;

    InOrderTraversal(root->left, q);
//    std::cout << root->value << " ";
    q.push(root->value);
    InOrderTraversal(root->right, q);
}

// Traverse the BST tree and
void PreOrderTraversal(Node *root, std::queue<int> &q) {
    if (root == nullptr) return;

//    std::cout << root->value << " ";
    root->value = q.front(); // get the first element in the queue
    q.pop(); // remove the current first element so that next time we retrieve the next element
    PreOrderTraversal(root->left, q);
    PreOrderTraversal(root->right, q);
}

// Print out the tree in level-order to check the output
void LevelOrderTraversal(Node *root) {
    if (root == nullptr) return;
    std::cout << "Print Level Order Traversal...\n";
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node *temp = q.front();
            q.pop();
            std::cout << temp->value << " ";
            if (temp->left != nullptr) q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

// We don't use this function for this assignment, just something to play with
void PostOrderTraversal(Node *root) {
    if (root == nullptr) return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    std::cout << root->value << " ";
}

int main() {
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    LevelOrderTraversal(root);

    // convert binary search tree to a min heap
    std::queue<int> q;
    ConvertBST2Heap(root, q);
    LevelOrderTraversal(root);

    return 0;
}
