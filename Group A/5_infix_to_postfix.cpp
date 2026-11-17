#include <iostream>
#include <cstring>
using namespace std;

char st[100];
int top = -1;

void push(char x) {
    st[++top] = x;
}

char pop() {
    return st[top--];
}

int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int main() {
    char exp[100], post[100];
    int k = 0;

    cout << "Enter infix expression: ";
    cin >> exp;

    for (int i = 0; i < strlen(exp); i++) {
        char x = exp[i];

        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) {
            post[k++] = x;
        } else if (x == '(') {
            push(x);
        } else if (x == ')') {
            while (top != -1 && st[top] != '(')
                post[k++] = pop();
            pop();
        } else {
            while (top != -1 && priority(st[top]) >= priority(x))
                post[k++] = pop();
            push(x);
        }
    }

    while (top != -1)
        post[k++] = pop();

    post[k] = '\0';
    cout << "Postfix: " << post << endl;

    return 0;
}
