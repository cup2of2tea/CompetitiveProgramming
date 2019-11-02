#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
 
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    int c=0;
    int mini = (*min_element(v.begin(),v.end()));
    while(v[c]!=mini)
    {
        c++;
    }
    for(int compteur=0;compteur<n&&v[((c-1)+n)%n]==mini;c=(c-1+n)%n,compteur++);
    for(int c2=0;c2+1<n;c2++)
    {
        if(v[(c2+c+1)%n]<v[(c2+c)%n])
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<(n-c)%n;
    return 0;
}