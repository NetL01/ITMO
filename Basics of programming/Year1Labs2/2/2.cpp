#include "Stack.h"

Stack::Stack(const Stack &Object) {
    this->data = new int[Object.capacity];
    for (size_t i = 0; i < Object.size; i++) {
        this->push(Object.data[i]);
    }
}

Stack::Stack(size_t max_size) {
    this->capacity = max_size;
    this->data = new int[max_size];
};

Stack::~Stack() {
    delete[] this->data;
}

size_t Stack::get_size() {
    return this->size;
}

bool Stack::empty() {
    return this->size == 0;
}

void Stack::push(int x) {
    if (this->size == this->capacity) {
        std::cout << "Size limit" << std::endl;
        return;
    }
    this->data[this->size] = x;
    this->size++;
}

void Stack::pop() {
    if (this->size == 0) {
        std::cout << "Stack is empty now!";
        return;
    }
    this->size--;
}

void Stack::print() {
    for (size_t i = 0; i < this->size; i++) {
        std::cout << this->data[i] << ' ';
    }
    std::cout << '\n';
}

int Stack::head() {
    return this->data[this->size - 1];
}

void Stack::set_size(size_t size_) {
    this->capacity = size_;
}
