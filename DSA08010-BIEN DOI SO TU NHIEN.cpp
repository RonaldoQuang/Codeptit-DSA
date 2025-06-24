//Cho số tự nhiên N (N<10^9) và hai phép biến đổi (a), (b) dưới đây.
//Thao tác (a): Trừ N đi 1 (N=N-1). Ví dụ N=17, thao tác (a) biến đổi N = N-1 =16.
//Thao tác (b): N = max(u,v) nếu u*v =N (u>1, v>1). Ví dụ N=16, thao tác (b) có thể biến đổi N = max(2, 8)=8 hoặc N=max(4, 4)=4.
//Chỉ được phép sử dụng hai thao tác (a) hoặc (b), hãy biến đổi N thành 1 sao số các thao tác (a), (b) được thực hiện ít nhất. 
//Ví dụ với N=17, số các phép (a), (b) nhỏ nhất biến đổi N thành 1 là 4 bước như sau:
//Thao tác (a): N = N-1 = 17-1 = 16
//Thao tác (b): 16 = max(4,4) = 4
//Thao tác (b): 4 = max(2,2) = 2
//Thao tác (a): 2 = 2-1 = 1
//Input
//3
//17
//50
//100
//Output
//4
//5
//5
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		queue<pair<int,int>> q;
		map<int,int> mp;
		q.push({n,0});
		while(!q.empty()){
			pair<int,int> x=q.front();
			q.pop();
			if(x.first==1){
				cout << x.second << endl;
				break;
			}
			for(int i=sqrt(x.first);i>=2;i--){
				if(x.first%i==0&&mp[x.first/i]==0){
					q.push({x.first/i,x.second+1});
					mp[x.first/i]=1;
				}
			}
			q.push({x.first-1,x.second+1});
		}
	}
}