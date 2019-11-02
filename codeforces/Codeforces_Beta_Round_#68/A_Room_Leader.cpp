 #include <iostream>
 
 
 using namespace std;
 
 
 int main()
 {
     int plus,moins,A,B,C,D,E;
      string joueur;
      string best="";
     int meilleur_score=-100000;
     int nb_joueurs;
     cin>>nb_joueurs;
    for(int c=0;c<nb_joueurs;c++)
    {
        cin>>joueur>>plus>>moins>>A>>B>>C>>D>>E;
         int total=plus*100-moins*50+A+B+C+D+E;
         if(total>meilleur_score)
         {
             meilleur_score=total;
             best=joueur;
         }
     }
     cout<<best;
 }