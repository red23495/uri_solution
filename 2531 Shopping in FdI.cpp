#include<bits/stdc++.h>

using namespace std;

struct node{
    int min;
    int max;
};

class segment_tree{
private:
    vector<node> v;
    int N;
    int left(int n){ return n << 1; }
    int right(int n) { return (n << 1) + 1; }
    node build(vector<int>& vp, int p, int L, int R){
        if(L==R && L==0) return v[0] = {INT_MAX,INT_MIN};
        if(L == R) return v[p] = {vp[L],vp[L]};
        auto x = build(vp,left(p),L,(L+R)/2);
        auto y = build(vp,right(p),(L+R)/2+1,R);
        v[p].min = min(x.min,y.min);
        v[p].max = max(x.max,y.max);
        return v[p];
    }
    node update(int p, int L, int R, int i, int val){
        if(i > R || i < L) return v[p];
        if(L == R && L == i) return v[p] = {val,val};
        auto x = update(left(p),L,(L+R)/2,i,val);
        auto y = update(right(p),(L+R)/2+1,R,i,val);
        v[p].min = min(x.min,y.min);
        v[p].max = max(x.max,y.max);
        return v[p];
    }
    node query(int p, int L, int R, int i, int j){
        //cout << p << ' ' << L << ' ' << R << ' ' << i << ' ' << j << endl;
        if(i > R || j < L) return {INT_MAX,INT_MIN};
        if(L >= i && R <= j) return v[p];
        auto x = query(left(p),L,(L+R)/2,i,j);
        auto y = query(right(p),(L+R)/2+1,R,i,j);
        node temp;
        temp.min = min(x.min,y.min);
        temp.max = max(x.max,y.max);
        return temp;
    }
public:
    segment_tree(vector<int>& vp){
        N = vp.size()-1;
        v.resize(4*N+1);
        build(vp,1,0,N);
        /*for(auto x: v){
            cout << "(" << x.min << "," << x.max << "),";
        }
        cout << endl;*/
        //cout << N << endl;
    }
    void update(int i, int val){
        update(1,0,N,i,val);
    }
    node query(int i, int j){
        //cout << N << endl;
        return query(1,0,N,i,j);
    }
};

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        vector<int> v;
        v.push_back(0);
        int x;
        while(n--){
            scanf("%d",&x); v.push_back(x);
        }
        segment_tree seg(v);
        int q;
        scanf("%d",&q);
        while(q--){
            int com,i,j;
            scanf("%d%d%d",&com,&i,&j);
            switch(com){
            case 1:
                seg.update(i,j);
                break;
            case 2:
                auto x = seg.query(i,j);
                printf("%d\n",x.max-x.min);
                break;
            }
        }
    }
    return 0;
}
