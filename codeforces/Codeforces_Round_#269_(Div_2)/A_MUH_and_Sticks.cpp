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
 
const long long UNIVERS = -4242424242LL;
 
 
 
 
int main()
{
ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    vector<int> v(6);
    for(int c=0;c<6;c++)
        cin>>v[c];
    sort(v.begin(),v.end());
    vector<int> count(10,0);
    for(int c=0;c<v.size();c++) count[v[c]]++;
    for(int c=0;c<count.size();c++)
        for(int c2=0;c2<count.size();c2++)
            for(int c3=c2+1;c3<count.size();c3++)
                if((count[c]==4 && count[c2]==2)||count[c]==6)
                {
                    cout<<"Elephant"<<endl;
                    return 0;
                }
                else if((count[c]==4 && count[c2] == 1 && count[c3] == 1)||(count[c]==5&&count[c2]==1))
                {
                    cout<<"Bear"<<endl;
                    return 0;
                }
    cout<<"Alien"<<endl;
}