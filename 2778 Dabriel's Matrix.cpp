#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 10000000
#define EMP 90000000
#define NONE 0
#define UP 1
#define DOWN 2
int N,M,X,Y;
vector<vector<int>> v;
int mem[101][101][21][21][3];
int dp(int i, int j, int x, int y, int dir){
    if(mem[i][j][x][y][dir] != EMP) return mem[i][j][x][y][dir];
    if(i == N-1 && j == M-1) return v[i][j];
    if(i >= N || j >= M || j < 0) return INF;
    if(v[i][j] == 0 && x <= 0) return INF;
    if(v[i][j] < 0 && y <= 0) return INF;
    int a = INF, b = INF, c = INF, ret = INF;
    int cx = x, cy = y;
    if(v[i][j] == 0) cx--;
    if(v[i][j] < 0) cy--;
    ret = dp(i+1,j,cx,cy,NONE);
    a = (ret == INF)?INF:v[i][j]+ret;
    if(dir != DOWN && j > 0) {
        ret = dp(i,j-1,cx,cy,UP);
        b = (ret == INF)?INF:v[i][j]+ret;
    }
    if(dir != UP && j < M-1) {
        ret = dp(i,j+1,cx,cy,DOWN);
        c = (ret == INF)?INF:v[i][j]+ret;
    }
    mem[i][j][x][y][dir] = min(a,min(b,c));
    return mem[i][j][x][y][dir];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> N >> M >> X >> Y){
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                for(int x = 0; x < 21; x++){
                    for(int y = 0; y < 21; y++){
                        for(int dir = 0; dir < 3; dir++){
                            mem[i][j][x][y][dir] = EMP;
                        }
                    }
                }
            }
        }
        v.clear();
        v.resize(N,vector<int>(M));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin  >> v[i][j];
            }
        }
        int ans =  dp(0,0,X,Y,NONE);
        if(ans != INF) cout << ans << endl;
        else cout << "Impossivel\n";
    }
    return 0;
}
