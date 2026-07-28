# Linked List User Manager (C)

A console-based **User Management System** written in C using a **singly linked list**. This project was developed to strengthen my understanding of pointers, dynamic memory allocation, linked lists, modular programming, and manual memory management.

---

## Features

* Add users dynamically
* Store users in a singly linked list
* Display all stored users
* Dynamic memory allocation using `malloc()`
* Proper memory cleanup using `free()`
* Input validation for integers and boolean values
* Modular project structure using separate source and header files

---

## Project Structure

```text
.
├── main.c
├── mainFunctions.c
├── mainFunctions.h
├── input.c
├── input.h
└── README.md
```

### File Descriptions

| File              | Description                                      |
| ----------------- | ------------------------------------------------ |
| `main.c`          | Entry point of the application.                  |
| `mainFunctions.c` | Contains the menu and linked list operations.    |
| `mainFunctions.h` | Structure definitions and function declarations. |
| `input.c`         | Input validation helper functions.               |
| `input.h`         | Declarations for input validation functions.     |

---

## Concepts Practiced

* Structures (`struct`)
* Pointers
* Pointer to pointer (`User **head`)
* Dynamic memory allocation (`malloc`, `free`)
* Singly linked lists
* Linked list traversal
* Modular programming
* Header files
* Function decomposition
* Input validation
* Manual memory management

---

## Example Output

```text
Do you want to add a new user? (1/0): 1

Enter a username: Alice

Enter an age: 22

Do you want to add a new user? (1/0): 1

Enter a username: Bob

Enter an age: 27

Do you want to add a new user? (1/0): 0

==== Total 2 Users ====

Name: Alice, Age: 22

Name: Bob, Age: 27
```

---

## Memory Management

Every user is stored as a dynamically allocated node.

* Memory is allocated with `malloc()` when a new user is created.
* Every allocated node is released with `free()` before the program exits.

This prevents memory leaks and reinforces good memory management practices in C.

---

## Future Improvements

* Delete a user
* Search for a user
* Edit user information
* Save users to a file
* Load users from a file
* Sort users alphabetically or by age
* More advanced menu system
* Doubly linked list implementation

---

## What I Learned

This project helped me gain practical experience with:

* Building and traversing linked lists
* Working with pointers and pointer-to-pointer parameters
* Managing dynamic memory safely
* Separating a C project into multiple source and header files
* Designing reusable functions
* Organizing code into a cleaner and more maintainable structure

---

## Build

Compile with GCC:

```bash
gcc main.c mainFunctions.c input.c -o LinkedList
```

Run:

```bash
./LinkedList
```

---

## Author

**Furkan Gurbanli**

Engineering Student • Learning C Programming • Interested in Embedded Systems & IoT

GitHub: **https://github.com/fGurbanli**
