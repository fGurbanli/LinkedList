#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct User {
    char name[100];
    int age;
    struct User* next;
}User;

bool GetBoolInput();
int GetIntInput();

void PrintUsers(User* head, int count);

void Append(User** head, int age, char name[100]);

int main(void) {
    User* head = NULL;
    int count = 0;

    while (1) {
        printf("Do you want to add a new user? (1/0)");
        if (!GetBoolInput()) {
            PrintUsers(head, count);
            exit(0);
        }
        char temp[100];

        printf("\nEnter a username: ");
        while (getchar() != '\n');
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';

        printf("\nEnter an age: ");
        int age = GetIntInput();

        Append(&head, age, temp);
        count++;
    }
}

bool GetBoolInput() {
    bool respond = 0;
    int input;

    while (1) {
        if (scanf("%d", &input) == 1 && input >=0 && input <= 1) {
            break;
        }
        printf("\nEnter a valid input!\n");
        while (getchar() != '\n');
    }
    if (input == 1) {
        respond = true;
    }
    return respond;
}

void Append(User** head, int age, char name[100]) {
    User* newUser = malloc(sizeof(User));

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

int GetIntInput() {
    int input;

    while (1) {
        if (scanf("%d", &input) == 1 && input >=0) {
            break;
        }
        printf("\nEnter a valid input!\n");
        while (getchar() != '\n');
    }
    return input;
}

void PrintUsers(User* head, int count) {

    if (count == 0) {
        printf("\nNo user added yet!");
        return;
    }

    printf("\n==== Total %d Users ====\n", count);

    User* current = head;

    while (current->next == NULL) {
        printf("\nName: %s, Age: %d\n\n", current->name, current->age);
        current = current->next;
    }
}