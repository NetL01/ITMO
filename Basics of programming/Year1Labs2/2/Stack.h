#ifndef header
#define header
#include <iostream>

class Stack {
public:
    Stack() = default;
    Stack(const Stack &Object);
    Stack(size_t max_size);
    ~Stack();

    size_t get_size();
    bool empty();
    void push(int x);
    void pop();
    int head();
    void print();
    void set_size(size_t size_);

    // Stack& operator+(const Stack &stack);

private:
    int *data;
    size_t size = 0;
    size_t capacity;
};

#endif //header