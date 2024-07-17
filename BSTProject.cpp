#include <iostream>
using namespace std;

// Node structure defination
struct Node {
    int value;
    Node* left;
    Node* right;
};
// Function to create and initialize a new node
Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->value = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
// Function to insert a value into the Binary search tree
Node* insert(Node* node, int val) {
    if (node == nullptr) return createNode(val);

    if (val < node->value) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }
    return node;
}
// Function to search for a value in the Binary Search Tree
Node* search(Node* node, int val) {
    if (node == nullptr || node->value == val) return node;

    if (val < node->value) return search(node->left, val);

    return search(node->right, val);
}
// Function to get the node with the minimum value in a subtree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) current = current->left;
    return current;
}
// Function to delete a node from the Binary Search Tree
Node* deleteNode(Node* node, int val) {
    if (node == nullptr) return node;

    if (val < node->value) {
        node->left = deleteNode(node->left, val);
    } else if (val > node->value) {
        node->right = deleteNode(node->right, val);
    } else {
        // Node with only one  or no child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = minValueNode(node->right);
        node->value = temp->value;
        // Delete the inorder successor
        node->right = deleteNode(node->right, temp->value);
    }
    return node;
}

// Function for in-order traversal in the tree
void inOrder(Node* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->value << " ";
    inOrder(node->right);
}

// Function for pre-order traversal in the tree
void preOrder(Node* node) {
    if (node == nullptr) return;
    cout << node->value << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// Function for post-order traversal in the tree
void postOrder(Node* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->value << " ";
}

int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "1. Insert\n2. Search\n3. Delete\n4. InOrder Traversal\n5. PreOrder Traversal\n6. PostOrder Traversal\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value))
                    cout << "Value found.\n";
                else
                    cout << "Value not found.\n";
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout<<"The value is deleted.\n";
                break;
            case 4:
                cout << "InOrder Traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "PreOrder Traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "PostOrder Traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}