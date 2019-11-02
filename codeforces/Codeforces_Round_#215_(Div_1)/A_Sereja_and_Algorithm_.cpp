#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;
 
 
main()
{
    string s;
    int m,l,r;
    int test[3];
    int xyz[3][100005];
    cin>>s;
   // cin >> s;
    cin >> m;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<3;j++) xyz[j][i+1] =  xyz[j][i] ;
        xyz[s[i]-'x'][i+1]++;
    }
 
    for(int i=0;i<m;i++) {
        cin>>l>>r;
        if(r-l<2){
            cout << "YES"<<endl;
            continue;
        }
        for(int j=0;j<3;j++)  test[j]=xyz[j][r]-xyz[j][l-1];
        sort(test,test+3);
        if(test[2]>test[0]+1)
            cout << "NO" << endl;
        else
            cout << "YES"<<endl;
    }
}
 