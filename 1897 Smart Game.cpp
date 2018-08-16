#include<bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int abs(int n) {return (n < 0)?-n:n; }

int op[6][3] = {{2,1,0},
                {3,1,0},
                {1,2,0},
                {1,3,0},
                {1,1,7},
                {1,1,-7}};
int a,b;

// solution: bfs
int main(){
    cin >> a >> b;
    queue<pair<int,int>> q;
    unordered_set<int> us;
    q.push({a,0});
    us.insert(a);
    int ans = 0;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int v = p.first, w = p.second;
        if(v == b){
            ans = w;
            break;
        }
        for(int i = 0; i < 6; i++){
            int t = (v*op[i][0])/op[i][1] + op[i][2];
            if(!us.count(t)){
                q.push({t,w+1});
                us.insert(t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
