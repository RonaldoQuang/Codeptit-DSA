//Cho một dãy các xâu ký tự chỉ bao gồm các chữ cái in hoa từ A đến Z.
//Trong đó các ký tự trong mỗi xâu đều đã được sắp xếp theo thứ tự từ điển và mỗi chữ cái chỉ xuất hiện nhiều nhất một lần (tức là độ dài xâu tối đa là 26). 
//Nếu một ký tự xuất hiện trong hai xâu liên tiếp thì được coi là một lần lặp. 
//Hãy tìm cách sắp xếp lại thứ tự các xâu sao cho số lần lặp là nhỏ nhất có thể. 
//Ví dụ dưới đây là cùng một dãy xâu nhưng với cách sắp xếp lại thì số lần lặp chỉ còn 2.
//ABC
//ABEF
//DEF
//ABCDE
//FGH
//=> Số lần lặp là 6
//ABEF
//DEF
//ABC
//FGH
//ABCDE
//=> Số lần lặp là 2.
//Input
//Dòng đầu tiên ghi số N (2 ≤ N ≤ 10) là số xâu ký tự. N dòng tiếp theo, mỗi dòng ghi một xâu. 
//Output
//In ra trên một dòng số lần lặp nhỏ nhất có thể. 
//Input
//5
//ABC
//ABEF
//DEF
//ABCDE
//FGH
//Output
//2
#include <bits/stdc++.h> 
using namespace std;
int dp[100][100];
int tinh(string a, string b){
	int cnt=0;
	for(char x:a){
		if(b.find(x)!=string::npos) ++cnt;
	}
	return cnt;
}
void kq(string s[], int a[], int n, int &min1){
	int cnt=0;
	for(int i=1;i<n;i++){
		cnt+=dp[a[i]][a[i+1]];
	}
	min1=min(min1,cnt);
}
void Try(string s[], int a[], int b[], int n, int &min1, int i){
	for(int j=1;j<=n;j++){
		if(b[j]){
			a[i]=j;
			b[j]=0;
			if(i==n){
				kq(s,a,n,min1);
			}
			else Try(s,a,b,n,min1,i+1);
			b[j]=1;
		}
	}
} 
int main(){
    int n; cin >> n;
	string s[n+1];
	int a[n+1], b[n+1];
	for(int i=1;i<=n;i++){
		cin >> s[i];
		b[i]=1;
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=tinh(s[i],s[j]);
			dp[j][i]=dp[i][j];
		}
	}
	int min1=1e9;
	Try(s,a,b,n,min1,1);
	cout << min1;	
}