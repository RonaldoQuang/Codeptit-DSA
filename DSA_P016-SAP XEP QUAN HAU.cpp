//Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định (0 ≤ A[i][j] ≤ 100), tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó.
//Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.
//Input:
//Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
//Mỗi test gồm 8 dòng, mỗi dòng 8 số nguyên mô tả bàn cờ.
//Output: 
//Với mỗi test, ghi ra thứ tự bộ test và giá trị điểm lớn nhất đạt được trên một dòng.
//Input
//1
//1 2 3 4 5 6 7 8
//9 10 11 12 13 14 15 16
//17 18 19 20 21 22 23 24
//25 26 27 28 29 30 31 32
//33 34 35 36 37 38 39 40
//41 42 43 44 45 46 47 48
//48 50 51 52 53 54 55 56
//57 58 59 60 61 62 63 64
//Output
//Test 1: 260
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
	int cnt=0;
	while(t--){
		++cnt;
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
	    cout << "Test " << cnt << ": " << max1 << endl;
	}
}