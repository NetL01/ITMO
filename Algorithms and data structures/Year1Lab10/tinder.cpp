#include<bits/stdc++.h>
#include <iostream>

using namespace std;
void topsort(vector<vector<int>> &array, vector<bool> &colors, vector<int> &res, int start) {
    colors[start] = true;
    for (int i = 0; i < array[start].size(); i++) {
        if (!colors[array[start][i]]) {
            topsort(array, colors, res, array[start][i]);
        }
    }
    res.push_back(start);
}

void dfs(vector<vector<int>> &array, vector<bool> &colors, vector<int> &answer, int start, int connecting_comps) {
    colors[start] = true;

    for (int i = 0; i < array[start].size(); i++) {
        if (!colors[array[start][i]]) {
            dfs(array, colors, answer, array[start][i], connecting_comps);
        }
    }
    answer[start] = connecting_comps;
}

void func() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> np1(n);
    vector<vector<int>> np2(n);

    for (int i = 0; i < m; i++) {
        int first, second;
        cin >> first >> second;

        np1[first - 1].push_back(second - 1);
        np2[second - 1].push_back(first - 1);
    }

    vector<bool> visited(n, false);
    vector<int> sort_array;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) topsort(np1, visited, sort_array, i);
    }

    std::reverse(sort_array.begin(), sort_array.end());

    vector<bool> parent1(n, false);
    vector<int> answer(n, -1);

    int connecting_comps = 1;

    for (int i = 0; i < n; i++) {
        if (!parent1[sort_array[i]]) {
            dfs(np2, parent1, answer, sort_array[i], connecting_comps);
            connecting_comps++;
        }
    }

    while (q > 0) {
        q--;
        int first, second;
        cin >> first >> second;
        first--;
        second--;
        if ( answer[first] == answer[second] ) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}

int main() {
    func();

    return 0;
}