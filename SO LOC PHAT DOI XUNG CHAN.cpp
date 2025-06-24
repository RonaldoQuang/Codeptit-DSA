//Trong quan điểm người Việt, một số nguyên dương được gọi là “lộc phát” nếu chỉ có hai chữ số là 6 và/hoặc 8. 
//Một số lộc phát X được gọi là đối xứng chẵn nếu:
//Số chữ số của X là chẵn
//X thỏa mãn tính chất đối xứng.
//Hãy liệt kê N số lộc phát đối xứng chẵn đầu tiên theo thứ tự từ nhỏ đến lớn.
//Input
//2
//4
//10
//Output
//66 88 6666 6886
//66 88 6666 6886 8668 8888 666666 668866 686686 688886
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n, cnt=2; cin >> n;
		vector<string> v;
		queue<string> q;
		q.push("6");
		q.push("8");
		while(cnt<=n+1){
			string s=q.front(); q.pop();
			v.push_back(s);
			if(cnt<=n+1){
				q.push(s+"6");
				++cnt;
				if(cnt<=n+1){
					q.push(s+"8");
				}
			}
		}
		for(auto x:v){
			cout << x;
			for(int i=x.size()-1;i>=0;i--){
				cout << x[i];
			}
			cout << " ";
		}
		cout << endl;
	}
}
