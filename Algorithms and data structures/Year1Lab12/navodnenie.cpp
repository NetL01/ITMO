#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100;
const int INF = 1e9;

int n, m, q;
bool used[MAXN][MAXN];
int match[MAXN * MAXN];
vector<int> g[MAXN * MAXN];

bool try_kuhn(int v, vector<bool>& visited) {
    if (visited[v]) {
        return false;
    }
    visited[v] = true;
    for (int u : g[v]) {
        if (match[u] == -1 || try_kuhn(match[u], visited)) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

int max_matching() {
    memset(match, -1, sizeof(match));
    int matching = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] && (i + j) % 2 == 0) {
                vector<bool> visited(n * m, false);
                if (try_kuhn(i * m + j, visited)) {
                    matching++;
                }
            }
        }
    }
    return matching;
}

bool can_place_domino(int i, int j) {
    if (j < m - 1 && !used[i][j] && !used[i][j + 1]) {
        return true;
    }
    if (i < n - 1 && !used[i][j] && !used[i + 1][j]) {
        return true;
    }
    return false;
}

void add_edge(int i, int j, int ni, int nj) {
    g[i * m + j].push_back(ni * m + nj);
    g[ni * m + nj].push_back(i * m + j);
}

void build_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] && (i + j) % 2 == 0) {
                if (can_place_domino(i, j + 1)) {
                    add_edge(i, j, i, j + 1);
                }
                if (can_place_domino(i + 1, j)) {
                    add_edge(i, j, i + 1, j);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        used[x - 1][y - 1] = true;
    }
    build_graph();
    int matching = max_matching();
    int uncovered = n * m - q - matching;
    int covered = (n * m - q - uncovered) / 2;
    cout << covered << endl;
    return 0;
}