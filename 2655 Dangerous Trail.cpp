#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class segment_tree{
private:
    vector<ll> v;
    int N;
    int left(int n) {return (n << 1); }
    int right(int n) {return (n << 1) + 1; }
    ll build(vector<int>& vp, int p, int L, int R){
        if(L == R) return v[p] = (1LL << vp[L-1]);
        ll x = build(vp,left(p),L,(L+R)/2);
        ll y = build(vp,right(p),(L+R)/2+1,R);
        return v[p] = (x|y);
    }
    ll update(int p, int L, int R, int i , int n){
        if(L == R && L == i) return v[p] = (1LL << n);
        if(L > i || R < i) return v[p];
        ll x = update(left(p),L,(L+R)/2,i,n);
        ll y = update(right(p),(L+R)/2+1,R,i,n);
        return v[p] = (x|y);
    }
    ll query(int p, int L , int R, int i, int j){
        if(i > R || j < L) return 0LL;
        if(L >= i && R <= j) return v[p];
        ll x = query(left(p),L,(L+R)/2,i,j);
        ll y = query(right(p),(L+R)/2+1,R,i,j);
        return (x|y);
    }
public:
    segment_tree(vector<int>& vp){
        N = vp.size();
        v.resize(4*N);
        build(vp,1,1,N);
    }
    void update(int i, int n){
        update(1,1,N,i,n);
    }
    ll query(int i, int j){
        return query(1,1,N,i,j);
    }
};

int main(){
    int n,q,m;
    scanf("%d%d%d",&n,&q,&m);
    vector<int> v;
    while(n--){
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    segment_tree seg(v);
    int comm,i,j;
    ll ans,ans2;
    while(q--){
        scanf("%d%d%d",&comm,&i,&j);
        switch(comm){
        case 1:
            ans = seg.query(i,j);
            ans2 = (ans >> 32);
            printf("%d\n",__builtin_popcount(ans)+__builtin_popcount(ans2));
            break;
        case 2:
            seg.update(i,j);
            break;
        }
    }
    return 0;
}
