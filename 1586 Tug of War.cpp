#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int v[10005];

int strength(string s){
    int ret = 0;
    for(char c: s){
        ret += c;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n && n){
        vector<string> name(n);
        vector<ll> v(n);
        for(int i = 0; i < n; i++){
            cin >> name[i];
            int val = strength(name[i]);
            v[i] = val;
        }
        int b = 0, e = n-1,mid,ans = -1;
        while(b <= e){
            mid = (b+e)/2;
            ll l = 0,r = 0;
            for(int i = mid, j = 1; i >= 0; i--,j++){
                l += v[i]*j;
            }
            for(int i = mid+1, j = 1; i < n; i++,j++){
                r += v[i]*j;
            }
            if(l == r){
                ans = mid;
                break;
            }else if(l < r){
                b = mid+1;
            }else{
                e = mid-1;
            }
        }
        if(ans == -1){
            cout << "Impossibilidade de empate.\n";
        }else{
            cout << name[ans] << endl;
        }
    }
    return 0;
}
