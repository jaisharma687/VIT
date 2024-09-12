# include <stdio.h>
# include <string.h>
char expression[15];
int top = -1;
int tempvalue[10];

void push(char element){
    tempvalue[++top] = (int)element;
}

int pop(){
    return tempvalue[top--];
}

void display(){
    for(int i = 0; i<=top; i++){
        printf("%d",tempvalue[i]);
    }
}

int operate(int val1, int val2, char operator){
    int val;
    switch (operator){
        case '+':
            val = val1 + val2;
            break;
        case '-':
            val = val2 - val1;
            break;
        case '*':
            val = val1 * val2;
            break;
        case '/':
            val = val1 / val2;
            break;
        case '^':
            val = val1 ^ val2;
        default:
            break;
        }
    return val;    
}

int main(){
    scanf("%[^\n]%*c", expression);
    for(int i = 0; i< strlen(expression);i++){
        if(expression[i]>='0' && expression[i] <= '9'){
            push(expression[i]-'0');
        }
        else{
            int v1 = pop();
            int v2 = pop();
            int v3 = operate(v1,v2,expression[i]);
            push(v3);
        }
    }
    // printf("%d", top);
    display();
    return 0;
}