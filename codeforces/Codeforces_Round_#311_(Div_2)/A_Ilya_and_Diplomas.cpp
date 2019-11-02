#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    int n;
    cin>>n;
    vector<int> mini(3),maxi(3);
    for(int c=0;c<3;c++) cin>>mini[c]>>maxi[c];
    int count1 = min(maxi[0],n-mini[1]-mini[2]);
    n -= count1;
    int count2 = min(maxi[1],n-mini[2]);
    n -= count2;
    cout<<count1<<" "<<count2<<" "<<n<<endl;
    return 0;
}