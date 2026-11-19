#include <ctype.h>
#include <stdlib.h>
#include<string.h>
int MAX = 100000;
int STACK[100000], TOP;

void PUSH(int num) {

    if (TOP >= MAX - 1) {
        printf("STACK OVERFLOW");
        return;
    }
    TOP += 1;
    STACK[TOP] = num;
}

int POP() {
    if (TOP <= -1) {
        printf("STACK UNDERFLOW");
        return -1;

    } else {
        int n = STACK[TOP--];
        return n;
    }
}

int isNumber(char* c) {
    int is=1;
    if(strlen(c)==1){
        return isdigit(c[0]);
    }
    for (int j = 0; c[j] != '\0'; j++) {
        if(c[j]=='+'||c[0]=='-')
            continue;
        if(!isdigit(c[j])){
            is=0;
            break;
        }

    }
    return is;
}

int evalRPN(char** tokens, int tokensSize) {
    TOP = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* c = tokens[i];
       

        if (isNumber(c)) {
            PUSH(atoi(c));

        }

        else if (*c == '+' || *c == '/' || *c == '*' || *c == '-') {
                int b = POP();
                int a = POP();
                int result;
                switch (*c) {
                case '+':
                    result= a + b;
                    break;
                case '-':
                    result=  a - b;
                    break;
                case '*':
                    result=  a * b;
                    break;
                case '/':
                if(b!=0)
                    result=  a / b;
                    break;
                }

             
                PUSH(result);
    
            }
    }

    
    return POP();
}