#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
//#define cin in
//    ifstream in("input.txt");
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<m;c2++)
        {
            if(v[c][c2]=='.')
            {
                v[c][c2] = ((c+c2)%2==0?'B':'W');
            }
        }
    }
    for(int c=0;c<n;c++) cout<<v[c]<<endl;
}