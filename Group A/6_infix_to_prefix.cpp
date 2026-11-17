#include <iostream>
#include <cstring>
#include <algorithm>
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
    char exp[100], rev[100], post[100];
    int k = 0;

    cout << "Enter infix expression: ";
    cin >> exp;

    int n = strlen(exp);

    for (int i = 0; i < n; i++) {
        rev[i] = exp[n - 1 - i];
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }
    rev[n] = '\0';

    for (int i = 0; i < n; i++) {
        char x = rev[i];

        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) {
            post[k++] = x;
        } else if (x == '(') {
            push(x);
        } else if (x == ')') {
            while (top != -1 && st[top] != '(')
                post[k++] = pop();
            pop();
        } else {
            while (top != -1 && priority(st[top]) > priority(x))
                post[k++] = pop();
            push(x);
        }
    }

    while (top != -1)
        post[k++] = pop();

    post[k] = '\0';
    reverse(post, post + strlen(post));

    cout << "Prefix: " << post << endl;
    return 0;
}
