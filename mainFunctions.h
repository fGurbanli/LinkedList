//
// Created by Furgan Gurbanlli on 28.07.2026.
//

#ifndef LINKEDLIST_MAINFUNCTIONS_H
#define LINKEDLIST_MAINFUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct User {
    char name[100];
    int age;
    int pin;
    struct User* next;
}User;

int PrintUsers(User* head, int count);

void Append(User** head, int age, char name[100]);

void FreeList(User* head);

void Menu(User** head, int* count, int* adminPin);

void AdminMenu(User** head, int* count, int* adminPin);

void PrintMenu();

void AddUser(int* age,char* temp,int* pin,int count, int* adminPin);
#endif //LINKEDLIST_MAINFUNCTIONS_H