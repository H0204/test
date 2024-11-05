#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tuLanh{
	string hangSx;
	int dungTich;
	float trongLuong;
};
void ss(tuLanh * d,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(d[i].dungTich>d[j].dungTich){
				tuLanh temp = d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}
}
void A(tuLanh* d,int n,int s,int &c,tuLanh *x){
	c=0;
	int kt=0;
	ss(d,n);
	for(int i=0;i<n;i++){
		if(kt+d[i].dungTich<=s){
			kt+=d[i].dungTich;
			x[c]=d[i];
			c++;
		}
		else{
			break;
		}
	}
}

int main(){
	int n=6;
	int s=13;
	tuLanh * d= new tuLanh[n]{
	{"hang a",2,55},
	{"hang b",3,60},
	{"hang c",3,52.5},
	{"hang d",2,50},
	{"hang a",3,50},
	{"hang d",5,65},
	};
	int c;
	tuLanh x[10];
	A(d,n,s,c,x);
	cout << "so tu lanh co the xep la:" << c << endl;
	cout << "ds tu lan dc chon la:" << endl;
	for(int i=0;i<c;i++){
		cout << x[i].hangSx << "	" << x[i].dungTich << "	" << x[i].trongLuong << endl;
	}
	cout << endl;	
}
