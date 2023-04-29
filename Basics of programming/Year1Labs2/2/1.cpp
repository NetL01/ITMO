#include "Stack.h"

int main() {
    std::cout << "Choose your stack size\n";
    size_t size;
    std::cin >> size;
    Stack s(size);

    while (1) {
        std::cout << "Is empty - 1" << std::endl;
        std::cout << "Add elem - 2" << std::endl;
        std::cout << "Del last - 3" << std::endl;
        std::cout << "Print last - 4" << std::endl;
        std::cout << "Print all stack - 5" << std::endl;
        std::cout << "Resize stack - 6" << std::endl;
        std::cout << "Print stack size - 7" << std::endl;

        size_t n;
        std::cin >> n;

        if(n == 1){
            if(s.empty()) std::cout << "Stack is empty\n";
            else std::cout << "Stack is not empty\n";
        }

        if(n == 2){
            std::cout << "Enter a value" << std::endl;
            int value;
            std::cin >> value;
            s.push(value);
        }

        if(n == 3){
            s.pop();
        }

        if(n == 4){
            std::cout << s.head() << std::endl;
        }

        if(n == 5){
            s.print();
        }

        if(n == 6){
            std::cout << "Enter new stack size: \n";
            size_t value;
            std::cin >> value;
            s.set_size(value);
        }

        if(n == 7){
            std::cout << s.get_size() << std::endl;
        }

        std::cout << "\n\n\n";
    }

}