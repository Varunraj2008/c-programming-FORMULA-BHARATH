#include<stdio.h>
int main()
{
 float width;
 float height;
 float thickness;
 float sea;
 int dMin;
 int dMax;
 int step;
 float area;
 float volume;
 float mass;
 float energy;
 float bestMass = 999999.0;
 int bestDensity = 0;
 printf("\n=============================================\n");
 printf(" DENSITY SWEEP OPTIMIZATION PROGRAM\n");
 printf("=============================================\n\n");
 printf("Width (mm) : ");
 scanf("%f",&width);
 printf("Height (mm) : ");
 scanf("%f",&height);
 printf("Thickness (mm) : ");
 scanf("%f",&thickness);
 printf("SEA (kJ/kg) : ");
 scanf("%f",&sea);
 printf("Minimum Density (kg/m3) : ");
 scanf("%d",&dMin);
 printf("Maximum Density (kg/m3) : ");
 scanf("%d",&dMax);
 printf("Density Step (kg/m3) : ");
 scanf("%d",&step);
 area = width * height;
 volume = area * thickness;
 volume = volume / 1000000000.0;

printf("\n====================================================================================\n");
 printf("Density Volume(m3) Mass(kg) Energy(J) SEA(kJ/kg)\n");

printf("====================================================================================\n");
 for(int density=dMin; density<=dMax; density+=step)
 {
 mass = density * volume;
 energy = sea * mass * 1000.0;
 printf("%6d %15.6f %15.4f %15.2f %15.2f\n",
 density,
 volume,
 mass,
 energy,
 sea);
 if(energy>=7350)
 {
 if(mass<bestMass)
 {
 bestMass = mass;
 bestDensity = density;
 }
 }
 }
 printf("\n=============================================\n");
 if(bestDensity==0)
 {
 printf("NO FEASIBLE MATERIAL FOUND\n");
 }
 else
 {
 printf("OPTIMUM DENSITY = %d kg/m3\n",bestDensity);
 printf("MINIMUM MASS = %.4f kg\n",bestMass);
 }
 printf("=============================================\n");
 return 0;
}