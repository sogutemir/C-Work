#include <iostream>
#include <queue>

// Define the structure for the tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

// Define the Binary Search Tree class
class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

    // Function to insert a new value into the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function for level order traversal
    void levelOrder() {
        if (root == nullptr) return;

        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            std::cout << current->value << " ";
            if (current->left != nullptr) queue.push(current->left);
            if (current->right != nullptr) queue.push(current->right);
        }
        std::cout << std::endl;
    }

private:
    // Helper recursive function to insert a new value
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->value) {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }
};

// Main function to demonstrate the functionality
int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << "Level-order traversal of BST: ";
    bst.levelOrder();

    return 0;
}
