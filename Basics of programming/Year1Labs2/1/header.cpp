#include "header.h"
using namespace std;
void three(int *first, int *two) {
    if (first > two) {
        *first = *first % *two;
    } else {
        *two = *two % *first;
    }
}
void three(int &first, int &two) {
    if (first > two) {
        first = first % two;
    } else {
        two = two % first;
    }
}
void round_pointer(float *first) {
    *first = round(*first);
}
void round_link(float &first) {
    first = round(first);
}
void change_radius_pointer(int *radius, int *number) {
    *radius = *radius - *number;
}
void change_radius_link(int &radius, int &number) {
    radius = radius - number;
}
void transp(vector<vector<int>> *matrix) {
    int t;
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < 3; ++j) {
            t = (*matrix)[i][j];
            (*matrix)[i][j] = (*matrix)[j][i];
            (*matrix)[j][i] = t;
        }
    }
}
void transp(vector<vector<int>> &matrix) {
    int t;
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
}
