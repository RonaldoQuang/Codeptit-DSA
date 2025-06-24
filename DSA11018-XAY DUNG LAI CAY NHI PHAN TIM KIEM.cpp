//Cho một mảng là phép duyệt level-order của cây nhị phân tìm kiếm. 
//Nhiệm vụ của bạn là xây dựng lại cây nhị phân tìm kiếm bảo toàn được cấu trúc cây nhị phân ban đầu.
//Input
//2
//9
//7 4 12 3 6 8 1 5 10
//6
//1 3 4 6 7 8
//Output
//7 4 3 1 6 5 12 8 10
//1 3 4 6 7 8
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		this->data=x;
		this->left=NULL;
		this->right=NULL;
	}
};
typedef struct Node* node;
void Insert(node &a, int x){
	if(a==NULL) a=new Node(x);
	else{
		if(x<a->data) Insert(a->left,x);
		else Insert(a->right,x);
	}
}
void in(node a){
	cout << a->data << " ";
	if(a->left!=NULL) in(a->left);
	if(a->right!=NULL) in(a->right);
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node a=NULL;
		while(n--){
			int x; cin >> x;
			Insert(a,x);
		}
		in(a);
		cout << endl;
	}
}