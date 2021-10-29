//Student's ID: 313357329
//Student's name: Danielle Agat Levi
#ifndef OSASSI1_LIST_H
#define OSASSI1_LIST_H
#include "settings.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listExp{
    node *head;
    node *tail;
}List;


bool is_empty(List* list);
void add_node_to_tail(List* list, node* toAdd);
void add_exp_to_tail(List* list, exp* to_add);
void make_empty_list(List* lst);
int length(List* list);
void print_list(List* list, bool is_eval, int x);

#endif
