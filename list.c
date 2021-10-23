//
// Created by Agat Levi on 22/10/2021.
//

#include "list.h"

void addNodeToTail(node* toAdd) {
    if(head == NULL) { //Empty list
        head = tail = toAdd;
    }
    else if (head == tail){ //One node in list
        tail=toAdd;
        head->next = toAdd;
    }
    else {
        tail->next = toAdd;
        tail = toAdd;
    }
    tail->next = NULL;
}
void addExpToTail(exp* toAdd) {
    node * nodeToAdd= (node*) malloc(sizeof(node));
    nodeToAdd->expr=toAdd;
    addNodeToTail(nodeToAdd);
}

//display the list
void printList() {
    node *ptr = head;
    printf("\n[ ");
    //start from the beginning
    while (ptr != NULL) {
        printf("(%d) ", ptr->expr);
        //TODO: printExp(ptr->expr);
        ptr = ptr->next;
    }
    printf(" ]");
}
//is list empty
bool isEmpty() {
    return head == NULL;
}
int length() {
    int length = 0;
    node *current;

    for (current = head; current != NULL; current = current->next) {
        length++;
    }

    return length;
}