#include<bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int abs(int n) {return (n < 0)?-n:n; }

class c_list: public list<int>{
public:
    c_list(int n): list<int>(n){
        int cnt = 1;
        iterator it = begin();
        while(it != end()){
            *it = cnt++;
            it++;
        }
    }
    iterator next(iterator it);
    iterator prev(iterator it);
};

c_list::iterator c_list::next(c_list::iterator it){
    it++;
    if(it == end()) it = begin();
    return it;
}

c_list::iterator c_list::prev(c_list::iterator it){
    if(it == begin()) it = end();
    it--;
    return it;
}

int main(){
    int n,k,m;
    while(cin >> n >> k >> m && n){
        c_list lst(n);
        bool start = true;
        auto front = lst.begin();
        auto rear = --lst.end();
        while(lst.size() > 0){
            if(start) start = false;
            else cout << ',';
            if(lst.size() == 1){
                cout << setw(3) <<*lst.begin();
                break;
            }
            for(int i = 0; i < k - 1; i++){
                front = lst.next(front);
            }
            for(int i = 0; i < m - 1; i++){
                rear = lst.prev(rear);
            }
            int x,y;
            x = *front;
            y = *rear;
            front = lst.erase(front);
            if(front == lst.end()) front = lst.begin();
            if(rear == front) front = lst.next(front);
            if(x != y){
                rear = lst.erase(rear);
                rear = lst.prev(rear);
            }
            else {
                rear = lst.prev(front);
            }
            if(x == y){
                cout << setw(3) << x;
            }
            else cout << setw(3) << x << setw(3) << y;
        }
        cout << endl;
    }
    return 0;
}
