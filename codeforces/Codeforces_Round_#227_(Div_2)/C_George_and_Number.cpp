#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
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
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    string prec = "";
    string actOri = "";
    int res = 0;
    string blabla = s;
    for(int c=0;c<s.size();c++)
    {
        actOri = s[c] + actOri ;
        int taille_tot = s.size()-c-1 + actOri.size();
        char maxi_act = s[s.size()-1];
        if(s[c] != '0' && (taille_tot> prec.size()|| (taille_tot==prec.size()&&maxi_act>=prec[0])))
        {
          //  cout<<prec<<" "<<actOri<<" "<<taille_tot<<endl;
            prec = actOri;
            res++;
            actOri="";
        }
    }
    cout<<res;
}