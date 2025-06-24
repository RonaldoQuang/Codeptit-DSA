//Cho hai số nguyên dương L, R. 
//Hãy đưa ra số các số K trong khoảng [L, R] thỏa mãn điều kiện:
//Tất cả các chữ số của K đều khác nhau.
//Tất cả các chữ số của K đều nhỏ hơn hoặc bằng 5.
//Ví dụ với L = 4, R = 13 ta có 5 số thỏa mãn yêu cầu là 4, 5, 10, 12, 13,
//Input
//2
//4 13
//100 1000
//Output
//5
//100
#include <bits/stdc++.h>
using namespace std;
int check(string s, int a){
	int cnt=0;
	for(int i=0;i<s.size();i++){
		int x=s[i]-'0';
		if(x==a){
			++cnt;
			break;
		}
	}
	if(cnt==0) return 1;
	else return 0;
}
int main(){
	int t; cin >> t;
	while(t--){
		int l, r, cnt=0; cin >> l >> r;
		int a[6]={0,1,2,3,4,5};
		queue<string> q;
		q.push("0");
		q.push("1");
		q.push("2");
		q.push("3");
		q.push("4");
		q.push("5");
		while(1){
			string w=q.front();
			if(stoi(w)>r) break;
			else{
				string s=q.front(), s1=q.front();
				q.pop();
				if(stoi(s1)>=l&&stoi(s1)<=r) ++cnt;
				for(int i=0;i<6;i++){
					if(check(s,a[i])&&s!="0") q.push(s+to_string(a[i]));
				}
			}
		}
		cout << cnt << endl;
	}
}