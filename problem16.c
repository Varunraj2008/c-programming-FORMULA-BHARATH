#include <stdio.h>
#define LAYERS 4
#define SEQUENCES 6
struct Material
{
 char name[25];
 float density;
 float sea;
};
int main()
{
 struct Material mat[4]=
 {
 {"CFRP",1600,1.15},
 {"Al Honeycomb",80,26.30},
 {"Al Foam",450,4.77},
 {"PU Foam",120,9.20}
 };
 float width[4]={70,80,90,100};
 float height[4]={140,160,180,200};
 float thickness[4]={20,70,60,50};
 int sequence[SEQUENCES][LAYERS]=
 {
 {0,1,2,3},
 {0,2,1,3},
 {1,0,2,3},
 {1,2,3,0},
 {2,1,0,3},
 {3,2,1,0}
 };
 int weight[4]={4,3,2,1};
 float bestScore=0.0;
 int bestSequence=0;

printf("\n==============================================================\n"
);
 printf(" LAYER SEQUENCE OPTIMIZATION PROGRAM\n");

printf("==============================================================\n");
 for(int s=0;s<SEQUENCES;s++)
 {
 float totalMass=0;
 float totalEnergy=0;
 float score=0;
 printf("\n----------------------------------------------------------\n");
 printf("Sequence %d\n",s+1);
 printf("----------------------------------------------------------\n");
 for(int i=0;i<LAYERS;i++)
 {
 int m=sequence[s][i];
 float volume=
 width[i]*height[i]*thickness[i];
 volume/=1000000000.0;
 float mass=
 mat[m].density*volume;
 float energy=
 mat[m].sea*mass*1000;
 score+=mat[m].sea*weight[i];
 totalMass+=mass;
 totalEnergy+=energy;
 printf("%d -> %-15s Mass=%7.4f Energy=%8.2f\n",
 i+1,
 mat[m].name,
 mass,
 energy);
 }
 printf("\nTotal Mass = %.4f kg\n",
 totalMass);
 printf("Total Energy = %.2f J\n",
 totalEnergy);
 printf("Sequence Score = %.2f\n",
 score);
 if(score>bestScore)
 {
 bestScore=score;
 bestSequence=s;
 }
 }

printf("\n==============================================================\n"
);
 printf("BEST LAYER SEQUENCE\n");

printf("==============================================================\n");
 for(int i=0;i<LAYERS;i++)
 {
 printf("%d. %s\n",
 i+1,
 mat[sequence[bestSequence][i]].name);
 }
 printf("\nBest Score = %.2f\n",
 bestScore);
 return 0;
}
