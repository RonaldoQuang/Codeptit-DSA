//Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng. 
//Mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j.
//Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. 
//Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.
//Dữ liệu vào: Dòng đầu tiên là số nguyên n – số thành phố (n ≤ 15); n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.
//Kết quả: Chi phí mà người đó phải bỏ ra.
//Input
//4
//0 20 35 10
//20 0 90 50
//35 90 0 12
//10 50 12 0
//Output
//117
#include <bits/stdc++.h>
using namespace std;
int n, a[50][50], min1=1e9, tien=1e9, x[100], used[100], tmp=-1; 
void Try(int i,int sum){ 
    for(int j=2;j<=n;j++){ 
        if(used[j]==0){ 
            x[i]=j; 
            used[j]=1; 
            if(i==n){ 
                if(sum+a[x[i-1]][x[i]]<tien){ 
                    tien=sum+a[x[i-1]][x[i]]; 
                    tmp=x[i]; 
                } 
            } 
            else{ 
                if(sum+a[x[i-1]][x[i]]+(n-i)*min1<tien){
                    Try(i+1,sum+a[x[i-1]][x[i]]);
                }
            } 
            used[j]=0; 
        } 
    } 
} 
int main(){ 
    cin >> n; 
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=n;j++){ 
            cin >> a[i][j]; 
            if(a[i][j]!=0&&a[i][j]<min1){ 
                min1=a[i][j];
            } 
        } 
    } 
    x[1]=1; 
    Try(2,0); 
    cout << tien+a[tmp][1]; 
}