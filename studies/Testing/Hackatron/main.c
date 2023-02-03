#include <stdio.h>
#include <string.h>

int main() {
    typedef struct {
        char sign[20];
        char Name[20];
    } Team;
   typedef struct {
       Team Team ;
       int jurypoints;
       int pubpoints;
   }Hackatron;

    Hackatron Team1;
    Team1.jurypoints = 10;
    Team1.pubpoints = 8;
    strcpy(Team1.Team.Name,"Peter");
    sprintf(Team1.Team.sign,"Nix");

    printf("Name = %s, Sign: %s, Points: %d/%d",Team1.Team.Name,Team1.Team.sign,Team1.jurypoints,Team1.pubpoints);

}
