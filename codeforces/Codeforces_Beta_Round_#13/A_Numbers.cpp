#include <iostream>
 
unsigned long long int PGCD (unsigned long long int a,unsigned long long int b)
{
        if(a==b)
                return a;
        if(a<b)
                return PGCD(a,b-a);
        return PGCD(a-b,b);
}
 
int main()
{
        unsigned long long int n;
        std::cin>>n;
        unsigned long long int num=0;
        unsigned long long denom=n-2;
        for(unsigned long long int c=2;c<=n-1;c++)
        {
                int n2=n;
                while(n2!=0)
                {
                        num+=n2%c;
                        n2/=c;
                }
        }
        unsigned long long int z=PGCD(num,denom);
        if(z>1)
        {
                num/=z;
                denom/=z;
        }
        std::cout<<num<<"/"<<denom;
}