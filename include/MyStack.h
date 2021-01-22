// Copyright 2021 Alexey Tatsenko
#pragma once
#include<iostream>
template <class T>
class MyStack {
 private:
    T *array;
    int pos;
    int size;

 public:
    explicit MyStack(int n) {
        pos = -1;
        size = n;
        array = new T[n];
    }
    MyStack(const MyStack& n) {
        array = n.array;
        size = n.size;
    }
    ~MyStack() {
        if (array != nullptr)
            delete[] array;
    }
    T get() const {
        return array[pos];
    }
    T pop() {
        T kr = array[pos];
        T * mas1 = new T[size];
        for (int i = 0; i < pos;  i++) {
            mas1[i] = array[i];
        }
        pos = pos - 1;
        array = nullptr;
        array = mas1;
        return kr;
    }
    void push(T n) {
        if (pos == -1) {
            array[0] = n;
            pos = 0;
        } else if (pos == size - 1) {
            std::cout << "error";
        } else {
            pos++;
            array[pos] = n;
            /* for (int i = 0; i < size; i++) std::cout << array[i] << ' ';
            std::cout << std::endl; */
           }
    }

    bool isFull() const {
        return pos == size - 1;
    }
    bool isEmpty() const {
        return pos == -1;
    }
};
