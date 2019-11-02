#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
int main()
{
    long long int n,k;
    cin>>n>>k;
    long long int n2=n;
    long long int c=0;
    while(n2<k)
    {
        c++;
        n2*=n;
    }
    if(n2==k)
        cout<<"YES"<<endl<<c;
    else
        cout<<"NO";
}