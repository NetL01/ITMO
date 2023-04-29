#include <iostream>
using namespace std;

int main()
{
    int num;
    int x;
    int one, two;
    cin >> num;
    for (int i = 0; i < num; i++){
        cin >> one >> two;
        x = one + two;
        cout << x << endl;
    }
    return 0;
}