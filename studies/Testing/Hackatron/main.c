#include <stdio.h>
#include <string.h>

int main() {
    typedef struct {
        char sign[20];
        char Name[20];
    } Team;
   typedef struct {

       int jurypoints;
       int pubpoints;
   }points;
   typedef struct {
       Team Team ;
       points points;
   }Hackatron;

    Hackatron competition[10];
    competition[0].points.jurypoints = 10;
    competition[0].points.pubpoints = 8;
    strcpy(competition[0].Team.Name,"Peter");
    sprintf(competition[0].Team.sign,"Nix");
    printf("Name = %s, Sign: %s, Points: %d/%d",competition[0].Team.Name,competition[0].Team.sign,competition[0].points.jurypoints,competition[0].points.pubpoints);

    char sign[20];
    char Name[20];
    int jurypoints =0;
    int pubpoints= 0;
    printf("Geben Sie Ihren Zeichen ein:");
    scanf("%s",&sign);
    printf("Geben Sie Ihren Namen ein:");
    scanf("%s",&Name);
    printf("Geben Sie Ihren Jurypoints ein:");
    scanf("%d",&jurypoints);
    printf("Geben Sie Ihren Pubpoints ein:");
    scanf("%d",&pubpoints);
    strcpy(competition[1].Team.sign, sign);
    strcpy(competition[1].Team.Name, Name);
    competition[1].points.jurypoints = jurypoints;
    competition[1].points.pubpoints = pubpoints;
    printf("Name = %s, Sign: %s, Points: %d/%d",competition[1].Team.Name,competition[1].Team.sign,competition[1].points.jurypoints,competition[1].points.pubpoints);

    return 0;
}
