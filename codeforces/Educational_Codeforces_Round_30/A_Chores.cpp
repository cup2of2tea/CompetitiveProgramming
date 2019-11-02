#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
 
 
int main() {
	int n,k,x;
	cin>>n>>k>>x;
	vector<int> v(n);
	for(int c=0;c<n;c++) cin>>v[c];
	reverse(v.begin(),v.end());
	long long res = 0;
	for(int c=0;c<k;c++) {
        res += x;
	}
	for(int c = k; c<n;c++) {
        res += v[c];
	}
	cout<<res;
}