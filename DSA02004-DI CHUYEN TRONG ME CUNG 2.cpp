//Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. 
//Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:
//Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
//Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
//Left (L): Chuột được phép sang trái dưới nếu ô bên trái nó có giá trị 1.
//Up (U): Chuột được phép lên trên nếu ô trên nó có giá trị 1.
//Hãy đưa ra tất cả các hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.
//Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng kế tiếp đưa vào các bộ test. 
//Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
//T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤8; 0≤A[i][j] ≤1.
//Output:
//Đưa ra các xâu ký tự được sắp xếp, trong đó mỗi xâu là một đường đi của con chuột trong mê cung. 
//In ra đáp án theo thứ tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
//Input
//3
//4
//1 0 0 0
//1 1 0 1
//0 1 0 0
//0 1 1 1
//4
//1 0 0 0
//1 1 0 1
//1 1 0 0
//0 1 1 1
//5
//1 0 0 0 0
//1 1 1 1 1
//1 1 1 0 1
//0 0 0 0 1
//0 0 0 0 1
//Output
//DRDDRR
//DDRDRR DRDDRR
//DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD
#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int d1[4]={1,0,-1,0};
int d2[4]={0,1,0,-1};
void Try(vector<string> &v, int a[100][100], int i, int j, int n, string s){
	for(int k=0;k<4;k++){
        int x=i+d1[k], y=j+d2[k]; 
		if(x<n&&y<n&&a[x][y]==1||x<n&&y==n&&a[x][y]==1||x==n&&y<n&&a[x][y]==1){
			a[x][y]=0;
			if(k==0) s+="D";
			else if(k==1) s+="R";
			else if(k==2) s+="U";
			else s+="L";
			Try(v,a,x,y,n,s);
			s.pop_back();
			a[x][y]=1;
		}
		else if(x==n&&y==n&&a[x][y]==1){
			if(k==0) s+="D";
			else if(k==1) s+="R";
			else if(k==2) s+="U";
			else s+="L";
			v.push_back(s);
			++cnt;
			s.pop_back();
		}
	}
}
int sum1=0;
int main(){
    int t; cin >> t;
    while(t--){
    	int n, k; cin >> n;
    	int a[100][100];
    	vector<string> v;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			cin >> a[i][j];
			}
		}
		string s="";
		if(a[1][1]==0) cout << "-1";
		else{
			a[1][1]=0;
		    Try(v,a,1,1,n,s);
		    if(cnt-sum1==0) cout << "-1";
		    sum1+=cnt-sum1;
		}
		sort(v.begin(),v.end());
		for(auto x:v){
			cout << x << " ";
		}
		cout << endl;
	}
}