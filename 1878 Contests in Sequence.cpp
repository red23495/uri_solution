#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int a,int b){ return (a%b == 0)?b:gcd(b,a%b);}

struct triple{
    int a,b,c;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    ll arr[3];
    map<ll,vector<triple>> mp;
    while(cin >> n >> m){
        mp.clear();
        for(int i = 0; i < 3; i++) arr[i] = 0;
        for(int i = 0; i < n; i++) cin >> arr[i];
        bool stop = false;
        for(int i = 1; i <= m && !stop; i++){
            for(int j = 1; j <= m && !stop; j++){
                for(int k = 1; k <= m && !stop; k++){
                    ll c = i*arr[0]+j*arr[1]+k*arr[2];
                    mp[c].push_back({i,j,k});
                    if(mp[c].size() > 1){
                        for(int x = 0; x < mp[c].size() && !stop; x++){
                            for(int y = x+1; y < mp[c].size() && !stop; y++){
                                auto p = mp[c][x], q = mp[c][y];
                                //cout << p.a << ' ' << p.b << ' ' << p.c << endl;
                                //cout << q.a << ' ' << q.b << ' ' << q.c << endl;
                                bool exact = true;
                                if(n >= 1 && p.a != q.a) exact = false;
                                if(n >= 2 && p.b != q.b) exact = false;
                                if(n >= 3 && p.c != q.c) exact = false;
                                if(exact) break;
                                if(p.a == q.a && n >= 1) exact = true;
                                if(p.b == q.b && n >= 2) exact = true;
                                if(p.c == q.c && n >= 3) exact = true;
                                stop = !exact;
                            }
                        }
                    }
                }
            }
        }
        if(stop) cout << "Try again later, Denis...\n"; else cout << "Lucky Denis!\n";
    }
    return 0;
}
