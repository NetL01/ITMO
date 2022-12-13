#include <vector>
#include <iostream>

int num;

int main() {
    int left, right;
    std::cin >> num;
    std::vector<std::vector<int>> tree(num, std::vector<int>(3));
    std::vector<int> h(num + 1);
    for (int i = 0; i < num; ++i) {
        std::cin >> tree[i][0] >> tree[i][1] >> tree[i][2];
    }
    for (int i = num; i > 0; i--) {
        left = tree[i - 1][1];
        right = tree[i - 1][2];
        h[i] = 1 + std::max(h[left], h[right]);
    }
    for (int i = 0; i < num; i++)
        std::cout << h[tree[i][2]] - h[tree[i][1]] << "\n";
}