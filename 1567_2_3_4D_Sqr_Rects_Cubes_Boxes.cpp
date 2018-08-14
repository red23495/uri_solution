#include<bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int abs(int n) {return (n < 0)?-n:n; }

ull p2[101];
ull p3[101];
ull p4[101];

// formula:
// total combination = (1+2+3+....+n)^dimension
// total unit combination = 1^dimension + 2^dimension + ..... + n^dimension

int main(){
    for(int i = 1; i <= 100; i++){
        p2[i] = p2[i-1]+i*i;
        p3[i] = p3[i-1]+i*i*i;
        p4[i] = p4[i-1]+i*i*i*i;
    }
    ull n;
    while(cin >> n){
        ull s = ((n+1)*n)/2;
        ull ss = s * s;
        ull a = ss - p2[n];
        cout << p2[n] << ' ' << a << ' ';
        ss *= s;
        a = ss - p3[n];
        cout << p3[n] << ' ' << a << ' ';
        ss *= s;
        a = ss - p4[n];
        cout << p4[n] << ' ' << a << endl;
    }
    return 0;
}
