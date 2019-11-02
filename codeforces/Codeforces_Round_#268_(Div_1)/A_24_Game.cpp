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
    int n;
    cin>>n;
    if(n<=3)
    {
        cout<<"NO";
    }
    else if(n%2==1)
    {
        cout<<"YES"<<endl;
        int bla =0;
        for(int c=6;c<n;c+=2)
        {
            cout<<c+1<<" - "<<c<<" = "<<1<<endl;
            bla++;
        }
        cout<<"3 - 2 = 1"<<endl;
        cout<<"1 + 5 = 6"<<endl;
        cout<<"6 * 4 = 24"<<endl;
        for(int c=0;c<bla+1;c++)
        {
            cout<<"24 * 1 = 24"<<endl;
        }
    }
    else
    {
        cout<<"YES"<<endl;
        int bla =0;
        for(int c=5;c<n;c+=2)
        {
            cout<<c+1<<" - "<<c<<" = "<<1<<endl;
            bla++;
        }
        cout<<"2 * 3 = 6"<<endl;
        cout<<"6 * 4 = 24"<<endl;
        for(int c=0;c<bla+1;c++)
        {
            cout<<"24 * 1 = 24"<<endl;
        }
    }
}