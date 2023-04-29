#include "Classes.h"
#include "func.cpp"

int main() {
    Square s1(1.2, 1.3, 5, 45);
    Square s2(1.5, 1.6, 7, 45);
    std::cout << (s1 == s2) << '\n';
    std::cout << (s1 != s2) << '\n';
    std::cout << (s1 > s2) << '\n';
    std::cout << (s1 < s2) << '\n';
    s1 = s2 * 1.3;
    std::cout << s1.Get_Lenght() << '\n';
    s1 = s2 * 1.3;
    std::cout << s1.Get_Lenght() << '\n';
    s1 = s2 + std::make_pair(4.3, 2.6);
    std::cout << s2.Get_X() << ' ' << s2.Get_Y() << '\n';

    s1 = s2 + std::make_pair(1.7, 4.5);
    std::cout << s1.Get_X() << ' ' << s1.Get_Y() << '\n';
    /*
     * s1 = s1 + std::make_pair(2.6, 5.4);
    std::cout << s1.Get_X() << ' ' << s1.Get_Y() << '\n';
    */

    /*Array a1;
    Array a2;
    for (int i = 0; i < 5; i++) {
        a1.Set(i, i * i);
    }
    for (int i = 0; i < 4; i++) {
        a2.Set(i, i + 1);
    }
    a1.Print();
    a2.Print();
    a1 = a1 + a2;
    a1.Print();
    std::cout << (a1 == a2) << '\n';
    std::cout << (a1 != a2) << '\n';
    std::cout << (a1 > a2) << '\n';
    std::cout << (a1 < a2) << '\n';
     */
}
