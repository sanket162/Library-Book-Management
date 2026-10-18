#include <iostream>
#include <string>
using namespace std;

struct Node {
    int itemID;
    string itemName;
    int quantity;
    Node *left;
    Node *right;
    bool lThread;
    bool rThread;
};

class ThreadedBST {
    Node *root;

public:
    ThreadedBST() { root = NULL; }

    // Insert a stock item
    void insertItem(int id, string name, int qty) {
        Node *ptr = root;
        Node *parent = NULL;

        while (ptr != NULL) {
            if (id == ptr->itemID) {
                cout << "Item ID already exists!\n";
                return;
            }

            parent = ptr;

            if (id < ptr->itemID) {
                if (ptr->lThread == false)
                    ptr = ptr->left;
                else
                    break;
            } else {
                if (ptr->rThread == false)
                    ptr = ptr->right;
                else
                    break;
            }
        }

        Node *newNode = new Node;
        newNode->itemID = id;
        newNode->itemName = name;
        newNode->quantity = qty;
        newNode->lThread = true;
        newNode->rThread = true;

        if (parent == NULL) {
            root = newNode;
            newNode->left = NULL;
            newNode->right = NULL;
        } else if (id < parent->itemID) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->lThread = false;
            parent->left = newNode;
        } else {
            newNode->left = parent;
            newNode->right = parent->right;
            parent->rThread = false;
            parent->right = newNode;
        }

        cout << "Stock item inserted successfully!\n";
    }

    // Find inorder successor
    Node* inorderSuccessor(Node *ptr) {
        if (ptr->rThread == true)
            return ptr->right;

        ptr = ptr->right;

        while (ptr->lThread == false)
            ptr = ptr->left;

        return ptr;
    }

    // Display stock items in ascending order
    void displayStock() {
        if (root == NULL) {
            cout << "Warehouse stock is empty!\n";
            return;
        }

        Node *ptr = root;

        while (ptr->lThread == false)
            ptr = ptr->left;

        cout << "\nID\tName\t\tQuantity\n";
        cout << "--------------------------------\n";

        while (ptr != NULL) {
            cout << ptr->itemID << "\t"
                 << ptr->itemName << "\t\t"
                 << ptr->quantity << endl;

            ptr = inorderSuccessor(ptr);
        }
    }

    // Delete a leaf node only
    void deleteLeaf(int id) {
        Node *parent = NULL;
        Node *ptr = root;

        while (ptr != NULL && ptr->itemID != id) {
            parent = ptr;

            if (id < ptr->itemID) {
                if (ptr->lThread == false)
                    ptr = ptr->left;
                else
                    ptr = NULL;
            } else {
                if (ptr->rThread == false)
                    ptr = ptr->right;
                else
                    ptr = NULL;
            }
        }

        if (ptr == NULL) {
            cout << "Item not found!\n";
            return;
        }

        // A leaf has threads on both sides
        if (ptr->lThread == false || ptr->rThread == false) {
            cout << "Item is not a leaf node!\n";
            cout << "Only leaf nodes can be deleted.\n";
            return;
        }

        // Deleting the only node
        if (parent == NULL) {
            root = NULL;
        } else if (parent->left == ptr) {
            parent->lThread = true;
            parent->left = ptr->left;
        } else {
            parent->rThread = true;
            parent->right = ptr->right;
        }

        delete ptr;
        cout << "Leaf stock item deleted successfully!\n";
    }
};

int main() {
    ThreadedBST warehouse;
    int choice, id, qty;
    string name;

    do {
        cout << "\n--- WAREHOUSE STOCK MANAGEMENT ---\n";
        cout << "1. Insert Stock Item\n";
        cout << "2. Delete Leaf Node\n";
        cout << "3. Display Stock\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Item ID: ";
                cin >> id;

                cout << "Enter Item Name: ";
                cin >> ws;
                getline(cin, name);

                cout << "Enter Quantity: ";
                cin >> qty;

                warehouse.insertItem(id, name, qty);
                break;

            case 2:
                cout << "Enter Item ID to delete: ";
                cin >> id;
                warehouse.deleteLeaf(id);
                break;

            case 3:
                warehouse.displayStock();
                break;

            case 4:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}