//Cho một bàn cờ vua có kích thước n * n, ta biết ràng quân hậu có thể di chuyển theo chiều ngang, dọc, chéo. 
//Vấn đề đặt ra rằng, có n quân hậu, bạn cần đếm số cách đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kì, chúng không “ăn” nhau.
//Input: Dòng đầu ghi số bộ test T (T<5). Mỗi bộ test ghi một số nguyên dương n duy nhất (không quá 10)
//Output:  Ghi kết quả mỗi bộ test trên một dòng. Số cách đặt quân hậu.
//Input
//1
//4
//Output
//2
#include <bits/stdc++.h>
using namespace std;
int cnt=0, sum=0;
void Try(int N, int x[100], int cot[100], int dcx[100], int dcn[100], int i){
	for(int j=1;j<=N;j++){
		if(cot[j]==1&&dcx[i-j+N]==1&&dcn[i+j-1]==1){
			x[i]=j;
			cot[j]=dcx[i-j+N]=dcn[i+j-1]=0;
			if(i==N){
				++cnt;
			}
			else{
				Try(N,x,cot,dcx,dcn,i+1);
			}
			cot[j]=dcx[i-j+N]=dcn[i+j-1]=1;
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int N, x[100], cot[100], dcx[100], dcn[100];
	    cin >> N;
	    for(int i=1;i<100;i++){
		    cot[i]=dcx[i]=dcn[i]=1;
	    }
	    Try(N,x,cot,dcx,dcn,1);
	    cout << cnt-sum << endl;
	    sum+=cnt-sum;
	}
}