//Cho hai đa thức có bậc không quá 10000 (chỉ viết ra các phần tử có hệ số khác 0). 
//Hãy sử dụng danh sách liên kết đơn để viết chương trình tính tổng hai đa thức đó.
//Chú ý: Bậc của các hạng tử luôn theo thứ tự giảm dần, trong đa thức chỉ có phép cộng và luôn được viết đầy đủ hệ số + số mũ (kể cả mũ 0).
//Input
//1
//3*x^8 + 7*x^2 + 4*x^0
//11*x^6 + 9*x^2 + 2*x^1 + 3*x^0
//Output
//3*x^8 + 11*x^6 + 16*x^2 + 2*x^1 + 7*x^0
#include <bits/stdc++.h>
using namespace std;
void gan(string a, map<int,int> &mp, queue<int> &q){
	int i=0;
	while(i<a.size()){
		if(i==0||a[i]<='9'&&a[i]>='0'&&a[i-1]==' '){
			int s=0;
			while(a[i]!='*'){
				s=s*10+a[i]-'0';
				++i;
			}
			q.push(s);
		}
		if(a[i]<='9'&&a[i]>='0'&&a[i-1]=='^'){
			int s=0;
			while(a[i]<='9'&&a[i]>='0'){
				s=s*10+a[i]-'0';
				++i;
			}
			mp[s]+=q.front();
			q.pop();
		}
		else ++i;
	}
}
int main(){
	int t; cin >> t;
	cin.ignore();
	while(t--){
		string a, b;
		getline(cin,a);
		getline(cin,b);
		map<int,int> mp;
		queue<int> q;
		gan(a,mp,q);
		gan(b,mp,q);
		vector<pair<int,int>> v;
		for(auto x:mp){
			pair<int,int> p;
			p.first=x.second, p.second=x.first;
			v.push_back(p);
		}
		for(int i=v.size()-1;i>=0;i--){
			if(i>0) cout << v[i].first << "*x^" << v[i].second << " + ";
			else cout << v[i].first << "*x^" << v[i].second;
		}
		cout << endl;
	}
}