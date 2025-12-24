# Monopoly_board
# Monopoly Board Game (Circular Linked List)

This project is a simple C++ implementation of a Monopoly-style property board using a circular linked list data structure. It demonstrates how to build and traverse a circular linked list of `MonopolyBoard` objects that store property information such as name, color, value, and rent. [file:2]

## Features

- `MonopolyBoard` class to represent individual Monopoly properties (name, color, value, rent). [file:2]  
- Template `Node<T>` class used as the building block of the circular linked list. [file:2]  
- Template `CircularLinkedList<T>` class supporting:
  - Insert at head, tail, and any position
  - Delete at head, tail, and any position
  - Search for a property using an `isEqual` comparison
  - Printing all properties in the list
  - Utility methods: check if list is empty, print head/last node, count nodes (optional methods like `reverseCLList` and `sortCLList` are stubbed). [file:2]

## Project structure

- `Monopoly_Board.cpp`  
  Contains:
  - `MonopolyBoard` class definition and methods (`isEqual`, `print`)  
  - Template definitions for `Node<T>` and `CircularLinkedList<T>`  
  - `main()` function that:
    - Creates several `MonopolyBoard` objects
    - Inserts them into a `CircularLinkedList<MonopolyBoard>`
    - Prints the list and searches for a property
    - Checks if the list is empty and counts nodes. [file:2]



