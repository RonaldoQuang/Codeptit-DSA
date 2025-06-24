//Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. 
//Ví dụ số K = 1, 10, 101. 
//Cho số tự nhiên N (N<263). 
//Hãy cho biết có bao nhiêu số BDN nhỏ hơn N. 
//Ví dụ N=100 ta có 4 số BDN bao gồm các số: 1, 10, 11, 100.
//Input
//3
//10
//10
//200
//Output
//2
//4
//7
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string n; cin >> n;
		queue<string> q;
		vector<string> v;
		string s="1";
		v.push_back(s);
		q.push(s);
		if(n.size()>=2){
			while(1){
			    s=q.front();
			    if(s.size()>n.size()) break;
			    q.push(s+"0");
			    q.push(s+"1");
			    q.pop();
			    if(q.front().size()<n.size()) v.push_back(q.front());
			    else if(q.front().size()==n.size()){
			    	if(q.front()<=n) v.push_back(q.front());
				}
		    }
		}		
		cout << v.size() << endl;
	}
}