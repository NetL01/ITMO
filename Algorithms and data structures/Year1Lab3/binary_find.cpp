#include <iostream>
#include <vector>
using namespace std;

int binary_find_left(int list_one[], int num, int length){
    int low = 0;
    int high = length - 1;
    int mid;
    /* cout << "high: " << high << endl; */
    while (low + 1 < high) {
        mid = (low + high) / 2;
        /* cout << "mid: " << mid << endl; */
        if (list_one[mid] < num) {
            low = mid;
        }
        else if (list_one[mid] >= num) {
            high = mid;
        }}
    if (list_one[low] == num){
        return low+1;
    }
    else if (list_one[high] == num) {
        return high+1;
    }
    return -1;





}

int binary_find_right(int list_one[], int num, int length){
    int low = 0;
    int high = length - 1;
    int mid;
    while (low + 1 < high) {
        /* cout << "otladka!!! ATTENTION!!! UVAGA!!! AHTUNG!!!" << low << high << endl; */
        mid = (low + high) / 2;
        if (list_one[mid] <= num) {
            low = mid;
        }
        else {
            high = mid;
        }}
    if (list_one[high] == num) {
        return high+1;
    }
    /* else if (list_one[low+1] == num) return low+2; */
    else if (list_one[low] == num) {
        return low + 1;
    }
    return -1;

}

int main() {
    int n;
    cin >> n;
    int list_one[n];
    for (int i = 0; i < n; i++) {
        int num_list_one;
        cin >> num_list_one;
        list_one[i] = num_list_one;
    }

    /* for(auto ans1: list_one) cout << ans1 << '\n'; */
    int num_of_finds;
    cin >> num_of_finds;
    int list_two[num_of_finds];
    for (int j = 0;j < num_of_finds; j++){
        int num_list_two;
        cin >> num_list_two;
        list_two[j] = num_list_two;
    }

    /* for(auto ans2: list_two) cout << ans2 << '\n'; */

    for(auto elem: list_two){
        cout << binary_find_left(list_one, elem, n) << ' ' << binary_find_right(list_one, elem, n) << endl;
    }
    return 0;
    }