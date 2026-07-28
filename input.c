//
// Created by Furgan Gurbanlli on 28.07.2026.
//
#include "input.h"
#include <stdio.h>

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