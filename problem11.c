#include<stdio.h>
int main()
{
 float density;
 float width;
 float height;
 float sea;
 int tMin;
 int tMax;
 int step;
 float volume;
 float mass;
 float energy;
 float bestMass = 100000;
 int bestThickness = 0;
 printf("=====================================\n");
 printf("THICKNESS SWEEP OPTIMIZATION PROGRAM\n");
 printf("=====================================\n\n");
 printf("Density (kg/m3) : ");
 scanf("%f",&density);
 printf("Width (mm) : ");
 scanf("%f",&width);
 printf("Height (mm) : ");
 scanf("%f",&height);
 printf("SEA (kJ/kg) : ");
 scanf("%f",&sea);
 printf("Minimum Thickness (mm) : ");
 scanf("%d",&tMin);
 printf("Maximum Thickness (mm) : ");
 scanf("%d",&tMax);
 printf("Thickness Step (mm) : ");
 scanf("%d",&step);
 printf("\n--------------------------------------------------------------\n");
 printf("Thickness Mass(kg) Energy(J)\n");
 printf("--------------------------------------------------------------\n");
 for(int t=tMin;t<=tMax;t=t+step)
 {
 volume = width*height*t;
 volume = volume/1000000000.0;
 mass = density*volume;
 energy = sea*mass*1000;
 printf("%5d %15.4f %15.2f\n",
 t,mass,energy);
 if(energy>=7350)
 {
 if(mass<bestMass)
 {
 bestMass = mass;
 bestThickness = t;
 }
 }
 }
 printf("\n=====================================\n");
 if(bestThickness==0)
 {
 printf("NO FEASIBLE DESIGN FOUND\n");
 }
 else
 {
 printf("OPTIMUM THICKNESS = %d mm\n",
 bestThickness);
 printf("MINIMUM MASS = %.4f kg\n",
 bestMass);
 }
 printf("=====================================\n");
 return 0;
}
