#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int precedence(char op){
    switch(op){
        case'+':
        case'-':
            return 1;
        case'*':
        case'/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}     
char* convertInfixToPostfix(char* infixExp){
    int len = strlen(infixExp), top = -1, x = 0;
    char *postfix = (char*) malloc(len+1);
    char operator[len];
    for(int i=0; i<len; i++){
        char ch = infixExp[i];
        if(isalnum(ch)){
            postfix[x++] = ch;
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            while(top != -1 && precedence(ch)<=precedence(operator[top]) && ch != '^'){
                postfix[x++] = operator[top--];

            }
            operator[++top] = ch;

        }
        else if(ch=='('){
            operator[++top] = ch;
        }
        else if(ch==')'){
            while(operator[top] != '('){
                postfix[x++] = operator[top--];
            }
            top--;                 
        }
    }
    while(top != -1){
        postfix[x++] = operator[top--];
    }
    postfix[x] = '\0';
    return postfix;

} 
char* convertPostfixToInfix(char* postfixExp){
    char stack[100][100];
    int len = strlen(postfixExp), top = -1;
    for(int i=0; i<len; i++){
        char ch = postfixExp[i];
        if(isalnum(ch)){
            char str[] = {ch, '\0'};
            strcpy(stack[++top], str);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            char *s1 = stack[top--];
            char *s2 = stack[top--];
            char s3[100] = "";
            sprintf(s3, "(%s%c%s)", s2,ch,s1);
            strcpy(stack[++top], s3);
        }
    }
    char *infix = (char*)malloc(strlen(stack[top])+1);
    strcpy(infix, stack[top--]);
    return infix;
}
int main(){
    char expr[100];
    printf("Enter Infix Expression: ");
    gets(expr);
    printf("Postfix expression = %s\n", convertInfixToPostfix(expr));

    printf("Enter Postfix Expression: ");
    gets(expr);
    printf("Infix expression = %s\n", convertPostfixToInfix(expr));

    
    return 0;
}
