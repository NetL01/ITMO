#include <string>
#include <iostream>
#include <vector>
using namespace std;



string answer = "NO";
void route(vector<vector<int>> &Graph, vector<string> &mark, int start, int parent) {
    mark[start - 1] = "grey";

    for (int i = 0; i < Graph[start - 1].size(); i++) {
        if (mark[Graph[start - 1][i] - 1] == "white") {
            route(Graph, mark, Graph[start - 1][i], start);
        }
        if (mark[Graph[start - 1][i] - 1] == "grey" && parent - 1 != Graph[start - 1][i] - 1) {
            answer = "YES";
            return;
        }
    }
    mark[start - 1] = "black";
}

void DFS(vector<vector<int>> &Graph, vector<string> &colors) {
    for (int i = 0; i < Graph.size(); i++) {
        if (colors[i] == "white") {
            route(Graph, colors, i + 1, i + 1);
        }
    }
}

int main() {
    int N,M;
    cin >> N >> M;

    vector<string> colors(N, "white");

    vector<vector<int>> Graph(N);


    for (int i = 0; i < M; i++) {
        int ONE, TWO;
        cin >> ONE >> TWO;

        Graph[ONE - 1].push_back(TWO);
        Graph[TWO - 1].push_back(ONE);
    }

    DFS(Graph, colors);
    cout << answer;
    return 0;
}