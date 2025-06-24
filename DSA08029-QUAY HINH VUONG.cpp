//Có một chiếc bảng hình chữ nhật với 6 miếng ghép, trên mỗi miếng ghép được điền một số nguyên trong khoảng từ 1 đến 6. 
//Tại mỗi bước, chọn một hình vuông (bên trái hoặc bên phải), rồi quay theo chiều kim đồng hồ.
//Input
//1
//1 2 3 4 5 6
//4 1 2 6 5 3
//Output
//2
#include <bits/stdc++.h>
using namespace std;
struct Hinhchunhat{
	int a, b, c, d, e ,f;
};
typedef struct Hinhchunhat hcn;
int ss(hcn x, hcn y){
	if(x.a==y.a&&x.b==y.b&&x.c==y.c&&x.d==y.d&&x.e==y.e&&x.f==y.f) return 1;
	else return 0;
}
int main(){
	int t; cin >> t;
	while(t--){
		hcn x, y;
		cin >> x.a >> x.b >> x.c >> x.d >> x.e >> x.f;
		cin >> y.a >> y.b >> y.c >> y.d >> y.e >> y.f;
		queue<pair<hcn,int>> q;
		q.push({x,0});
		while(!q.empty()){
			pair<hcn,int> p=q.front(); q.pop();
			if(ss(p.first,y)){
				cout << p.second << endl;
				break;
			}
			hcn m, n;
			m.a=p.first.d, m.b=p.first.a, m.c=p.first.c, m.d=p.first.e, m.e=p.first.b, m.f=p.first.f;
			q.push({m,p.second+1});
			n.a=p.first.a, n.b=p.first.e, n.c=p.first.b, n.d=p.first.d, n.e=p.first.f, n.f=p.first.c;
			q.push({n,p.second+1});
		}
	}
}