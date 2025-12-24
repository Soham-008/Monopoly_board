//
// Created by Soham Kulkarni on 10/2/24.
//

#include "Monopoly_Board.h"
//Class Monopoly at line 6
//Class node at 42
//Class Circular linked list at 56
// Main is at 251
#include <iostream>
#include <string>
using namespace std;

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    // Overloaded the constructor
    MonopolyBoard(string propertyName, string propertyColor, int value, int rent) {
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }

    // Equality checking
    bool isEqual(MonopolyBoard other) {
        return (propertyName == other.propertyName &&
                propertyColor == other.propertyColor &&
                value == other.value &&
                rent == other.rent);
    }

    // Printing the property details
    void print() {
        cout << "Property: " << propertyName << endl;
        cout << "Color: " << propertyColor << endl;
        cout << "Value: $" << value << endl;
        cout << "Rent: $" << rent << endl;
    }
};

// Template Node class
template <typename T>
class Node {
public:
    T data;
    Node* nextNode;


    Node(T value) : data(value) {
        nextNode = nullptr;
    }
};

// Template CircularLinkedList class
template <typename T>
class CircularLinkedList {
private:
    Node<T>* headNode;

public:
    CircularLinkedList() {
        headNode = nullptr;
    }

    // Core Tasks
    void insertAtHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!headNode) { // If list is empty
            headNode = newNode;
            newNode->nextNode = headNode; // Circular link
        } else {
            Node<T>* temp = headNode;
            while (temp->nextNode != headNode) {
                temp = temp->nextNode;
            }
            newNode->nextNode = headNode; // Link new node to the current head
            temp->nextNode = newNode;     // Link last node to new node
            headNode = newNode;           // Update head to the new node
        }
    }

    void insertAtTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!headNode) { // If list is empty
            headNode = newNode;
            newNode->nextNode = headNode; // Circular link
        } else {
            Node<T>* temp = headNode;
            while (temp->nextNode != headNode) {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;     // Link last node to new node
            newNode->nextNode = headNode; // Link new node to head (circular)
        }
    }

    void insertAtPosition(T value, int pos) {
        Node<T>* newNode = new Node<T>(value);
        if (!headNode || pos == 1) { // If list is empty or inserting at head
            insertAtHead(value);
        } else {
            Node<T>* temp = headNode;
            int count = 1;
            while (count < pos - 1 && temp->nextNode != headNode) {
                temp = temp->nextNode;
                count++;
            }
            newNode->nextNode = temp->nextNode; // Link new node to next node
            temp->nextNode = newNode;           // Link previous node to new node
        }
    }

    void deleteAtHead() {
        if (!headNode) return; // Empty list

        if (headNode->nextNode == headNode) { // Single node in the list
            delete headNode;
            headNode = nullptr;
        } else {
            Node<T>* temp = headNode;
            Node<T>* last = headNode;

            while (last->nextNode != headNode) {
                last = last->nextNode;
            }
            last->nextNode = headNode->nextNode; // Update circular link
            headNode = headNode->nextNode;       // Move head to the next node
            delete temp;
        }
    }

    void deleteAtTail() {
        if (!headNode) return; // Empty list

        if (headNode->nextNode == headNode) { // Single node
            delete headNode;
            headNode = nullptr;
        } else {
            Node<T>* temp = headNode;
            Node<T>* prev = nullptr;

            while (temp->nextNode != headNode) {
                prev = temp;
                temp = temp->nextNode;
            }
            prev->nextNode = headNode; // Update the second last node to point to head
            delete temp;
        }
    }

    void deleteAtPosition(int pos) {
        if (!headNode || pos == 1) { // If list is empty or deleting head
            deleteAtHead();
        } else {
            Node<T>* temp = headNode;
            Node<T>* prev = nullptr;
            int count = 1;

            while (count < pos && temp->nextNode != headNode) {
                prev = temp;
                temp = temp->nextNode;
                count++;
            }
            if (temp == headNode) return; // Position out of bounds

            prev->nextNode = temp->nextNode; // Bypass the node to delete
            delete temp;
        }
    }

    void search(T value) {
        Node<T>* temp = headNode;
        do {
            if (temp->data.isEqual(value)) {
                cout << "Property found!" << endl;
                temp->data.print();
                return;
            }
            temp = temp->nextNode;
        } while (temp != headNode);
        cout << "Property not found." << endl;
    }

    void printList() {
        if (!headNode) {
            cout << "List is empty!" << endl;
            return;
        }
        Node<T>* temp = headNode;
        do {
            temp->data.print();  // Call print function of MonopolyBoard
            temp = temp->nextNode;
        } while (temp != headNode);
    }

    // Optional Tasks
    void reverseCLList() {
        cout << "Reverse List unwritten" << endl;
    }

    void sortCLList() {
        cout << "Sort List unwritten" << endl;
    }

    void printHeadNode() {
        if (!headNode) {
            cout << "Head Node is empty!" << endl;
        } else {
            cout << "Head Node: ";
            headNode->data.print();
        }
    }

    void printLastNode() {
        if (!headNode) {
            cout << "List is empty!" << endl;
        } else {
            Node<T>* temp = headNode;
            while (temp->nextNode != headNode) {
                temp = temp->nextNode;
            }
            cout << "Last Node: ";
            temp->data.print();
        }
    }

    void isListEmpty() {
        if (!headNode) {
            cout << "List is empty." << endl;
        } else {
            cout << "List is not empty." << endl;
        }
    }

    void countNodes() {
        if (!headNode) {
            cout << "No nodes in the list." << endl;
            return;
        }
        int count = 0;
        Node<T>* temp = headNode;
        do {
            count++;
            temp = temp->nextNode;
        } while (temp != headNode);
        cout << "Number of nodes in the list: " << count << endl;
    }
};

// Main function to demonstrate the LinkedList class
int main() {
    // Create a LinkedList of MonopolyBoard objects
    CircularLinkedList<MonopolyBoard> list;

    // Create properties
    MonopolyBoard prop1("Park Place", "Blue", 350, 50);
    MonopolyBoard prop2("Boardwalk", "Blue", 400, 60);
    MonopolyBoard prop3("Baltic Avenue", "Brown", 60, 2);

    // Insert elements at the head, tail, and position
    list.insertAtHead(prop1);
    list.insertAtTail(prop2);
    list.insertAtPosition(prop3, 2);

    // Print the list
    cout << "Monopoly Board Properties:" << endl;
    list.printList();

    // Search for a property
    cout << "\nSearching for Park Place:" << endl;
    list.search(prop1);

    // Optional Tasks
    cout << "\nChecking if the list is empty:" << endl;
    list.isListEmpty();

    cout << "\nCounting nodes in the list:" << endl;
    list.countNodes();

    return 0;
}
