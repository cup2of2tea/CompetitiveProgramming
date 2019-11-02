#include <iostream>
#include <vector>
 
using namespace std;
 
 
int main()
{
        long long int N;
        cin>>N;
        vector <long long int> cups(N);
        long long int total=0;
        for(int c=0;c<N;c++)
        {
                cin>>cups[c];
                total+=cups[c];
        }
        if(total%N)
                cout<<"Unrecoverable configuration.";
        else
        {
                long long int moyenne=total/N;
                int prob=0;
                int b[2];
                long long int z;
                for(int c=0;c<N;c++)
                {
                        if(cups[c]!=moyenne)
                        {
                                if(prob!=2)
                                {
                                        b[prob]=c;
                                                if(cups[c]>moyenne)
                                                        z=cups[c]-moyenne;
                                                else
                                                        z=moyenne-cups[c];
                                }
                                prob++;
                        }
                        if(prob>2)
                        {
                                cout<<"Unrecoverable configuration.";
                                return 0;
                        }
                }
                if(prob==0)
                {
                        cout<<"Exemplary pages.";return 0;
                }
                
                
                else if(prob==2)
                {if(cups[b[0]]>cups[b[1]])
                        swap(b[0],b[1]);
                        cout<<z<<" ml. from cup #"<<b[0]+1<<" to cup #"<<b[1]+1<<".";
                }
        }
}
     