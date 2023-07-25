#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int bellmanFord(int n, int m, int src, int dest, int edges[][3]) {
    int dist[n + 1];
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != INT_MAX && (dist[u] + wt) < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    //LOOP FOR CHECKING IF NEGATIVE CYCLE EXITS(IF ITERATION 4TH AND 5TH ARE DIFFERENT THEN IT EXISTS)
    bool flag = false;
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != INT_MAX && (dist[u] + wt) < dist[v]) {
            flag = true;
            break;
        }
    }

    if (!flag) {
        return dist[dest];
    }
    return -1;
}

int main() {
    int n, m, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    int edges[m][3];
    printf("Enter the edges (start vertex, end vertex, weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    int shortestPath = bellmanFord(n, m, src, dest, edges);
    if (shortestPath == -1) {
        printf("Negative cycle detected. No shortest path exists.\n");
    } else {
        printf("Shortest path from source to destination: %d\n", shortestPath);
    }
    return 0;
}
