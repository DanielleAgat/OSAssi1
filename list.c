#include "list.h"

void make_empty_list(List* lst){
    lst->head = lst->tail = NULL;
}

void add_node_to_tail(List* list, node* toAdd) {
    if(list->head == NULL) { //Empty list
        list->head = list->tail = toAdd;
    }
    else if (list->head == list->tail){ //One node in list
        list->tail=toAdd;
        list->head->next = toAdd;
    }
    else {
        list->tail->next = toAdd;
        list->tail = toAdd;
    }
    list->tail->next = NULL;
}
void add_exp_to_tail(List* list, exp* to_add) {
    node * node_to_add= (node*) malloc(sizeof(node));
    node_to_add->expr=to_add;
    add_node_to_tail(list, node_to_add);
}

//display the list
void print_list(List* list, bool is_eval, int x) {
    node *ptr = list->head;
    //start from the beginning
    while (ptr != NULL) {
        print_exp(ptr->expr, is_eval, x);
        ptr = ptr->next;
    }
}
//is list empty
bool is_empty(List* list) {
    return list->head == NULL;
}
int length(List* list) {
    int length = 0;
    node *current;

    for (current = list->head; current != NULL; current = current->next) {
        length++;
    }

    return length;
}