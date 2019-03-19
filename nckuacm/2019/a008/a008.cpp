#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int const INF = 100000000;

char maze[1006][1006];
int visit_fire[1006][1006];
int visit_joe[1006][1006];

int const dii[] = {0, 0, -1, 1};
int const djj[] = {-1, 1, 0, 0};

queue<PII> Q;

void bfs_fire(PII start)
{
    Q.push(start);
    int i, j, di, dj;
    PII p;

    while(!Q.empty()) {
        p = Q.front(); Q.pop();
        i = p.first; j = p.second;
        for(int k=0; k<4; ++k) {
            di = dii[k]; dj = djj[k];
            if(visit_fire[i+di][j+dj] == INF && maze[i+di][j+dj] == '.') {
                visit_fire[i+di][j+dj] = visit_fire[i][j] + 1;
                Q.push(make_pair(i+di, j+dj));
            }
        }
    }
}

int bfs_joe(PII start)
{
    Q.push(start);
    int i, j, di, dj;
    PII p;

    while(!Q.empty()) {
        p = Q.front(); Q.pop();
        i = p.first; j = p.second;
        for(int k=0; k<4; ++k) {
            di = dii[k]; dj = djj[k];
            if(maze[i+di][j+dj]=='*') return visit_joe[i][j] + 1;
            else if(visit_fire[i+di][j+dj] <= visit_joe[i][j] + 1) continue;
            else if(visit_joe[i+di][j+dj] == INF && maze[i+di][j+dj] == '.') {
                visit_joe[i+di][j+dj] = visit_joe[i][j] + 1;
                Q.push(make_pair(i+di, j+dj));
            }
        }
    }

    return -1;
}

void init(int R, int C)
{
    while(!Q.empty()) Q.pop();
    for(int i=0; i<=R+1; ++i)
        for(int j=0; j<=C+1; ++j) {
            maze[i][j] = '*';
            visit_fire[i][j] = INF;
            visit_joe[i][j] = INF;
        }
}

void print_fire(int R, int C)
{
    for(int r=1; r<=R; ++r) {
        for(int c=1; c<=C; ++c) cout << visit_fire[r][c] << ' ';
        cout << endl;
    }
}

void print_joe(int R, int C)
{
    for(int r=1; r<=R; ++r) {
        for(int c=1; c<=C; ++c) cout << visit_joe[r][c] << ' ';
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int T, R, C, res;
    PII joe_start, fire_start;

    cin >> T;
    while(T--) {
        cin >> R >> C;
        init(R, C);
        for(int r=1; r<=R; ++r)
            for(int c=1; c<=C; ++c) {
                cin >> maze[r][c];
                if(maze[r][c] == 'J') {
                    visit_joe[r][c] = 0;
                    joe_start = make_pair(r, c);
                }
                if(maze[r][c] == 'F') {
                    visit_fire[r][c] = 0;
                    fire_start = make_pair(r, c);
                }
            }
        bfs_fire(fire_start);
        res = bfs_joe(joe_start);

        if(res < 0) cout << "IMPOSSIBLE" << endl;
        else cout << res << endl;
    }

    return 0;
}

