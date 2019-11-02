#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
 
int main() {
	long long int n;
	cin>>n;
	int t;
	cin>>t;
	long long res = n * n;
	long long int one = n, two = n;
	map<int,bool> columns, rows;
	for(int c=0;c<t;c++) {
		int x,y;
		cin>>x>>y;
		
		if(columns.find(y) == columns.end()) {
			columns[y] = true;
			one --;
		    res -= two;
		}
		if(rows.find(x) == rows.end()) {
			rows[x] = true;
			two --;
		    res -= one;
		}
		if(rows.find(x) == rows.end() && columns.find(y) == columns.end()) {
		    res++;
		}
		cout<<res<<" ";
	}
	
}