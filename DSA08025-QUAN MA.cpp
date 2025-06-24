//Cho một quân mã trên bàn cờ vua tại vị trí ST. 
//Nhiệm vụ của bạn là hãy tìm số bước di chuyển ít nhất để đưa quân mã tới vị trí EN.
//Input
//8
//e2 e4
//a1 b2
//b2 c3
//a1 h8
//a1 h7
//h8 a1
//b1 c3
//f6 f6
//Output
//2
//4
//2
//6
//5
//6
//1
//0
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int h[8]={1,2,2,1,-1,-2,-2,-1};
		int c[8]={-2,-1,1,2,2,1,-1,-2};
		string s1, s2; cin >> s1 >> s2;
		queue<pair<int,int>> q;
		int cnt=0, dem=1;
		int x=s1[0]-96, a=s2[0]-96, y=s1[1]-'0', b=s2[1]-'0';
		q.push({x,y});
		while(!q.empty()){
			pair<int,int> p=q.front();
			q.pop();
			if(p.first==a&&p.second==b){
				cout << cnt << endl;
				break;
			}
			else{
				--dem;
				for(int i=0;i<8;i++){
					int m=p.first+h[i], n=p.second+c[i];
					if(1<=m&&m<=8&&1<=n&&n<=8){
						q.push({m,n});
					}
				}
				if(dem==0){
					++cnt;
					dem=q.size();
				}
			}
		}
	}
}