#include <iostream>
 
int main()
{
    unsigned long long int nb_personnes,nb_chips;
    std::cin>>nb_personnes>>nb_chips;
    unsigned long long int machin=nb_personnes*(nb_personnes+1)/2;
    nb_chips%=machin;
    for(int c=1;c<=nb_personnes;c++)
    {
        if(nb_chips<c)
            break;
        nb_chips-=c;
    }
    std::cout<<nb_chips;
}