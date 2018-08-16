#include<bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int abs(int n) {return (n < 0)?-n:n; }

// for each value of i rock no i^2 is accesible
// and from each alternate rock among(0,lower_limit] and [i^2,upper_limit] is also reachable
// moreover expansion of range is faster the growth of i^2
// lower_limit = i^2 - 2i + 1
// upper_limit = i^2 + 2 * floor(lower_limit/2)
// we have to find a point where the upper limit of two consecutive values of i overlaps each other
// and also also all the values among (0,lower_limit] is reachable
// that point is 7. (6 and 7 barely overlaps) so any value of m > 34 (lower_limit of 7) is reachable


int main(){
    int a, b;
    while(cin >> a >> b && a){
        bool found = false;
        if(b > 34) found = true;
        queue<pair<int,int>> q;
        q.push({1,1});
        while(!found && !q.empty()){
            auto p = q.front();
            q.pop();
            int v = p.first, w = p.second;
            //cout << v << ' ' << w << endl;
            if(v == b) {
                found = true;
                break;
            }
            int d = 2*(w+1) - 1;
            if(v-d > 0) q.push({v-d,w+1});
            if(v+d <= a) q.push({v+d,w+1});
        }
        if(found) cout << "Let me try!\n";
        else cout << "Don't make fun of me!\n";
    }
    return 0;
}
