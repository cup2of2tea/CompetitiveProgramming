#include <iostream>
 
int main()
{
    long long int a;
    std::cin>>a;
    long long int tot=1;
    for(long long int c=0;c<a;c++)
       tot+=12*c;
    std::cout<<tot;
}