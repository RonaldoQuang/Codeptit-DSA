//Cho số nguyên N. 
//Nhiệm vụ của bạn cần tìm số nguyên X nhỏ nhất là bội của N, và X chỉ chứa hai chữ số 0 và 9.
//Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10000). 
//Mỗi bộ test chứa số nguyên N trên một dòng (1 ≤ N ≤ 500).
//Output:  Với mỗi test in ra đáp án tìm được trên một dòng.
//Input
//3
//2
//5
//11
//Output
//90
//90
//99
#include <bits/stdc++.h>
using namespace std;
long long kq(string s, long long m){
	long long sum=0;
	for(int i=0;i<s.size();i++){
		sum=sum*10+s[i]-'0';
		sum%=m;
	}
	return sum;
}
int main(){
	int t; cin >> t;
	while(t--){
		long long n; cin >> n;
		queue<string> q;
		string s="9";
		q.push(s);
		string z;
		while(1){
			s=q.front();
			if(kq(q.front(),n)==0){
				z=q.front();
				break;
			}
			q.push(s+"0");
			q.push(s+"9");
			q.pop();
		}
		cout << z << endl;
	}
}