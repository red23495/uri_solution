#include<bits/stdc++.h>

using namespace std;

int v[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    int n,q;
    while(cin >> n >> q && n){
        cout << "CASE# " << test << ":\n";
        test++;
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v,v+n);
        while(q--){
            int x;
            cin >> x;
            int b = 0, e = n-1, mid;
            while(b <= e){
                mid = (b+e)/2;
                if(v[mid] >= x){
                    e = mid-1;
                }
                else{
                    b = mid+1;
                }
            }
            if(v[b] == x){
                cout << x << " found at " << b+1 << endl;
            }else{
                cout << x << " not found\n";
            }
        }
    }
    return 0;
}
