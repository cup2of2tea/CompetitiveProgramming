#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <cstdio>
#include <set>
#include <iomanip>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"-----"<<s<<"-----"<<endl;
#endif
 
using namespace std;
 
string bourrin(int cas)
{
 
}
 
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int nb_1_com=0,nb_1_1=0,nb_1_2=0;
    for(int c=0;c<s1.size();c++)
    {
        if(s1[c]==s2[c]&&s1[c]=='1')
        {
            nb_1_com++;
        }
        else if(s1[c]=='1')
            nb_1_1++;
        else if(s2[c]=='1')
            nb_1_2++;
    }
    cout<<(nb_1_com%2+nb_1_1>nb_1_2?"First":(nb_1_com%2+nb_1_1>=nb_1_2-1?"Draw":"Second"));
}