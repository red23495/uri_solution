#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct card {
    int a,d,s;
    card(int x, int y, int z){a = x; d = y; s = z;}
    void operator += (card rhs){
        a += rhs.a; d += rhs.d; s += rhs.s;
    }
    bool operator == (card rhs){
        return (a == rhs.a && s == rhs.s && d == rhs.d);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,d,s;;
    cin >> n >> a >> d >> s;
    card ms(a,d,s);
    vector<card> v;
    for(int i = 0; i < n; i++){
        cin >> a >> d >> s;
        v.push_back(card(a,d,s));
    }
    bool ans = false;
    for(int i = 3; i < (1 << n); i++){
        if(__builtin_popcount(i) == 1) continue;
        card t(0,0,0);
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                t += v[j];
            }
        }
        if(t == ms) {
            ans = true;
            break;
        }
    }
    if(ans) cout << "Y\n";
    else cout << "N\n";
    return 0;
}
