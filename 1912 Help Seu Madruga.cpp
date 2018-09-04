#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    while(cin >> n >> a && n){
        vector<int> v(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
        }
        if(a > sum){
            cout << "-.-\n";
        }else if(a == sum){
            cout << ":D\n";
        }else{
            double b = 0.0;
            double e = 10000.0;
            double mid;
            while(b <= e){
                mid = (b+e)/2.0;
                double cut = 0;
                for(int x: v){
                    if(x > mid){
                        cut += x-mid;
                    }
                }
                double thres = (a-cut);
                if(abs(thres) < 0.00005) break;
                if(cut < a){
                    e = mid;
                }else{
                    b = mid;
                }
            }
            cout << fixed << setprecision(4) << mid << endl;
        }
    }
    return 0;
}
