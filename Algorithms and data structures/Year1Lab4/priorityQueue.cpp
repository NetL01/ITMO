#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::swap;

void Sift_Down(std::vector<int> &array, std::vector<int> &num_of_elem, int i) {
    int lowest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < array.size() && array[left] < array[lowest]) {
        lowest = left;
    }
    if (right < array.size() && array[right] < array[lowest]) {
        lowest = right;
    }
    if (lowest != i) {
        swap(array[i], array[lowest]);
        swap(num_of_elem[i], num_of_elem[lowest]);
        Sift_Down(array, num_of_elem, lowest);
    }
}

void Sift_Up(std::vector<int> &array, std::vector<int> &num_of_elem, int position) {
    while ((position - 1) / 2 >= 0 && array[position] < array[(position - 1) / 2]) {
        swap(array[position], array[(position - 1) / 2]);
        swap(num_of_elem[position], num_of_elem[(position - 1) / 2]);
        position = (position - 1) / 2;
    }
}

int Extract_Min(std::vector<int> &array, std::vector<int> &num_of_elem) {
    int min = array[0];
    array[0] = array[array.size() - 1];
    num_of_elem[0] = num_of_elem[num_of_elem.size() - 1];
    array.pop_back();
    num_of_elem.pop_back();
    Sift_Down(array, num_of_elem, 0);
    return min;
}

void Insert(std::vector<int> &array, std::vector<int> &num_of_elem, int num_of_str, int elem) {
    array.push_back(elem);
    num_of_elem.push_back(num_of_str);
    Sift_Up(array, num_of_elem, array.size() - 1);
}

int main() {
    std::vector<int> array;
    std::vector<int> num_of_elem;
    std::string string;

    int count = 1;

    while (std::cin >> string) {
        if (string == "push") {
            int num;
            cin >> num;
            Insert(array, num_of_elem, count, num);
        }
        if (string == "extract-min") {
            if (!array.empty()) {
                cout << Extract_Min(array, num_of_elem) << "\n";
            }
            else {
                cout << '*' << "\n";
            }
        }
        if (string == "decrease-key") {
            int num_str, num;
            cin >> num_str >> num;

            for (int i = 0; i < num_of_elem.size(); i++) {
                if (num_of_elem[i] == num_str) {
                    array[i] = num;
                    Sift_Up(array, num_of_elem, i);
                    break;
                }
            }
        }
        count++;
    }

    return 0;
}