//Có n tờ tiền có giá trị t[1], t[2], …, t[n].
//Hãy tìm cách trả ít tờ tiền nhất với số tiền đúng bằng S
//Chú ý: Các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần.
//Input
//3 5
//1 4 5
//Output
//1
#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], c[100], n, k, N, cnt=1, dem=0;
void Try(int i, int sum){
	b[i]=1;
	for(int j=i+1;j<=n;j++){
		if(a[j]<N){
			++cnt;
			if(cnt%k==0){
				b[j]=1;
				sum+=a[j];
				if(sum==N){
					++dem;
					return;
				}
			}
			else{
				sum+=a[j];
			    Try(j,sum);
			}
			b[j]=0;
			cnt-=1;
			sum-=a[j];
		}
	}
	b[i]=0;
}
int main(){
	cin >> n >> N;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		a[i]=c[n+1-i];
	}
	if(binary_search(c+1,c+n+1,N)==1) cout << "1";
	else{
		for(k=2;k<=n;k++){
			for(int i=1;i<=n-k+1;i++){
		        int sum=a[i];
		        Try(i,sum);
		        if(dem==1) break;
	        }
	        if(dem==1){
	        	cout << k;
	        	break;
			}
		}
		if(dem==0) cout << "-1";
	}
}