//
// Created by Agat Levi on 22/10/2021.
//

#ifndef OSASSI1_LIST_H
#define OSASSI1_LIST_H
#include "Settings.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

node *head = NULL;
node *tail = NULL;
node *current = NULL;

bool isEmpty();
void addNodeToTail(node* toAdd);
void addExpToTail(exp* toAdd);

int length();
void printList();

#endif //OSASSI1_LIST_H
