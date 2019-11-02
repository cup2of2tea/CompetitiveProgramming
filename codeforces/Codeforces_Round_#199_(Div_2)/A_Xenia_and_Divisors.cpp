#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<int> v(8,0);
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        if(z==5)
        {
            cout<<-1;
            return 0;
        }
        v[z]++;
    }
    if(v[1]==n/3&&v[2]+v[3]==n/3&&v[3]<=v[6])
    {
        for(int c=0;c<n/3;c++)
        {
            cout<<"1 ";
            if(v[3])
            {
                v[3]--;
                cout<<"3 6";
            }
            else if(v[4])
            {v[4]--;
                cout<<"2 4";
            }
            else cout<<"2 6";
            cout<<endl;
        }
    }
    else cout<<-1;
}