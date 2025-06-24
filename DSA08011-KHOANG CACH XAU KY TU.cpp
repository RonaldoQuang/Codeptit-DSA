//Cho tập n xâu ký tự S và hai xâu s, t Î S. 
//Ta giả thiết các xâu ký tự S[i] Î S có độ dài bằng nhau.  
//Hãy tìm khoảng cách đường đi ngắn nhất từ s đến t. 
//Biết từ một xâu ký tự bất kỳ ta chỉ được phép dịch chuyển đến xâu khác với nó duy nhất 1 ký tự. 
//Ví dụ ta có tập các từ S = { POON, TOON, PLEE, SAME, POIE, PLEA, PLIE, POIN }, s = TOON, t = PLEA ta có độ dài đường đi ngắn nhất là 7 tương ứng với các phép dịch chuyển : 
//TOON -> POON –> POIN –> POIE –> PLIE –> PLEE –> PLEA.
//Input
//1
//8 TOON  PLEA
//POON TOON PLEE SAME  POIE  PLEA  PLIE  POIN
//Output
//7
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string x, y; cin >> x >> y;
		string a[n];
		queue<pair<string,int>> q;
		set<string> se;
		for(int i=0;i<n;i++){
			cin >> a[i];
			se.insert(a[i]);
		}
		q.push({x,0});
		while(!q.empty()){
		    pair<string,int> p=q.front(); q.pop();
		    if(p.first==y){
		    	cout << p.second+1 << endl;
		    	break;
			}
			for(int i=0;i<p.first.size();i++){
				for(char j='A';j<='Z';j++){
					string s=p.first;
					if(j!=s[i]){
						s[i]=j;
						if(se.find(s)!=se.end()){
							q.push({s,p.second+1});
							se.erase(s);
						}
					}
				}
			}	
		}
	}
}