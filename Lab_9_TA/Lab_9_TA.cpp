#include <iostream>
#include <Windows.h>
const int N = 20; 

struct Deque {
    int d[N];
    int s = 0;       
    int start = 0;   
    int end = 0;     

    void push_front(int n) {
        if (s == N) {
            std::cout << "Дека заповнена";
        }
        else {
            if (s == 0) { 
                d[start] = n;
            }
            else if (start == 0) {
                start = N - 1;
                d[start] = n;
            }
            else {
                d[--start] = n;
            }
            s++;
        }
    }

    void push_back(int n) {
        if (s == N) {
            std::cout << "Дека заповнена";
        }
        else {
            if (s == 0) { 
                d[end] = n;
            }
            else if (end == N - 1) {
                end = 0;
                d[end] = n;
            }
            else {
                d[++end] = n;
            }
            s++;
        }
    }

    int pop_front() {
        if (s == 0) return -1;
        int result = d[start];
        start = (start + 1) % N;
        s--;
        return result;
    }

    int pop_back() {
        if (s == 0) return -1;
        int result = d[end];
        end = (end == 0) ? N - 1 : end - 1;
        s--;
        return result;
    }

    int front() {
        return (s == 0) ? -1 : d[start];
    }

    int back() {
        return (s == 0) ? -1 : d[end];
    }

    int size() {
        return s;
    }

    void clear() {
        s = 0;
        start = end = 0;
    }

    void merge(Deque& other) {
        while (other.s > 0 && s < N) {
            push_back(other.pop_front());
        }
    }

    void print() {
        for (int i = 0, idx = start; i < s; i++, idx = (idx + 1) % N) {
            std::cout << d[idx] << " ";
        }
        std::cout << "\n";
    }
};



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Deque deque;

    deque.push_back(10);
    deque.push_back(20);
    deque.push_front(5);

    std::cout << "Дек після додавання елементів ";
    deque.print();

    std::cout << "Перший елемент " << deque.front() << "\n";
    std::cout << "Останній елемент " << deque.back() << "\n";

    deque.pop_front();
    deque.pop_back();

    std::cout << "Дек після видалення елементів ";
    deque.print();

    std::cout << "Розмір дека " << deque.size() << "\n";
    deque.clear();
    std::cout << "Дек очищено Розмір після очищення " << deque.size() << "\n";
    
    Deque deque1, deque2;
    for (int i = 0; i <= 5; i++) {
        deque1.push_back(i);
    }
    for (int i = 0; i <= 5; i++) {
        deque2.push_back(i*2);
    }
    std::cout << "Дека 1: ";
    deque1.print();
    std::cout << "Дека 2: ";
    deque2.print();

    deque1.merge(deque2);

    std::cout << "Об'єднаний дек: ";
    deque1.print();

    return 0;
}
