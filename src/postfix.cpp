// Copyright 2021 Alexey Tatsenko
#include<iostream>
#include"MyStack.h"
#include"postfix.h"
#include<string>

std::string infix2postfix(std::string str) {
    std::string str_;
    MyStack<char> stack(str.size());

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') continue;

        if (str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
            str_ += str[i];
            if ((str[i]) !=  '.' && (str[i + 1]) != '.') str_ += ' ';
            continue;
        }

        if (str[i] == '(' || change(str[i]) > change(stack.get()) || stack.isEmpty()) {

            stack.push(str[i]);
            continue;
        }

        if (change(stack.get()) >= change(str[i]) && str[i] != ')') {
            str_ += stack.pop();
            stack.push(str[i]);
            str_ += ' ';
            continue;
        }

        if (change(str[i]) == 1) {

            while (stack.get() != '(') {
                str_ += stack.pop();
                str_ += ' ';
            }
            stack.pop();
            continue;
        }
    }

    if (stack.isEmpty() == 0) {

        while (stack.isEmpty() != 1) {
            str_ += stack.pop();
            str_ += ' ';
        }

    }
    str_.resize(str_.size() - 1);

    return str_;
}

int change(char symb) {
    switch (symb) {
    case '(':
        return 0;
        break;
    case ')':
        return 1;
        break;
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 3;
        break;
    default:
        return 4;
    }
}
