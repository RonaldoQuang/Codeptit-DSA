//Cho ma trận A[M][N]. 
//Nhiệm vụ của bạn hãy tìm số bước đi ít nhất dịch chuyển từ vị trí A[1][1] đến vị trí A[M][N]. 
//Biết mỗi bước đi ta chỉ được phép dịch chuyển đến vị trí A[i][j+A[i][j]] hoặc vị trí A[i+A[i][j]][j] bên trong ma trận.
//Input
//1
//3  3
//2  1  2
//1  1  1
//1  1  1
//Output
//2
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--){
        int n, m, cnt=0, ok=0; cin >> n >> m;
        vector<vector<int>> a(n+1,vector<int>(m+1));
        vector<vector<int>> b(n+1,vector<int>(m+1,0));
        queue<pair<int,int>> q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        if(1+a[1][1]<=n){
            b[1+a[1][1]][1]=1;
            q.push({1+a[1][1],1});
        } 
        if(a[1][1]+1<=m){
            b[1][a[1][1]+1]=1;
            q.push({1,a[1][1]+1});
        }   
        int dem=q.size();
        if(dem>0) cnt=1;
        while(!q.empty()){
            pair<int,int> x=q.front();
            q.pop();
            if(x.first==n&&x.second==m){
                ok=1;
                cout << cnt << endl;
                break;
            } 
			else{
                --dem;
                if(x.first+a[x.first][x.second]<=n&&b[x.first+a[x.first][x.second]][x.second]==0){
                    b[x.first+a[x.first][x.second]][x.second]=1;
                    q.push({x.first+a[x.first][x.second],x.second});
                }
                if(x.second+a[x.first][x.second]<=m&&b[x.first][x.second+a[x.first][x.second]]==0){
                    b[x.first][x.second+a[x.first][x.second]]=1;
                    q.push({x.first,x.second+a[x.first][x.second]});
                }
                if(dem==0&&q.size()){
                    ++cnt;
                    dem=q.size();
                }
            }
        }
        if(n==1&&m==1) cout << "0" << endl;
        else if(ok==0){
            cout << "-1" << endl;
        }
    }
}
