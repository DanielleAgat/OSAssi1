//
// Created by Agat Levi on 22/10/2021.
//

#ifndef OSASSI1_SETTINGS_H
#define OSASSI1_SETTINGS_H
#include "stdbool.h"

#define MAX_COMMAND_LEN 10
#define EXIT 'L'
#define NEW_EXP 'N'
#define PRINT 'P'
#define EVAL 'E'

#define PRINT_F false
#define EVAL_F true

enum EXP_TYPE {
    ADD = 'A', SUB = 'S', MUL = 'M', DIV = 'D', BAD_EXP
};

enum OPERAND_TYPE {
    VALUE = 'V', VAR_X = 'X', BAD_OPERAND
};

enum WHOM_TO_OUTPUT {
    CURRENT = 'C', ALL_EXP = 'T', NONE
};

typedef struct operand {
    enum OPERAND_TYPE type;
    int val; // value, valid if this is not a variable
}operand;

typedef struct exp { // binary expression
    enum EXP_TYPE type;
    operand oper1, oper2;
}exp;

typedef struct node {
    exp *expr;
    struct node *next;
}node;

typedef struct totalExp{
    exp exp;
    enum WHOM_TO_OUTPUT whmOut;
    bool printOrEval;
    bool isLastExp;
    bool isNewExp;
}totalExp;

#endif //OSASSI1_SETTINGS_H