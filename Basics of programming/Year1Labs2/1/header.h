#pragma once
#include <cmath>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/*
 * 1, 6, 9, 14
 */
void three(int *first, int *second);
void three(int &first, int &second);

void round_pointer(float *first);
void round_link(float &first);

void change_radius_pointer(int *radius, int *number);
void change_radius_link(int &radius, int &number);

void transp(vector<vector<int>> *matrix);
void transp(vector<vector<int>> &matrix);

