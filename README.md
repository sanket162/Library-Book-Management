# Warehouse Stock Management System Using Threaded BST

## Introduction

This project is a Warehouse Stock Management System developed using C++. It uses a Threaded Binary Search Tree to store and manage stock items. Each item contains an item ID, item name, and quantity.

The main purpose of this project is to understand how a Threaded BST works and how it can be used to manage warehouse stock.

## Features

- Insert new stock items.
- Delete a leaf node from the tree.
- Display stock items in ascending order of item ID.
- Maintain threads correctly during insertion and deletion.

## Technologies Used

- C++
- Threaded Binary Search Tree
- Pointers and Structures

## How It Works

The program stores stock items in a Threaded Binary Search Tree. Each item is arranged according to its ID. During insertion, the item is placed in the correct position, and the threads are updated. During deletion, only leaf nodes are removed, and the related threads are maintained. The display operation uses inorder successor traversal to show stock items in sorted order.

## How to Run

1. Download or clone the repository.
2. Open the project in VS Code.
3. Compile the C++ program using:

   `g++ main.cpp -o warehouse`

4. Run the program using:

   `warehouse.exe`

## Conclusion

This project helped me understand the working of a Threaded Binary Search Tree and its use in stock management. It also improved my understanding of pointers, insertion, deletion, and tree traversal in C++.

## Author

C++ Data Structures Project