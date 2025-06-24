//Cho một cây biểu thức là một cây nhị phân đầy đủ bao gồm các phép toán +, -, *. / và một số toán hạng có giá trị nguyên. 
//Nhiệm vụ của bạn là hãy tính toán giá trị biểu thức được biểu diễn trên cây nhị phân đầy đủ. 
//Ví dụ với cây dưới đây là biểu diễn của biểu thức P = ( (5*4) + (100-20)) sẽ cho ta giá trị là 100.
//Input
//2
//7
//+ * - 5 4 100 20
//3
//- 4 7 
//Output
//10
//-3
#include <bits/stdc++.h>
using namespace std;
int tinh(int a, int b, string s){
	if(s=="+") return a+b;
	if(s=="-") return a-b;
	if(s=="*") return a*b;
	if(s=="/") return a/b;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s[n];
		for(int i=0;i<n;i++) cin >> s[i];
		queue<int> q;
		for(int i=n-1;i>=0;i--){
			if(s[i]=="+"||s[i]=="-"||s[i]=="*"||s[i]=="/"){
				int y=q.front(); q.pop();
				int x=q.front(); q.pop();
				q.push(tinh(x,y,s[i]));
			}
			else q.push(stoi(s[i]));
		}
		cout << q.front() << endl;
	}
}