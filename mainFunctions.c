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

int PrintStudents(User* head, int count) {
    int user = 0;

    if (count == 0) {
        printf("\nNo student added yet!");
        return user;
    }
    user = 1;

    printf("\n==== Total %d Students ====\n", count);

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

void Menu(User** head, int* count, int* adminPin) {

    while (1) {

        if (*count == 0) {
            printf("There is no teacher added yet. Please create a teacher user.\n");

            AddTeacher(adminPin);
        }

        FindTeacherPin(adminPin);

        printf("Do you want to run program as an Teacher? (1/0): ");
        if (GetBoolInput()) {
            printf("Enter teacher pin: ");
            int input = GetIntInput();
            if (input == *adminPin) {
                AdminMenu(head,count);
            }
            printf("Teacher pin is incorrect, running program as a guest...\n");
        }
        printf("\nRunning program as a guest...\n");

        printf("1-) Student list\n");
        printf("\nEnter 0 to exit\n");

        while (1) {
            int option = GetBoolInput();

            switch (option) {
                case 0:
                    printf("\nClosing program...");
                    FreeList(*head);
                    exit(0);
                case 1:
                    PrintStudents(*head, *count);
            }
        }
    }
}

void PrintMenu() {
    printf("1-)Add a student\n");
    printf("2-)Delete a student\n");
    printf("3-)Edit a student\n");
    printf("4-)Student list\n");
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
                int pin;
                AddStudent(&age, temp,sizeof(temp),&pin);
                Append(head, age, temp);
                (*count)++;
                break;
            case 4:
                PrintStudents(*head, *count);
                break;
            default:
                printf("\nEnter a valid option!\n");
        }
    }
}

void AddStudent(int* age,char temp[100],size_t size,int* pin) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);


    printf("\nEnter a student name: ");
    fgets(temp, size, stdin);
    temp[strcspn(temp, "\n")] = '\0';

    *age = 0;
    while (*age < 10 || *age > 100) {
        printf("\nStudent's age has to be between 10 and 100\n");
        printf("\nEnter an age: ");
        *age = GetIntInput();
    }

    printf("Enter a student pin: ");
    *pin = GetIntInput();

    FILE* userList = fopen("userList.txt", "a");

    if (userList == NULL) {
        printf("\nFile couldn't be opened\n");
        return;
    }

    fprintf(userList,"%s;%d;%d;\n", temp, *age, *pin);

    fclose(userList);
}

void AddTeacher(int* adminPin) {
    char temp[100];
    int age = 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);


    printf("\nEnter a name of teacher: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';

    while (age < 10 || age > 100) {
        printf("\nTeacher's age has to be between 20 and 100\n");
        printf("\nEnter an age: ");
        age = GetIntInput();
    }

    printf("Enter an teacher pin: ");
    int pin = GetIntInput();
    *adminPin = pin;

    FILE* userList = fopen("userList.txt", "a");

    if (userList == NULL) {
        printf("\nFile couldn't be opened\n");
        return;
    }

    fprintf(userList,"%s;%d;%d;\n", temp, age, pin);

    fclose(userList);
}

void FindTeacherPin(int* adminPin) {
    int pin;
    char temp[100];
    int temp2 = 0;
    FILE* userList = fopen("userList.txt", "r");

    if (userList == NULL) {
        printf("\nFile couldn't be opened!");
        return;
    }

    rewind(userList);

    fscanf(userList," %99[^;];%d;%d;",temp,&temp2,&pin);

    *adminPin = pin;

}