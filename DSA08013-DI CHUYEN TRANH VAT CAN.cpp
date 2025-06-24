//Cho một bảng kích thước N x N, trong đó có các ô trống ‘.’ và vật cản ‘X’. 
//Các hàng và các cột được đánh số từ 0.
//Mỗi bước di chuyển, bạn có thể đi từ ô (x, y) tới ô (u, v) nếu như 2 ô này nằm trên cùng một hàng hoặc một cột, và không có vật cản nào ở giữa.
//Cho điểm xuất phát và điểm đích. 
//Bạn hãy tính số bước di chuyển ít nhất?
//Input
//1
//3
//.X.
//.X.
//...
//0 0 0 2
//Output
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		char a[n][n];
		int b[n][n]={};
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> a[i][j];
			}
		}
		int m, l, x, y; cin >> m >> l >> x >> y;
		queue<pair<int,int>> q;
		int cnt=0, dem=1;
		q.push({m,l});
		b[m][l]=1;
		while(!q.empty()){
			pair<int,int> p=q.front(); q.pop();
			if(p.first==x&&p.second==y){
				cout << cnt << endl;
				break;
			}
			else{
				--dem;
				int i=p.first+1;
				while(i<n&&a[i][p.second]!='X'){
					if(b[i][p.second]==0){
					    q.push({i,p.second});
					    b[i][p.second]=1;
					}
					++i;
				}
				i=p.first-1;
				while(i>=0&&a[i][p.second]!='X'){
					if(b[i][p.second]==0){
					    q.push({i,p.second});
					    b[i][p.second]=1;
					}
					--i;
				}
				int j=p.second+1;
				while(j<n&&a[p.first][j]!='X'){
					if(b[p.first][j]==0){
					    q.push({p.first,j});
					    b[p.first][j]=1;
					}
					++j;
				}
				j=p.second-1;
				while(j>=0&&a[p.first][j]!='X'){
					if(b[p.first][j]==0){
					    q.push({p.first,j});
					    b[p.first][j]=1;
					}
					--j;
				}
				if(dem==0){
					++cnt;
					dem=q.size();
				}
			}
		}
	}
}