#include<bits/stdc++.h>
using namespace std;

bool isOperator(char op) {
    return op == '+' || op == '-' ||
           op == '*' || op == '%' ||
           op == '/' || op == '^';
}

int compute(int left, int right, char op) {
    int value;
    switch(op) {
        case '+': value = left + right; break;
        case '-': value = left - right; break;
        case '*': value = left * right; break;
        case '%': value = left % right; break;
        case '/': value = left / right; break;
        case '^': value = pow(left, right); break;
    }
    return value;
}

int expr_eval(string expr) {
    int left, right, ans;
    char ch;
    stack<int> stk;
    for(int i = 0; i < expr.length(); i++) {
        ch = expr[i];
        if(isdigit(ch)) stk.push(ch - '0');
        else if(isOperator(ch)) {
            left = stk.top();
            stk.pop();
            right = stk.top();
            stk.pop();
            ans = compute(left, right, ch);
            stk.push(ans);
        } else cout << "Expression is not correct" << endl;
    }
    return stk.top();
}

int main() {
    int result = expr_eval("711-2*3+");
    cout << result;
    return 0;
}