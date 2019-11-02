#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    int n,n2;
	cin>>n2;
	cin>>n;
	if(n==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
	vector<int> v(n);
	for(int c=0;c<n;c++) cin>>v[c];
	sort(v.begin(),v.end());
	if(n>0&&(v[0]==1||v.back()==n2)){cout<<"NO"<<endl; return 0;}
	int act=1;
	for(int c=1;c<v.size();c++)
        if(v[c]==v[c-1]+1)
        {
            act++;
            if(act>=3){cout<<"NO"<<endl;return 0;}
        }
        else act=1;
    cout<<"YES"<<endl;
}