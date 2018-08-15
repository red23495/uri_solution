#include<bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int abs(int n) {return (n < 0)?-n:n; }


int main(){
    int n;
    while(cin >> n && n){
        stack<pair<ull,ull>> st;
        st.push({0,0});
        ull cur = 0;
        ull _max = 0;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(x > st.top().first){
                st.push({x,i});
            }
            else{
                int last = i;
                while(st.top().first > x){
                    auto t = st.top();
                    st.pop();
                    ull cur = t.first * (i - t.second);
                    _max = max(cur,_max);
                    last = t.second;
                    //cout << t.first << ' ' << t.second << ' ' << i << endl;
                }
                st.push({x,last});
                st.push({x,i});
            }
        }
        while(!st.empty()){
            auto t = st.top();
            st.pop();
            ull cur = t.first * (n + 1 - t.second);
            _max = max(cur,_max);
            //cout << t.first << ' ' << t.second << ' ' << n << endl;
        }
        cout << _max << endl;
    }
    return 0;
}
