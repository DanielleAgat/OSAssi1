//Student's ID: 313357329
//Student's name: Danielle Agat Levi
#include "Settings.h"

void print_exp(exp* expression, bool should_eval, int x){
    if(expression->type != BAD_EXP){ //New expression with 2 operands
        print_good_expression(expression);
        if(should_eval){
            int value = evaluate(expression,x);
            printf(" = %d", value);
        }
    } else { //BAD_EXP means N command wasn't entered, X was entered
        printf("X = %d", x);
    }

    printf("\n");
}

void print_good_expression(exp* expression){
    if(expression->oper1.type == VALUE){
        printf("%d ",expression->oper1.val);
    }else {
        printf("X ");
    }

    printf("%c", get_oper(expression->type));
    if(expression->oper2.type == VALUE){
        printf(" %d", expression->oper2.val);
    } else {
        printf(" X");
    }
}

int evaluate(exp* expression, int x){
    int value;
    int operand1 = (expression->oper1.type != VAR_X) ? expression->oper1.val : x;
    int operand2 = (expression->oper2.type != VAR_X) ? expression->oper2.val : x;

    switch(expression->type){
        case ADD:
            value = operand1 + operand2;
            break;
        case SUB:
            value = operand1 - operand2;
            break;
        case MUL:
            value = operand1 * operand2;
            break;
        case DIV:
            value = operand1 / operand2;
            break;
    }
    return value;
}

char get_oper(enum EXP_TYPE type){
    char oper;
    switch (type) {
        case ADD:
            oper = '+';
            break;
        case SUB:
            oper = '-';
            break;
        case MUL:
            oper = '*';
            break;
        case DIV:
            oper = '/';
            break;
        default:
            printf("Bad command!\nThe assumption is that the command is valid!"
                   "\nHence not handling the command!\nByeBye!");
            exit(1);
    }
    return oper;
}