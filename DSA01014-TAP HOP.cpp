//Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau và không lớn hơn số n cho trước. 
//Nhiệm vụ của bạn là hãy đếm xem có tất cả bao nhiêu tập hợp có số lượng phần tử bằng k và tổng của tất cả các phần tử trong tập hợp bằng s?
//Các tập hợp là hoán vị của nhau chỉ được tính là một.
//Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất thỏa mãn.
//Mỗi bộ test gồm 3 số nguyên n, k, s với 1 ≤ n ≤ 20, 1 ≤ k ≤ 10 và 1 ≤ s ≤ 155. 
//Input kết thúc bởi 3 số 0.
//Với mỗi test in ra số lượng các tập hợp thỏa mãn điều kiện đề bài.
//Input
//9 3 23
//9 3 22
//10 3 28
//16 10 107
//20 8 102
//20 10 105
//20 10 155
//3 4 3
//4 2 11
//0 0 0
//Output
//1
//2
//0
//20
//1542
//5448
//1
//0
//0
#include <bits/stdc++.h>
using namespace std;
void kq(int a[100], int k, int S, int &cnt){
    int sum=0;
	for(int i=1;i<=k;i++){
		sum+=a[i];
	}
	if(sum==S){
		++cnt;
	}
}
void Try(int a[100], int n, int k, int S, int &cnt, int i){
	for(int j=a[i-1]+1;j<=n-k+i;j++){
		a[i]=j;
		if(i==k){
			kq(a,k,S,cnt);
		}
		else Try(a,n,k,S,cnt,i+1);
	}
}
int main(){
	int n, k, S;
	while(cin >> n >> k >> S){
		if(n==0&&k==0&&S==0) break;
	    int a[100], cnt=0;
	    a[0]=0;
		Try(a,n,k,S,cnt,1);
		cout << cnt << endl;
	}
}