#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Users {
    char name[100];
    int age;
    struct Node* next;
}User;
bool GetBoolInput();

int main(void) {
    printf("Do you want to add a new user? (1/0)");
    if (!GetBoolInput()) return 0;



    return 0;
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