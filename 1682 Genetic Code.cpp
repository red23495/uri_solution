#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

char arr[3] = {'N','O','P'};

bool match(string& ts, int s1, int e1, int s2, int e2){
    int i = 0;
    while(s1+i <= e1){
        if(ts[e1-i] != ts[e2-i]) return false;
        i++;
    }
    return true;
}

bool is_thue(string& ts){
    int s1 = ts.length()-1,e1 = ts.length()-1 ,s2 , e2 ;
    s2 = s1-1, e2 = e1 - 1;
    while(s2 >= 0){
        bool r = match(ts,s1,e1,s2,e2);
        if(r) return false;
        s1--;
        e2 = s1-1;
        s2 = e2 - (e1-s1);
        //cout << s2 << ' ' << e2 << endl;
    }
    return true;
}


bool code(int n, string& s){
    if(n > 5000) return true;
    for(int i = 0; i < 3; i++){
        s.push_back(arr[i]);
        if(is_thue(s)) {
            bool ret = code(n+1,s);
            if(ret) return true;
        }
        s.pop_back();
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    s.reserve(5005);
    code(0,s);
    int n;
    while(cin >> n && n){
        for(int i = 0; i < n; i++) cout << s[i];
        cout << endl;
    }
    return 0;
}
