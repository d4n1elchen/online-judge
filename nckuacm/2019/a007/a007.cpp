#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

char maze[105][105];

void dfs(int i, int j)
{
    if(maze[i][j]=='*') return;
    maze[i][j] = '*';

    for(int di=-1; di<=1; ++di)
        for(int dj=-1; dj<=1; ++dj)
            if(maze[i+di][j+dj] == '@')
                dfs(i+di, j+dj);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int m, n, cnt;

    while(cin >> m >> n) {
        if(m==0) break;

        cnt = 0;
        memset(maze, 0, sizeof(maze));

        for(int i=1; i<=m; ++i)
            for(int j=1; j<=n; ++j)
                cin >> maze[i][j];

        for(int i=1; i<=m; ++i)
            for(int j=1; j<=n; ++j)
                if(maze[i][j] == '@') {
                    dfs(i, j);
                    ++cnt;
                }

        cout << cnt << endl;
    }

    return 0;
}

