#include <bits/stdc++.h>

using namespace std;

int shortestPath(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < n; ++i) {
            if (graph[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                distance[i] = distance[current] + 1;
            }
        }
    }

    return distance[end];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    int shortest = shortestPath(graph, start - 1, end - 1);

    cout << shortest << endl;

    return 0;
}