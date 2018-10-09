#define _USE_MATH_DEFINES
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int a,int b){ return (a%b == 0)?b:gcd(b,a%b);}

void sieve(int n, vector<int>& v){
    vector<bool> check(n);
    v.push_back(2);
    for(int i = 3; i*i <= n; i+=2){
        if(!check[i]){
            v.push_back(i);
            for(int j = i*i; j <= n; j+=i) check[j] = true;
        }
    }
    int x = sqrt(n)+1;
    if(x&1 == 0) x++;
    while(x <= n) {
        //cout << x << endl;
        if(!check[x]){
            v.push_back(x);
            //cout << x << endl;
        }
        x += 2;
    }
}

void segsieve(int n, vector<int>& v){
    int lim = sqrt(n);
    sieve(lim,v);
    int found = v.size();
    int b = lim+1, e = b+lim-1;
    while(b <= n){
        if(e > n) e = n;
        bool mark[lim+1];
        memset(mark,0,sizeof mark);
        for(int i = 0; i < found; i++){
            int start = (b/v[i])*v[i];
            if(start < b) start += v[i];
            for(int j = 0; start+v[i]*j <= e; j++){
                mark[start+v[i]*j-b] = true;
            }
        }
        for(int i = 0; i <= e-b; i++){
            if(mark[i] == false) v.push_back(b+i);
        }
        b = e+1;
        e = b+lim-1;
    }
}

int main(){
    vector<int> primes;
    segsieve(1e7,primes);
    int n;
    scanf("%d",&n);
    auto x = lower_bound(primes.begin(),primes.end(),n);
    int sum = 0;
    for(int i = 0; i < 10; i++){
        sum += *x;
        x++;
    }
    int h = 6e7/sum;
    int d = h/24;
    printf("%d km/h\n%d h / %d d\n",sum,h,d);
    return 0;
}
