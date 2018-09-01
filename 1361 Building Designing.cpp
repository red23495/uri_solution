#include<bits/stdc++.h>

using namespace std;

int abs(int n) {return (n < 0)?-n:n; }

struct flr {
    int val;
    int color;
    flr(int n){
        val = abs(n);
        color = n/abs(n);
    }
    flr(){}
    bool operator < (const flr rhs) const {
        return val < rhs.val;
    }
};

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<flr> v(n);
        while(n--){
            int x;
            cin >> x;
            v[n] = flr(x);
        }
        sort(v.begin(),v.end());
        int clr = 1;
        int max1 = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i].color == clr){
                max1++;
                clr *= -1;
            }
        }
        clr = -1;
        int max2 = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i].color == clr){
                max2++;
                clr *= -1;
            }
        }
        cout << max(max1,max2) << endl;
    }
    return 0;
}
