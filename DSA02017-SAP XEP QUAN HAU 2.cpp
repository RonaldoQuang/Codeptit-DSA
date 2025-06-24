//Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định (0 ≤ A[i][j] ≤ 100), tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó.
//Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.
//Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
//Mỗi test gồm 8 dòng, mỗi dòng 8 số nguyên mô tả bàn cờ.
//Output:  Với mỗi test, in ra đáp án trên một dòng.
#include <bits/stdc++.h>
using namespace std;
int kq(int a[100][100], int x[100]){
	int sum=0;
	for(int i=1;i<=8;i++){
		sum+=a[i][x[i]];
	}
	return sum;
}
void Try(int a[100][100], int x[100], int cot[100], int dcx[100], int dcn[100], int i, int &max1){
	for(int j=1;j<=8;j++){
		if(cot[j]==1&&dcx[i-j+8]==1&&dcn[i+j-1]==1){
			x[i]=j;
			cot[j]=dcx[i-j+8]=dcn[i+j-1]=0;
			if(i==8){
				max1=max(max1,kq(a,x));
			}
			else{
				Try(a,x,cot,dcx,dcn,i+1,max1);
			}
			cot[j]=dcx[i-j+8]=dcn[i+j-1]=1;
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int a[100][100];
		int x[100], cot[100], dcx[100], dcn[100];
		int max1=-1e9;
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				cin >> a[i][j];
			}
		}
	    for(int i=1;i<100;i++){
		    cot[i]=dcx[i]=dcn[i]=1;
	    }
	    Try(a,x,cot,dcx,dcn,1,max1);
	    cout << max1 << endl;
	}
}