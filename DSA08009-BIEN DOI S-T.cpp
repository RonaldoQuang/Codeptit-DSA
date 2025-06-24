//Cho hai số nguyên dương S và T (S, T<10000) và hai thao tác (a), (b) dưới đây:
//Thao tác (a): Trừ S đi 1  (S = S-1) ;
//Thao tác (b): Nhân S với 2 ( S = S*2);
//Hãy dịch chuyển S thành T sao cho số lần thực hiện các thao tác (a), (b) là ít nhất.
//Ví dụ với    S =2, T=5 thì số các bước ít nhất để dịch chuyển S thành T thông qua 4 thao tác sau:
//Thao tác (a): 2*2 = 4;
//Thao tác (b): 4-1 = 3;
//Thao tác (a): 3*2 = 6;
//Thao tác (b): 6-1 = 5;
//Input
//3
//2 5
//3 7
//7 4
//Output
//4
//4
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int s, t; cin >> s >> t;
		queue<pair<int,int>> q;
		map<int,bool> mp;
		q.push({s,0});
		while(1){
			pair<int,int> p=q.front();
			q.pop();
			if(p.first==t){
				cout << p.second << endl;
				break;
			}
			if(p.first-1==t||p.first*2==t){
				cout << p.second+1 << endl;
				break;
			}
			if(p.first*2<=t*2&&mp[p.first*2]==0){
				q.push({p.first*2,p.second+1});
				mp[p.first*2]=1;
			}
			if(p.first-1>=0&&mp[p.first-1]==0){
				q.push({p.first-1,p.second+1});
				mp[p.first-1]=1;
			}
		}
	}
}