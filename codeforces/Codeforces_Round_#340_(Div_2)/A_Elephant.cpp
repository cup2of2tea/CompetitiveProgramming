#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
 
//    ifstream in("input.txt");
//    ofstream out("output.txt");
//#define cin in
//#define cout out
 
    int N;
    cin>>N;
    cout<<min(1,N%5)+N/5;
    return 0;
}
//A : dp[100000][4]
//B :