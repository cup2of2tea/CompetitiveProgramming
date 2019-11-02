#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int nbOp;
    cin>>nbOp;
 
    int act = 0;
    int maxi = 0;
    vector<bool> presents(1e6+10,false);
    while(nbOp--)
    {
        string op;
        int N;
        cin>>op>>N;
        if(op == "+")
        {
                act++;
                presents[N] = true;
        }
        else if(op == "-")
        {
            if(presents[N])
            {
                act--;
                presents[N] = false;
            }
            else
            {
                maxi++;
            }
        }
        maxi = max(maxi,act);
    }
    cout<<maxi;
}