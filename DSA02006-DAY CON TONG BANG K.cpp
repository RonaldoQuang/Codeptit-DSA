//Cho dãy số A[] = (a1, a2, .., an) và số tự nhiên K. 
//Hãy đưa ra tất cả các dãy con của dãy số A[] sao cho tổng các phần tử của dãy con đó đúng bằng K. 
//Các phần tử của dãy số A[] được giả thuyết là nguyên dương và không có các phần tử giống nhau. 
//Ví dụ với dãy con A[] = {5, 10, 15, 20, 25}, K = 50 ta có 3 dãy con {5, 10, 15, 20}, {5, 20, 25}, {10, 15, 25}.
//Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng kế tiếp đưa vào các bộ test. 
//Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[] và số K; dòng tiếp theo đưa vào N phần tử của dãy số A[].
//T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤10; 1≤ K, A[i] ≤100.
//Output:
//Đưa ra tất cả các dãy con của dãy số A[] thỏa mãn yêu cầu bài toán theo thứ tự từ điển, trong đó mỗi dãy con được bao bởi các ký tự [, ]. 
//Nếu không có dãy con nào thỏa mãn yêu cầu bài toán, hãy đưa ra -1.
//Input
//2
//5 50
//5  10 15 20  25
//8  53
//15  22  14  26  32  9  16  8
//Output
//[5 10 15 20] [5 20 25] [10 15 25]
//[8 9 14 22] [8 14 15 16] [15 16 22]
#include <bits/stdc++.h>
using namespace std;
void kq(int a[100], int b[100], int n){
	int k=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			++k;
		}
	}
	int cnt=0;
	cout << "[";
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			++cnt;
		    if(cnt%k!=0) cout << a[i] << " ";
		    else cout << a[i] << "]";
		}
	}
	cout << " ";
}
void Try(int a[100], int b[100], int c[1], int N, int i, int n, int sum){
	b[i]=1;
	for(int j=i+1;j<=n;j++){
		if(a[j]<N){
			b[j]=1;
			sum+=a[j];
			if(sum==N){
				kq(a,b,n);
				c[0]=1;
			}
			else if(sum<N){
			    Try(a,b,c,N,j,n,sum);
			}
			b[j]=0;
			sum-=a[j];
		}
	}
	b[i]=0;
}
int main(){
	int t; cin >> t;
	while(t--){
		int a[100], b[100], n, k, N; cin >> n >> N;
		int c[1]={0};
	    for(int i=1;i<=n;i++){
		    cin >> a[i];
		    b[i]=0;
	    }
	    sort(a+1,a+n+1);
	    for(int i=1;i<=n-k+1;i++){
		    int sum=a[i];
		    Try(a,b,c,N,i,n,sum);
	    }
		if(binary_search(a+1,a+n+1,N)){
		    cout << "[" << N << "]";
	    }
	    if(c[0]==0) cout << "-1";
		cout << endl;
	}
}