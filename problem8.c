#include<stdio.h>
int main()
{
 float totalEnergy;
 float ratio[4];
 float energy[4];
 int i;
 printf("ENERGY DISTRIBUTION CALCULATOR\n\n");
 printf("Enter Total Impact Energy (J): ");
 scanf("%f",&totalEnergy);
 for(i=0;i<4;i++)
 {
 printf("Energy Ratio for Layer %d (%%): ",i+1);
 scanf("%f",&ratio[i]);
 }
 printf("\n---------------------------------------------\n");
 printf("Layer\tRatio(%%)\tEnergy(J)\n");
 printf("---------------------------------------------\n");
 for(i=0;i<4;i++)
 {
 energy[i]=totalEnergy*ratio[i]/100.0;
 printf("%d\t%.2f\t\t%.2f\n",
 i+1,
 ratio[i],
 energy[i]);
 }
 printf("---------------------------------------------\n");
 return 0;
}