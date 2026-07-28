//
// Created by Furgan Gurbanlli on 28.07.2026.
//

#include "mainFunctions.h"
#include "input.h"

void Append(User** head, int age, char name[100]) {
    User* newUser = malloc(sizeof(User));
    if (newUser == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newUser->age = age;
    strcpy(newUser->name, name);
    newUser->next = NULL;

    if (*head == NULL) {
        *head = newUser;
        return;
    }

    User* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next  = newUser;
}

void PrintUsers(User* head, int count) {

    if (count == 0) {
        printf("\nNo user added yet!");
        return;
    }

    printf("\n==== Total %d Users ====\n", count);

    User* current = head;

    while (current != NULL) {
        printf("\nName: %s, Age: %d\n\n", current->name, current->age);
        current = current->next;
    }
}

void FreeList(User* head) {
    while (head != NULL) {
        User* temp = head;
        head = head->next;
        free(temp);
    }
}

void Menu(User** head, int* count) {
    *count = 0;

    while (1) {
        printf("Do you want to add a new user? (1/0): ");
        if (!GetBoolInput()) {
            PrintUsers(*head, *count);
            FreeList(*head);
            exit(0);
        }
        char temp[100];

        printf("\nEnter a username: ");
        while (getchar() != '\n');
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';

        printf("\nEnter an age: ");
        int age = GetIntInput();

        Append(head, age, temp);
        count++;
    }
}