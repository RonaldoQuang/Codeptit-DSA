//Trên một giá có kích thước R x C (R hàng, C cột), một số hạt mầm đã được tra vào các ô. 
//Một số hạt mầm được bón thêm chất dinh dưỡng, nên đã nảy mầm sớm thành cây non.
//Mỗi ngày, các cây non sẽ lan truyền chất dinh dưỡng của nó cho các mầm ở ô xung quanh (trái, trên, phải, dưới), làm cho các hạt mầm này phát triển thành cây non. 
//Tuy nhiên, có thể có một số hạt mầm được gieo ở vị trí lẻ loi, do không nhận được chất dinh dưỡng nên không thể nảy mầm.
//Các bạn hãy xác định xem cần ít nhất bao nhiêu ngày để tất cả các hạt đều mầm?
//A[i][j] = 0, ô (i, j) là ô trống.
//A[i][j] = 1, ô (i, j) là hạt chưa nảy mầm.
//A[i][j] = 2, ô (i, j) là cây non.
//Input
//2
//3 5
//2 1 0 2 1
//1 0 1 2 1
//1 0 0 2 1
//3 5
//2 1 0 2 1
//0 0 1 2 1
//1 0 0 2 1
//Output
//2
//-1
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    while(t--){
        int n, m; cin >> n >> m;
        int a[n][m];
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a[i][j];
                if(a[i][j] == 2){
                    q.push({{i, j},0});
                }
            }
        }
        int res=0;
        while(!q.empty()){
            pair<pair<int,int>,int> p=q.front(); q.pop();
            int x=p.first.first;
            int y=p.first.second;
            int day=p.second;
            res = max(res, day);
            for(int k=0;k<4;k++){
                int i=x+dx[k];
                int j=y+dy[k];
                if(i>=0&&i<n&&j>=0&&j<m&&a[i][j]==1){
                    a[i][j]=2;
                    q.push({{i,j},day+1});
                }
            }
        }
        bool ok=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1){
                    ok=false;
                    break;
                }
            }
        }
        if(!ok) cout << "-1\n";
        else cout << res << "\n";
    }
}