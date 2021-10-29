//Student's ID: 313357329
//Student's name: Danielle Agat Levi

#include <stdio.h>
#include <stdlib.h>
#include "settings.h"
#include "stdbool.h"
#include "list.h"

#define _CRT_SECURE_NO_WARNINGS
#define EOS '\0'
#define ENTER '\n'
#define END_OF_COMMAND(command) (command == EOS || command == ENTER)

void program();
void enter_new_command(char command, total_exp* expr);
bool is_expression_type(char ch);
bool is_whom_to_output(char ch);
void scan_operand(operand* oper);
void init_total_exp(total_exp* to_init);

int main() {
    program();
    return 0;
}

void program(){
    char* commands = (char*)malloc(sizeof(char)* MAX_COMMAND_LEN);
    total_exp expr={.exp=NULL,.print_or_eval=false,.is_new_exp=false,.whm_out=NONE,.is_last_exp=false};
    expr.exp = (exp*)malloc(sizeof(exp));
    List list;
    make_empty_list(&list);
    int x = 0;
    while(1){
        init_total_exp(&expr);
        fflush(stdin);
        scanf("%s",commands);
        for(int i = 0; i < MAX_COMMAND_LEN && !END_OF_COMMAND(commands[i]); i++){
            enter_new_command(commands[i], &expr);
        }
        fflush(stdout);

        //Scan operands:
        if(expr.is_new_exp) {
            fgetc(stdin);// remove '\n'
            scan_operand(&expr.exp->oper1);
            fgetc(stdin);// remove 'space'
            scan_operand(&expr.exp->oper2);
            add_exp_to_tail(&list, expr.exp);
        }else if(expr.exp->oper1.type == VAR_X){
            scanf("%d",&x); //Assuming input is valid (integer)
            print_exp(expr.exp, false, x);
        }
        if(expr.whm_out == ALL_EXP){
            print_list(&list, expr.print_or_eval, x);
        }else if(expr.whm_out == CURRENT){
            print_exp(expr.exp, expr.print_or_eval, x);
        }

        if(expr.is_last_exp){
            exit(0);
        }
    }
}

void scan_operand(operand* oper){
    int input=0;
    int num_of_scanned = scanf("%d", &input);
    oper->val=input;
    if (num_of_scanned == 0) { //Assuming input is valid (integer or 'X')
        fgetc(stdin);//to read X
        oper->type = VAR_X;
        oper->val = 0;
    } else {
        oper->type = VALUE;
    }
}

void init_total_exp(total_exp* to_init){
    to_init->print_or_eval = PRINT_F;
    if(to_init->is_new_exp){
        to_init->exp = (exp*)malloc(sizeof(exp));
    }
    to_init->is_new_exp = false;
    to_init->exp->type = BAD_EXP;
    to_init->exp->oper1.type = BAD_OPERAND;
    to_init->exp->oper2.type = BAD_OPERAND;
    to_init->exp->oper1.val = 0;
    to_init->exp->oper2.val = 0;
    to_init->whm_out = NONE;
}

void enter_new_command(char command, total_exp* expr){
    if(command == VAR_X){
        expr->exp->oper1.type = command;
    } else if(is_expression_type(command)){
        expr->exp->type = command;
    } else if(is_whom_to_output(command)){
        expr->whm_out = command;
    }else if(command == EXIT){
        expr->is_last_exp = true;
    }else if(command == NEW_EXP){
        expr->is_new_exp = true;
    }else if(command == PRINT){
        expr->print_or_eval = PRINT_F;
    }else if(command == EVAL){
        expr->print_or_eval = EVAL_F;
    }
}


bool is_expression_type(char ch){
    if(ch == ADD || ch == SUB || ch == MUL || ch == DIV)
        return true;
    return false;
}

bool is_whom_to_output(char ch){
    if(ch == CURRENT || ch == ALL_EXP)
        return true;
    return false;
}