#include "mainFunctions.h"

int main(void) {
    FILE* userList = fopen("userList.txt", "a+");
    if (userList == NULL) {
        printf("\nFile couldn't be opened!\n");
        return 1;
    }

    int count = 0;

    rewind(userList);

    User* head = NULL;
    User* tail = NULL;

    rewind(userList);

    while (1)
    {
        User* newUser = malloc(sizeof(User));

        if (newUser == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(userList);
            return 1;
        }

        if (fscanf(userList," %99[^;];%d;%d;",newUser->name,&newUser->age,&newUser->pin) != 3)
        {
            free(newUser);
            break;
        }

        newUser->next = NULL;

        if (head == NULL)
        {
            head = newUser;
            tail = newUser;
        }
        else
        {
            tail->next = newUser;
            tail = newUser;
        }
        count++;
    }

    int adminPin = 0;

    Menu(&head,&count, &adminPin);
    fclose(userList);
}
