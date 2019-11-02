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
    int n,s;
    cin>>n>>s;
    int bestSweet = -1;
    for(int c=0;c<n;c++)
    {
        int dollars,cents;
        cin>>dollars>>cents;
        if(dollars < s ||(dollars==s && cents==0))
        {
            bestSweet = max(bestSweet,(100-cents)%100);
        }
    }
    cout<<bestSweet;
}