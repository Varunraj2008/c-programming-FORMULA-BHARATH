#include<stdio.h>
#define LAYERS 4
int main()
{
 char material[LAYERS][30]=
 {
 "CFRP",
 "Al Honeycomb",
 "Al Foam",
 "PU Foam"
 };
 float density[LAYERS]=
 {
 1600,
 80,
 450,
 120
 };
 float volume[LAYERS]=
 {
 0.00040,
 0.00140,
 0.00120,
 0.00100
 };
 float materialSEA[LAYERS]=
 {
 1.15,
 26.30,
 4.77,
 9.20
 };
 float ratio[LAYERS]=
 {
 10,
 40,
 35,
 15
 };
 float totalEnergy=7358;
 float totalMass=0;
 float energy;
 float mass;
 float sea;
 float efficiency;
 float bestEfficiency=0;
 int bestLayer=0;
 printf("===========================================================\n");
 printf(" ENERGY DISTRIBUTION OPTIMIZATION PROGRAM\n");
 printf("===========================================================\n\n");

printf("===============================================================================================\n");
 printf("Material Mass(kg) Energy(J) SEA(kJ/kg) Efficiency(%%)\n");

printf("===============================================================================================\n");
 for(int i=0;i<LAYERS;i++)
 {
 mass=density[i]*volume[i];
 energy=(ratio[i]/100.0)*totalEnergy;
 sea=energy/(mass*1000);
 efficiency=(sea/materialSEA[i])*100.0;
 totalMass+=mass;
 printf("%-15s %10.4f %12.2f %12.2f %15.2f\n",
 material[i],
 mass,
 energy,
 sea,
 efficiency);
 if(efficiency>bestEfficiency)
 {
 bestEfficiency=efficiency;
 bestLayer=i;
 }
 }

printf("===============================================================================================\n");
 printf("\nTotal Mass = %.4f kg\n",totalMass);
 printf("Total Energy = %.2f J\n",totalEnergy);
 printf("Overall SEA = %.2f kJ/kg\n",
 totalEnergy/(totalMass*1000));
 printf("\n=============================================\n");
 printf("BEST PERFORMING LAYER\n");
 printf("=============================================\n");
 printf("Material : %s\n",
 material[bestLayer]);
 printf("Efficiency = %.2f %%\n",
 bestEfficiency);
 return 0;
}
