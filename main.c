#include "mainFunctions.h"

int main(void) {
    FILE* userList = fopen("userList.txt", "a+");
    if (userList == NULL) {
        printf("\nFile couldn't be opened\n");
        return 1;
    }

    char line[100];

    int count = 0;

    rewind(userList);

    User* head = NULL;

    int adminPin = 1911;

    Menu(&head,&count, &adminPin);
    fclose(userList);
}
