#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>
#include <sstream>
#include <ctime>
#include <queue>
#include <iomanip>
#include <map>
#define DEBUG2
 
using namespace std;
 
 
 
int main()
{
    vector<string> v(4);
    for(int c=0;c<4;c++) cin>>v[c];
    vector<char> res;
    for(int c=0;c<v.size();c++)
    {
        bool sup = true, inf = true;
        for(int c2=0;c2<v.size();c2++)
        {
            if(c!=c2)
            {
                if((v[c].size()-2)<(v[c2].size()-2)*2) sup = false;
                if((v[c].size()-2)*2>(v[c2].size()-2)) inf = false;
            }
        }
        if(sup||inf) res.push_back(v[c][0]);
    }
    if(res.size()==1) cout<<res[0];
    else cout<<"C";
}