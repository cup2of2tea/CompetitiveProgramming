#include <iostream>
#include <vector>
 
using namespace std;
int main()
{
        int d,sum;
        cin>>d>>sum;
        int act=0;
        vector<int> max_times(d);
        vector<int> min_times(d);
        for(int c=0;c<d;c++)
        {
                int a,b;
                cin>>a>>b;
                act+=a;
                min_times[c]=a;
                max_times[c]=b;
        }
        if(act>sum)
        {
            cout<<"NO";
            return 0;
        }
        for(int c=0;c<d;c++)
        {
                if(max_times[c]-min_times[c]+act>=sum)
                {
                        cout<<"YES"<<endl;
                        for(int c2=0;c2<c;c2++)
                                cout<<max_times[c2]<<" ";
                        cout<<min_times[c]+sum-act<<" ";
                        for(int c2=c+1;c2<d;c2++)
                                cout<<min_times[c2]<<" ";
                        return 0;
                }
                else
                        act+=max_times[c]-min_times[c];
        }
        cout<<"NO";
}