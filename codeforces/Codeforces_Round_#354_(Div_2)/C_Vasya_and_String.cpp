#include <bits/stdc++.h>
 
using namespace std;
 
 
 
 
int main() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int count[2]={0,0};
	int i = 0, j = 0;
	int res = 0;
	while(j < s.size()) {
		if(s[j] == 'a') count[0]++;
		else count[1]++;
		while(min(count[0],count[1]) > k) {
			if(s[i]=='a') count[0]--;
			else count[1]--;
			i++;
		}
		res = max(res,j-i+1);
		j++;
	}
	cout<<res;
}