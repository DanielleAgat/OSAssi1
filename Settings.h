//
// Created by Agat Levi on 22/10/2021.
//

#ifndef OSASSI1_SETTINGS_H
#define OSASSI1_SETTINGS_H
#define MAX_COMMAND_LEN 10
enum EXP_TYPE {
    ADD, SUB, MUL, DIV, BAD_EXP
};
enum OPERAND_TYPE {
    VALUE, VAR_X, BAD_OPERAND
};
enum WHOM_TO_OUTPUT {
    CURRENT, ALL_EXP, NONE
};
struct operand {
    enum OPERAND_TYPE type;
    int val; // value, valid if this is not a variable
};
struct exp { // binary expression
    enum EXP_TYPE type;
    struct operand oper1, oper2;
};
struct Node {
    struct exp *expr;
    struct Node *next;
};

#endif //OSASSI1_SETTINGS_H
