#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <stack>
#include <limits.h>
#define ll long long
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
   int n,t;
   cin>>n>>t;
   string s1,s2;
   cin>>s1>>s2;
   int equals = s1.size()-t;
   int notDiff = 0;
   for(int c=0;c<s1.size();c++)
        if(s1[c]==s2[c]) notDiff++;
    int toEqualS1Restant = max(0,equals - notDiff);
    int toEqualS2Restant = max(0,equals - notDiff);
 
 
    string res="";
    for(int c=0;c<s1.size();c++)
    {
        if(s1[c] == s2[c] && equals && notDiff)
        {
            equals--;
            notDiff--;
            res=res+s1[c];
        }
        else if(s1[c] != s2[c] && toEqualS1Restant){
            toEqualS1Restant --;
            res = res+s1[c];
        } else if(s1[c] != s2[c] && toEqualS2Restant && equals){
            res=res+s2[c];
            equals--;
            toEqualS2Restant--;
        } else {
            char c2;
            for(c2 = 'a'; c2 <= 'z';c2++) {
                if(c2 != s1[c] && c2!=s2[c]) break;
            }
            res = res + c2;
        }
    }
    if(toEqualS1Restant || toEqualS2Restant || equals) {
        cout<<-1;
    } else {
        cout<<res;
    }
 
}