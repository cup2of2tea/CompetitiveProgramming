#include <iostream>
#include <map>
#include <vector>
#include <string>
 
std::string notes[12]={"C","C#","D","D#","E","F","F#","G","G#","A","B","H"};
 
 
 
int main()
{
        std::vector <std::string> v;
        v.resize(3);
        std::cin>>v[0]>>v[1]>>v[2];
        for(int c2=0;c2<12;c2++)
                for(int c3=0;c3<3;c3++)
                        if(notes[c2]==v[c3]&&(notes[(c2+7)%12]==v[(c3+2)%3]||notes[(c2+7)%12]==v[(c3+1)%3]))
                        {
                                if(notes[(c2+3)%12]==v[(c3+2)%3]||notes[(c2+3)%12]==v[(c3+1)%3])
                                {
                                        std::cout<<"minor";
                                        return 0;
                                }
                                else if(notes[(c2+4)%12]==v[(c3+2)%3]||notes[(c2+4)%12]==v[(c3+1)%3])
                                {
                                        std::cout<<"major";
                                        return 0;
                                }
                        }
        std::cout<<"strange";
}