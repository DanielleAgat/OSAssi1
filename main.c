#include <stdio.h>
#include <stdlib.h>
#include "Settings.h"
#include "stdbool.h"

void program();
void enterNewCommand(char command, totalExp* expr);
bool isExpressionType(char ch);
bool isShouldPrintOrEval(char ch);
bool isOperandType(char ch);
void initTotalExp(totalExp* toInit);

int main() {

    program();
    return 0;
}

void program(){
    char commands[MAX_COMMAND_LEN];
    totalExp expr;
    while(1){
        initTotalExp(&expr);
        scanf("%s", commands);
        for(int i = 0; i < MAX_COMMAND_LEN && commands[i] != EOF; i++){
            enterNewCommand(commands[i], &expr);
        }

        //TODO: Scan operands
        //TODO: Process commands
        if(expr.printOrEval == EVAL_F){
            //TODO: evaluate expression
        }

        //TODO: Print expression
        if(expr.isLastExp){
            exit(0);
        }
    }
}

void initTotalExp(totalExp* toInit){
    totalExp expr;
    expr.printOrEval = PRINT_F;
    expr.isNewExp = false;
    expr.exp.type = BAD_EXP;
    expr.exp.oper1.type = BAD_OPERAND;
    expr.exp.oper2.type = BAD_OPERAND;
    expr.exp.oper1.val = 0;
    expr.exp.oper2.val = 0;
    expr.whmOut = NONE;
    *toInit = expr;
}

void enterNewCommand(char command, totalExp* expr){
    if(isOperandType(command)){
        if(expr->exp.oper1.type != BAD_OPERAND){
            expr->exp.oper1.type = command;
        }else{
            expr->exp.oper2.type = command;
        }
    } else if(isExpressionType(command)){
        expr->exp.type = command;
    } else if(isShouldPrintOrEval(command)){
        expr->whmOut = command;
    }else if(command == EXIT){
        expr->isLastExp = true;
    }else if(command == NEW_EXP){
        expr->isNewExp = true;
    }else if(command == PRINT){
        expr->printOrEval = PRINT_F;
    }else if(command == EVAL){
        expr->printOrEval = EVAL_F;
    }else {
        printf("Bad command!\nThe assumption is that the command is valid!"
               "\nHence not handling the command!\nByeBye!");
        exit(1);
    }
}


bool isExpressionType(char ch){
    if(ch == ADD || ch == SUB || ch == MUL || ch == DIV)
        return true;
    return false;
}

bool isOperandType(char ch){
    if(ch == VALUE || ch == VAR_X)
        return true;
    return false;
}

bool isShouldPrintOrEval(char ch){
    if(ch == PRINT || ch == EVAL)
        return true;
    return false;
}