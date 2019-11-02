#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
 
    int n;
    cin>>n;
    string vilainCanard="";
    string suffixe="";
    int nbZeros = 0;
    vector<string> v(n);
    for(int c=0;c<n;c++) {
        cin>>v[c];
        int nbOnes = 0;
        for(int c2=0;c2<v[c].size();c2++) {
            if(v[c][c2]=='1') nbOnes++;
            else if(v[c][c2]>'1') {vilainCanard=v[c];goto end;}
            if(nbOnes>1){vilainCanard=v[c];goto end;}
        }
        if(v[c]=="0") {cout<<"0";return 0;}
        nbZeros+=(v[c].size()-1);
        end:;
    }
    cout<<(vilainCanard.size()==0?"1":vilainCanard)<<string(nbZeros,'0');
}