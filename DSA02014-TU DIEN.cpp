//CCho tập từ ghi trong trừ điển dic[] và một bảng hai chiều A[M][N] các ký tự. 
//Hãy tạo nên tất cả các từ có mặt trong từ điển dic[] bằng cách nối các ký tự kề nhau trong mảng A[][]. 
//Chú ý, phép nối các ký tự kề nhau trong mảng A[][] được thực hiện theo 8 hướng nhưng không có phần tử A[i][j] nào được lặp lại. 
//Ví dụ với từ điển dic[] ={ “GEEKS”, “FOR”, “QIUZ”, “GO”} và mảng A[][] dưới đây sẽ cho ta kết quả: “GEEKS”, “QUIZ”
//Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào ba số K, M, N tương ứng với số từ của từ điển dic[], số hàng và số cột của ma trận ký tự A[M][N]; dòng tiếp theo đưa vào K từ của từ điển dic[]; dòng cuối cùng đưa vào các phần tử A[i][j].
//T, K, M, N thỏa mãn ràng buộc: 1≤T ≤10; 1≤K≤100; 1≤ M, N ≤3.
//Output:
//Đưa ra theo thứ tự tăng dần các từ có mặt trong từ điển dic[] được tạo ra từ ma trận A[][]. Đưa ra -1 nếu không thể tạo ra từ nào thuộc dic[] từ A[][].
//Input
//1
//4  3  3
//GEEKS FOR QUIZ GO
//G I Z
//U E K
//Q S E
//Output
//GEEKS QUIZ
#include<bits/stdc++.h>
using namespace std;
int h[8]={-1,-1,-1,0,0,1,1,1};
int c[8]={-1,0,1,-1,1,-1,0,1};
char a[3][3];
int b[3][3]={};
int k, m, n; 
void Try(vector<string> &v, string &s, map<string,int> mp1, int i, int j){
	s+=a[i][j];
	b[i][j]=1;
	if(mp1[s]) v.push_back(s);
	for(int k=0;k<8;k++){
		int x=i+h[k], y=j+c[k];
		if(b[x][y]==0&&0<=x&&x<n&&0<=y&&y<m) Try(v,s,mp1,x,y);
	}
	s.pop_back();
	b[i][j]=0;
}
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    cin >> k >> n >> m;
	    map<char,int> mp;
	    map<string,int> mp1;
	    while(k--){
	    	string s; cin >> s;
	    	mp[s[0]]=1; mp1[s]=1;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> a[i][j];
			}
		}
		string s="";
		vector<string> v;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(mp[a[i][j]]){
					Try(v,s,mp1,i,j);
				}
			}
		}
		if(v.size()){
		    for(auto x:v) cout << x << " ";
		}
		else cout << -1;
		cout << endl;
	} 
}