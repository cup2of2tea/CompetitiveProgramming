#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main()
{
   string s1,s2;
   cin>>s1>>s2;
   int h1 = (s1[0]-'0')*10+s1[1]-'0',m1 = (s1[3]-'0')*10+s1[4]-'0';
   int h2 = (s2[0]-'0')*10+s2[1]-'0',m2 = (s2[3]-'0')*10+s2[4]-'0';
   int tot1 = h1*60+m1;
   int tot2 = h2*60+m2;
   tot2 = 24*60 - tot2;
   tot1 += tot2;
   tot1%=24*60;
   cout<<(tot1/60<10?"0":"")<<tot1/60<<":"<<(tot1%60<10?"0":"")<<tot1%60;
}