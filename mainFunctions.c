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

int PrintUsers(User* head, int count) {
    int user = 0;

    if (count == 0) {
        printf("\nNo user added yet!");
        return user;
    }
    user = 1;

    printf("\n==== Total %d Users ====\n", count);

    User* current = head;

    while (current != NULL) {
        printf("\nName: %s, Age: %d\n\n", current->name, current->age);
        current = current->next;
    }
    return user;
}

void FreeList(User* head) {
    while (head != NULL) {
        User* temp = head;
        head = head->next;
        free(temp);
    }
}

void Menu(User** head, int* count, int adminPin) {
    while (1) {
        printf("Do you want to run program as an admin? (1/0): ");
        if (GetBoolInput()) {
            printf("Enter admin pin: ");
            int input = GetIntInput();
            if (input == adminPin) {
                AdminMenu(head,count);
            }
            printf("Pin is incorrect, running program as a guest...\n");
        }
        if (PrintUsers(*head, *count) == 0) {
            return;
        }

        int index = GetIntInput();
        char temp[100];
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);


        printf("\nEnter a username: ");
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';

        int age = 0;
        while (age < 10 || age > 100) {
            printf("\nUser's age has to be between 10 and 100\n");
            printf("\nEnter an age: ");
            age = GetIntInput();
        }

        Append(head, age, temp);
        (*count)++;
    }
}

void PrintMenu() {
    printf("1-)Add a user\n");
    printf("2-)Delete a user\n");
    printf("3-)Edit a user\n");
    printf("4-)User list\n");
    printf("\n\n0-)Close program\n");
}

void AdminMenu(User** head, int* count) {

    while (1) {
        PrintMenu();
        int option = GetIntInput();

        switch (option) {
            case 0:
                printf("\nClosing program...");
                FreeList(*head);
                exit(0);
            case 1:
                char temp[100];
                int age;
                AddUser(&age, temp);
                Append(head, age, temp);
                (*count)++;
                break;
            case 4:
                PrintUsers(*head, *count);
                break;
            default:
                printf("\nEnter a valid option!\n");
        }
    }
}

void AddUser(int* age,char* temp) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);


    printf("\nEnter a username: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';

    *age = 0;
    while (*age < 10 || *age > 100) {
        printf("\nUser's age has to be between 10 and 100\n");
        printf("\nEnter an age: ");
        *age = GetIntInput();
    }
}