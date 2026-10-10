#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    int id;
    char name[50];
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

// Add a book
void addBook()
{
    Node* newNode = new Node;

    cout << "Enter Book ID: ";
    cin >> newNode->id;

    cout << "Enter Book Name: ";
    cin >> ws;
    cin.getline(newNode->name, 50);

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "Book added successfully.\n";
}

// Display forward
void displayForward()
{
    Node* temp = head;

    if (temp == NULL)
    {
        cout << "No books available.\n";
        return;
    }

    while (temp != NULL)
    {
        cout << temp->id << " - "
             << temp->name << endl;
        temp = temp->next;
    }
}

// Display backward
void displayBackward()
{
    Node* temp = tail;

    if (temp == NULL)
    {
        cout << "No books available.\n";
        return;
    }

    while (temp != NULL)
    {
        cout << temp->id << " - "
             << temp->name << endl;
        temp = temp->prev;
    }
}

// Delete a book
void deleteBook()
{
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Book not found.\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    delete temp;
    cout << "Book deleted successfully.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- Library Book Management ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Forward\n";
        cout << "3. Display Backward\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addBook(); break;
            case 2: displayForward(); break;
            case 3: displayBackward(); break;
            case 4: deleteBook(); break;
            case 5: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    // Release remaining memory
    Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
    return 0;
}