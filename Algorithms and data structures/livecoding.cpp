#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 1000;
const int MAXK = 20;

int dist[MAXN][MAXN][MAXK + 1];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // Инициализируем массив расстояний
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l <= k; l++) {
                if (i == j) {
                    dist[i][j][l] = 0;
                } else {
                    dist[i][j][l] = INT_MAX;
                }
            }
        }
    }

    // Считываем связи между временными пространствами
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        dist[a][b][0] = min(dist[a][b][0], w);
    }

    // Вычисляем расстояния через промежуточные временные пространства
    for (int l = 1; l <= k; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int p = 0; p < n; p++) {
                    dist[i][j][l] = min(dist[i][j][l], dist[i][p][l - 1] + dist[p][j][0]);
                }
            }
        }
    }

    // Обрабатываем запросы
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int ans = INT_MAX;
        for (int l = 0; l <= k; l++) {
            ans = min(ans, dist[a][b][l]);
        }
        if (ans == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}