#include<stdio.h>
int main()
{
 float density;
 float width;
 float thickness;
 float sea;
 int hMin;
 int hMax;
 int step;
 float area;
 float volume;
 float mass;
 float energy;
 float bestMass = 1000000.0;
 int bestHeight = 0;
 printf("\n===========================================\n");
 printf(" HEIGHT SWEEP OPTIMIZATION PROGRAM\n");
 printf("===========================================\n\n");
 printf("Density (kg/m3) : ");
 scanf("%f",&density);
 printf("Width (mm) : ");
 scanf("%f",&width);
 printf("Thickness (mm) : ");
 scanf("%f",&thickness);
 printf("SEA (kJ/kg) : ");
 scanf("%f",&sea);
 printf("Minimum Height (mm) : ");
 scanf("%d",&hMin);
 printf("Maximum Height (mm) : ");
 scanf("%d",&hMax);
 printf("Height Step (mm) : ");
 scanf("%d",&step);

printf("=============================================================================\n\n");
 printf("Height Area(mm2) Volume(m3) Mass(kg) Energy(J)\n");

printf("=============================================================================\n\n");
 for(int height=hMin;height<=hMax;height+=step)
 {
 area = width * height;
 volume = area * thickness;
 volume = volume / 1000000000.0;
 mass = density * volume;
 energy = sea * mass * 1000;
 printf("%5d %15.2f %15.6f %12.4f %15.2f\n",
 height,
 area,
 volume,
 mass,
 energy);
 if(energy>=7350)
 {
 if(mass<bestMass)
 {
 bestMass = mass;
 bestHeight = height;
 }
 }
 }
 printf("\n===========================================\n");
 if(bestHeight==0)
 {
 printf("NO FEASIBLE HEIGHT FOUND\n");
 }
 else
 {
 printf("OPTIMUM HEIGHT = %d mm\n",bestHeight);
 printf("MINIMUM MASS = %.4f kg\n",bestMass);
 }
 printf("===========================================\n");
 return 0;
}