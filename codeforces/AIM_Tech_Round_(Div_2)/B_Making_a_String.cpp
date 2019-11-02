#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	vector<long long int> v(n);
	for(int c=0;c<n;c++) cin>>v[c];
	sort(v.rbegin(),v.rend());
	long long int res = 0;
	for(int c=0;c<v.size();c++)
	{
		if(c > 0 && v[c] >=  v[c-1]) v[c]=v[c-1]-1;
		res += max(0LL,v[c]);
 
	}
	cout<<res;
} 