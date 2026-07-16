#include <stdio.h>
#define MATERIALS 6
#define LAYERS 4
struct Material
{
 char name[30];
 float density;
 float sea;
};
int main()
{
 struct Material mat[MATERIALS] =
 {
 {"CFRP",1600,1.15},
 {"Al Honeycomb",80,26.30},
 {"Al Foam",450,4.77},
 {"PU Foam",120,9.20},
 {"PVC Foam",70,12.50},
 {"PET Foam",110,11.20}
 };
 float width[LAYERS]={70,80,90,100};
 float height[LAYERS]={140,160,180,200};
 float thickness[LAYERS]={20,70,60,50};
 float volume,mass,energy;
 float totalMass=0.0;
 float totalEnergy=0.0;
 int choice[LAYERS];
 printf("=============================================\n");
 printf(" HYBRID MATERIAL COMBINATION GENERATOR\n");
 printf("=============================================\n\n");
 printf("Available Materials\n\n");
 for(int i=0;i<MATERIALS;i++)
 {
 printf("%d. %-15s Density=%6.1f SEA=%5.2f\n",
 i+1,
 mat[i].name,
 mat[i].density,
 mat[i].sea);
 }
 printf("\nSelect material for each layer\n\n");
 for(int i=0;i<LAYERS;i++)
 {
 printf("Layer %d Material ID : ",i+1);
 scanf("%d",&choice[i]);
 choice[i]--;
 if(choice[i]<0 || choice[i]>=MATERIALS)
 {
 printf("Invalid Selection\n");
 return 0;
 }
 }

printf("\n==========================================================================\n");
 printf("Layer Material Mass(kg) Energy(J)\n");

printf("==========================================================================\n");
 for(int i=0;i<LAYERS;i++)
 {
 volume = width[i]*height[i]*thickness[i];
 volume = volume/1000000000.0;
 mass = mat[choice[i]].density * volume;
 energy = mat[choice[i]].sea * mass *1000.0;
 totalMass += mass;
 totalEnergy += energy;
 printf("%3d %-15s %10.4f %15.2f\n",
 i+1,
 mat[choice[i]].name,
 mass,
 energy);
 }

printf("==========================================================================\n");
 printf("Total Mass = %.4f kg\n",totalMass);
 printf("Total Energy = %.2f J\n",totalEnergy);
 printf("Overall SEA = %.2f kJ/kg\n",
 totalEnergy/(1000.0*totalMass));
 if(totalEnergy>=7350)
 printf("\nSTATUS : FEASIBLE DESIGN\n");
 else
 printf("\nSTATUS : NOT FEASIBLE\n");
 return 0;
}