# Linked List User Management in C

A simple User Management System written in C using a **Singly Linked List**. This project demonstrates dynamic memory allocation, pointers, structs, and linked list operations without using arrays to store users.

## Features

- Add new users dynamically
- Store user name and age
- Print all users
- Dynamic memory allocation using `malloc()`
- Memory cleanup using `free()`
- Input validation for integer and boolean inputs

## Technologies

- C (C17)
- Standard C Library
    - stdio.h
    - stdlib.h
    - string.h
    - stdbool.h

## Project Structure

```
.
├── main.c
└── README.md
```

## Data Structure

```c
typedef struct User {
    char name[100];
    int age;
    struct User* next;
} User;
```

Each node stores:

- User name
- User age
- Pointer to the next node

Example:

```
Head
 ↓
+-------------+      +-------------+      +-------------+
| Alice | 21  | ---> | Bob | 19    | ---> | John | 25   | ---> NULL
+-------------+      +-------------+      +-------------+
```

## Implemented Functions

### Append()

Adds a new user to the end of the linked list.

### PrintUsers()

Traverses the linked list and prints every user.

### FreeList()

Frees every allocated node before the program exits to prevent memory leaks.

### GetIntInput()

Validates integer input.

### GetBoolInput()

Accepts only **0** or **1** as valid input.

## Example

```
Do you want to add a new user? (1/0): 1

Enter a username:
Alice

Enter an age:
21

Do you want to add a new user? (1/0): 1

Enter a username:
Bob

Enter an age:
19

Do you want to add a new user? (1/0): 0

==== Total 2 Users ====

Name: Alice
Age : 21

Name: Bob
Age : 19
```

## Concepts Practiced

- Structures
- Self-referencing Structures
- Pointers
- Pointer to Pointer (`User**`)
- Dynamic Memory Allocation
- Memory Management
- Linked Lists
- Traversing a Linked List
- Function Decomposition
- Input Validation

## Future Improvements

- Delete a user
- Search by name
- Edit user information
- Insert at a specific position
- Save users to a file
- Load users from a file
- Sort users by name or age
- Doubly Linked List implementation

## Learning Outcome

This project was created to strengthen my understanding of:

- Dynamic memory allocation
- Self-referencing structures
- Pointer manipulation
- Singly Linked Lists
- Writing modular and maintainable C code

---

**Author:** Furgan Gurbanli

This project is part of my journey to master the C programming language and prepare for Embedded Systems and IoT development.