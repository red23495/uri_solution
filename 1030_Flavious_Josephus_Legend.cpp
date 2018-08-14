#include<bits/stdc++.h>

using namespace std;
typedef unsigned int ui;

int mod(int n, int m){
    return (n<0)?(n%m)+m:(n%m);
}

int jos(int start, int total, int gap){
    if(total == 1) return 0;
    int dead = ((start+gap-1)%total);
    if(total == 2) return mod(dead+1,2);
    int ret = jos(mod(dead,total-1),total-1,gap);
    if(dead <= ret) ret++;
    return ret;
}


int main(){
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        int n,k;
        cin >> n >> k;
        int ans = jos(0,n,k)+1;
        cout << "Case "<< t <<": " << ans << endl ;
    }
    return 0;
}
