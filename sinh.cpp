#include <iostream>
using namespace std;

int n,k, a[100],check=0;
void ktao(){
	for(int i=1;i<=n;i++){
		a[i]=0;
	}
}
void sinh(){
	int i=n;
	while(i>=1&&a[i]==1){
		a[i]=0;
		--i;
	}
	if(i==0){
		check=1;
	}
	else{
		a[i]=1;
	}
}
void sinh_lk(){
	int i=n;
	while(i>=1&&a[i]==n-k+i){
		i--;
	}
	if(i==0){
		check==1;
	}
	else{
		a[i]++;
		for(int j=i+1;j<=k;j++){
			a[j]=a[j-1]+1;
		}
	}
}

int main(){
	cin >> n;
	ktao();
	while(check==0){	
		for(int i=1;i<=n;i++){
			cout << a[i];
		}
		cout << endl;
		sinh();
	}
}
