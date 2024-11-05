#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct lapTop{
	string hangSx;
	string thongSo;
	float gia;
};
void ss(lapTop*d,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(d[i].gia<d[j].gia){
				lapTop temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}
}
void B(lapTop * d,int n,int p,int &c,lapTop *x){
	c=0;
	float tien=0;
	for(int i=0;i<n;i++){
		x[c]=d[i];
		tien+=x[i].gia;
		c++;
		if(tien>=p){
			break;
		}
	}
} 

int kyTu(char c, string s) {
    for (int i = s.length() - 1; i > -1; i--) {
        if (c == s[i]) {
            return i;
        }
    }
    return -1;
}

int BoyerMooreHorspool(string P, string T) {
    int v = P.length(), i = v - 1;
    while (i < T.length()) {
        int k = v - 1;
        while (k>-1&&T[i]==P[k]){
            i--;
            k--;
        }
        if (k < 0) return i;
        else {
            int x = kyTu(T[i], P);
            if (x < 0) i = i + v;
            else i = i + v - x - 1;
        }
    }
    return -1;
}

pair<int, vector<lapTop>> D(lapTop *d, int n, string p) {
    vector<lapTop> ds;
    for (int i = 0; i < n; i++) {
        if (BoyerMooreHorspool(p, d[i].thongSo) != -1) {
            ds.push_back(d[i]);
        }
    }

    if (ds.size() == 0) {
        return make_pair(-1, ds);
    } else {
        return make_pair(ds.size(), ds);
    }
}

int main(){
	int n=7;
	int p=60000000;
	lapTop *d=new lapTop[n]{
        {"MSI", "CPU 2.9GHz upto 4.2GHz-RAM 32GB-SSD 1TB", 30000000},
        {"APPLE", "CPU 3.1GHz upto 4.1GHz-RAM 8GB-SSD 256GB", 25000000},
        {"DELL", "CPU 2.8GHz upto 4.0GHz-RAM 16GB-SSD 1TB", 20000000},
        {"LENOVO", "CPU 2.7GHz upto 3.9GHz-RAM 16GB-SSD 512GB", 17000000},
        {"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 15000000},
        {"ASUS", "CPU 2.6GHz upto 3.8GHz-RAM 8GB-SSD 256GB", 13000000},
        {"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB", 12000000}
	};
	int c;
	lapTop x[10];
	ss(d,n);
	B(d,n,p,c,x);
	cout << "can ban it nhat " << c << " de dc so tien hon so tien " << p << endl;
	cout << "danh sach laptop dc chon la:" << endl;
	for(int i=0;i<c;i++){
		cout << x[i].hangSx << "	" << x[i].thongSo << "	" << x[i].gia << endl;
	}
	cout << endl;
    pair<int, vector<lapTop>> dsB = D(d, n, "SSD 256GB");
    if (dsB.first!= -1) {
        cout << "Tim thay " << dsB.first << " laptop" << endl;
        for (int i = 0; i < dsB.second.size(); i++) {
            cout << dsB.second[i].hangSx << "	" << dsB.second[i].thongSo << " " << dsB.second[i].gia << endl;
        }
    } else {
        cout << "Khong tim thay laptop" << endl;
    }
}
