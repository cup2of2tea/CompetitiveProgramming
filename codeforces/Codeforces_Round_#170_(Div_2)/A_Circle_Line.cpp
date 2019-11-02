#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<int> distances(n);
    int tot=0;
    for(int c=0;c<n;c++)
    {
        cin>>distances[c];
        tot+=distances[c];
    }
    int s,t;
    cin>>s>>t;
    if(s>t)
        swap(s,t);
    s--;
    t--;
    int sum1=0;
    for(int c=s;c<t;c++)
    {
        sum1+=distances[c];
    }
    cout<<min(sum1,tot-sum1);
}