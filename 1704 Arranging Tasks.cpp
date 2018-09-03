#include<bits/stdc++.h>

using namespace std;

struct task {
    int v; int t;
    bool operator < (task rhs) const{
        return (v > rhs.v);
    }
};

// activity selection problem (job scheduling)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,h;
    while(cin >> n >> h){
        vector<task> v;
        while(n--){
            int t,vi;
            cin >> vi >> t;
            task ts;
            ts.t =t; ts.v = vi;
            v.push_back(ts);
        }
        sort(v.begin(),v.end());
        vector<bool> slot(h+1,false);
        slot[0] = true;
        int cost = 0;
        for(int i = 0; i < v.size(); i++){
            //cout << "(" << v[i].v << ' ' << v[i].t << ") ";
            bool found = false;
            for(int j = v[i].t; j > 0 && !found ; j--){
                if(!slot[j]){
                    slot[j] = true;
                    found = true;
                }
            }
            if(!found){
                cost += v[i].v;
            }
        }
        cout << cost << endl;
    }
    return 0;
}
