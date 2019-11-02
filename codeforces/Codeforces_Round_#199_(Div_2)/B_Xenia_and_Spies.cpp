#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
 
using namespace std;
 
 
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,m,s,f;
    cin>>n>>m>>s>>f;
    vector<long long> t(m),r(m),l(m);
    for(int c=0;c<m;c++)
    {
        cin>>t[c]>>l[c]>>r[c];
    }
    int tour_act=1;
    for(int c=0;c<m;c++)
    {
        if(t[c]-tour_act>=abs(s-f))
        {
            cout<<string(abs(s-f),(s>f?'L':'R'));
            return 0;
        }
        cout<<string(t[c]-tour_act,(s>f?'L':'R'));
        s+=(s>f?-1:1)*(t[c]-tour_act);
        if((s-1>r[c]||s<l[c])&&f<s)
        {
            cout<<"L";
            s--;
        }
        else if((s+1<l[c]||s>r[c])&&f>s)
        {
            cout<<"R";
            s++;
        }
        else cout<<"X";
        tour_act=t[c]+1;
    }
    cout<<string(abs(s-f),(s>f?'L':'R'));
}