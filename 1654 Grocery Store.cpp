#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 1; i <= 500; i++){
        for(ll j = i; j <= (2000 - i)/3; j++){
            for(int k = j; k <= (2000 - i - j)/2; k++){
                ll h = 1000000*(i+j+k);
                ll l = i*j*k-1000000;
                if(l <= 0 || h%l != 0) continue;
                int oth = (h/l);
                if((i+j+k+oth) > 2000 || oth < k) continue;
                cout << fixed << setprecision(2) << i/100.0 << ' ' << j /100.0 << ' ' << k/100.0 << ' ' << oth/100.0 << endl;
            }
        }
    }
    return 0;
}
