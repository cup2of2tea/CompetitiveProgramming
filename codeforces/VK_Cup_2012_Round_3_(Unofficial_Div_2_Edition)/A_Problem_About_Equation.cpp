#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
 
int main()
{
        int n;
        double b;
        cin>>n>>b;
        double avg;
        vector<double> res(n);
        vector<double> v(n);
        for(int c=0;c<n;c++)
        {
                cin>>v[c];
                b+=v[c];
        }
        avg=(double)(b)/(double)(n);
        for(int c=0;c<n;c++)
        {
                if(v[c]>avg)
                {
                        cout<<-1;
                        return 0;
                }
                res[c]=(avg-v[c]);
        }
        for(int c=0;c<n;c++)
                cout<<fixed<<setprecision(10)<<res[c]<<endl;
}