#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
 
 
int main()
{
ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    long long int N;
    cin>>N;
    vector<long long int> v(N);
    for(int c=0;c<N;c++) cin>>v[c];
    sort(v.begin(),v.end());
    if(v[0]==v.back())
    {
        cout<<0<<" "<<((N-1LL)*1LL*N)/2LL;
    }
    else
    {
        long long int diff=v.back()-v[0];
        long long int c=0;
        while(v[c]==v[0]) c++;
        reverse(v.begin(),v.end());
        long long int c2=0;
        while(v[c2]==v[0]) c2++;
        cout<<diff<<" "<<c2*c;
    }
}