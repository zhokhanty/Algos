#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> field(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> field[i][j];
        }
    }

    queue<Point> marios;

    // Find initial positions of Mario(s)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 2) {
                marios.push({i, j});
            }
        }
    }

    int minutes = 0;

    while (!marios.empty()) {
        int size = marios.size();

        for (int i = 0; i < size; ++i) {
            Point curr = marios.front();
            marios.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nx = curr.x + dx[dir];
                int ny = curr.y + dy[dir];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && field[nx][ny] == 1) {
                    // Crush the mushroom
                    field[nx][ny] = 2;
                    marios.push({nx, ny});
                }
            }
        }

        if (!marios.empty()) {
            ++minutes;
        }
    }

    // Check for any remaining mushrooms
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << minutes << endl;

    return 0;
}