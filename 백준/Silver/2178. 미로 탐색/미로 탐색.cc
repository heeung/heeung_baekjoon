#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

#define X first
#define Y second

char board[102][102];
int dist[102][102];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
        scanf("%d %d", &n, &m);
        for (int i = 0 ; i < n ; i++)
                scanf("%s", board[i]);
        for (int i = 0 ; i < n ; i++)
                fill(dist[i], dist[i] + m, -1);
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        dist[0][0] = 0;
        while (!Q.empty())
        {
                auto cur = Q.front(); Q.pop();
                for (int dir = 0 ; dir < 4 ; dir++)
                {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                                continue ;
                        if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
                                continue ;
                        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        Q.push({nx, ny});
                }
        }
        printf("%d\n", dist[n - 1][m - 1] + 1);
}