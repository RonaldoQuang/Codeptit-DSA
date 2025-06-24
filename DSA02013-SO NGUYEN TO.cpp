//Cho ba số N, P, S. 
//Trong đó, P là một số nguyên tố. 
//Nhiệm vụ của bạn là đưa ra tất cả N số nguyên tố lớn hơn P có tổng bằng S. 
//Ví dụ với S = 28, P=7, N =2 ta có kết quả 11 + 17 = 28. 
//Với N = 3, P = 2, S = 23 ta có kết quả : {3, 7, 13}, {5, 7, 11}
//Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ ba số S, P, N được viết trên một dòng.
//S, P, N thỏa mãn ràng buộc: 1≤T ≤100; 1 ≤ N ≤ 10; 2≤S, P≤200.
//Output:
//Với mỗi test, dòng đầu tiên in ra số lượng đáp án tìm được. Mỗi dòng tiếp theo in ra kết quả tìm được theo thứ tự từ điển.
//Input
//2
//2 7 28
//3 2 23
//Output
//1
//11 17
//2
//3 7 13
//5 7 11
#include <bits/stdc++.h>
using namespace std;
int prime[201];
void sang(){
	for(int i=2;i<=200;i++){
		prime[i]=1;
	}
	prime[0]=prime[1]=0;
	for(int i=2;i<=sqrt(200);i++){
		if(prime[i]){
			for(int j=i*i;j<=200;j+=i){
				prime[j]=0;
			}
		}
	}
}
void kq(vector<int> &v, int a[1000], int b[1000], int N, int S, int &cnt){
    int sum=0;
	for(int i=1;i<=N;i++){
		sum+=a[b[i]];
	}
	if(sum==S){
		++cnt;
		for(int i=1;i<=N;i++){
			v.push_back(a[b[i]]);
		}
	}
}
void Try(vector<int> &v, int a[1000], int b[1000], int n, int N, int S, int &cnt, int i){
	for(int j=b[i-1]+1;j<=n-N+i;j++){
		b[i]=j;
		if(i==N){
			kq(v,a,b,N,S,cnt);
		}
		else Try(v,a,b,n,N,S,cnt,i+1);
	}
}
int main(){
	int t; cin >> t;
	sang();
	while(t--){
		int N, P, S; cin >> N >> P >> S;
	    int a[1000], b[1000], cnt=0;
	    b[0]=0;
	    vector<int> v;
	    int n=1;
	    for(int i=P+1;i<S;i++){
	    	if(prime[i]){
	    		a[n]=i;
	    		++n;
			}
		}
		n-=1;
		Try(v,a,b,n,N,S,cnt,1);
		cout << cnt << endl;
		for(int i=0;i<=cnt-1;i++){
			for(int j=i*N;j<=i*N+N-1;j++){
				cout << v[j] << " ";
			}
			cout << endl;
		}
	}
}