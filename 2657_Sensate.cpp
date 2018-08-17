#include<bits/stdc++.h>

using namespace std;

class union_find{
private:
    vector<pair<int,pair<int,int>>> v;
public:
    union_find(vector<int> n){
        v.resize(n.size());
        for(int i = 0; i < n.size(); i++){
            v[i] = {i,{n[i],1}};
        }
    }
    pair<int,pair<int,int>> parent(int n){
        if(v[n].first == n) return v[n];
        return v[n] = parent(v[n].first);
    }
    void combine(int a, int b){
        auto pa = parent(a), pb = parent(b);
        if(rand()&1){
            v[pa.first].first = pb.first;
            v[pb.first].second.first = max(pa.second.first,pb.second.first);
            v[pb.first].second.second += pa.second.second;
        }else{
            v[pb.first].first = pa.first;
            v[pa.first].second.first = max(pa.second.first,pb.second.first);
            v[pa.first].second.second += pb.second.second;
        }
        /*cout << a << ' ' << b << endl;
        for(int i = 0; i < v.size(); i++){
            cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << endl;
        }
        cout << endl;*/
    }
    bool isSame(int a, int b){
        return parent(a).first == parent(b).first;
    }
};

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    map<string,int> people;
    vector<int> rank;
    rank.clear();
    rank.resize(n);
    int p_in = 0;
    while(n--){
        string s; int rnk;
        cin >> s >> rnk;
        people[s] = p_in;
        rank[p_in++] = rnk;
    }
    union_find un(rank);
    while(m--){
        string s1,s2;
        cin >> s1 >> s2;
        un.combine(people[s1],people[s2]);
    }
    while(q--){
        string s;
        cin >> s;
        int in = people[s];
        auto p = un.parent(in);
        //cout << rank[in] << ' ' << p.second.second << ' ' << p.second.first << endl;
        if(rank[in] >= 5 || p.second.second == 1 || p.second.first <= 5) cout << "S\n";
        else cout << "N\n";
    }
    return 0;
}
