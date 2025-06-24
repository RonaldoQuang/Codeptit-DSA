#include <bits/stdc++.h>
using namespace std;
void Try(){
    int n; cin >> n;
    string s;
    int x;
    queue<int> q;
    while(n--){
        cin >> s;
        if(s=="PUSH"){
            cin >> x;
            q.push(x);
        }
        else if(s=="POP"){
            if(!q.empty()){
                q.pop();
            }
        }
        else{
            if(q.empty()) cout << "NONE";
            else cout << q.front();
            cout << endl;
        }
    }
}

int main(){
    Try();
    cout << endl;
}