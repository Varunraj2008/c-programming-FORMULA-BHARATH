#include<stdio.h>
#define MATERIALS 6
int main()
{
 float density[MATERIALS]={200,300,400,500,600,700};
 float sea[MATERIALS]={5.60,5.30,5.00,4.77,4.40,4.10};
 float width,height,thickness;
 float volume;
 float mass;
 float energy;
 float plateau;
 float efficiency;
 float score;
 float bestScore=-1.0;
 int bestIndex=0;
 printf("=============================================\n");
 printf(" ALUMINIUM FOAM DENSITY OPTIMIZATION\n");
 printf("=============================================\n\n");
 printf("Width (mm) : ");
 scanf("%f",&width);
 printf("Height (mm) : ");
 scanf("%f",&height);
 printf("Thickness (mm) : ");
 scanf("%f",&thickness);
 volume=width*height*thickness;
 volume/=1000000000.0;

printf("\n===========================================================================================================\n");
 printf("Density Mass(kg) Energy(J) SEA Plateau(MPa) Efficiency Score\n");

printf("===========================================================================================================\n");
 for(int i=0;i<MATERIALS;i++)
 {
 mass=density[i]*volume;
 energy=sea[i]*mass*1000.0;
 plateau=0.045*density[i];
 efficiency=energy/(mass*1000.0);
 score=
 0.40*(energy/7350.0)+
 0.30*(sea[i]/6.0)+
 0.20*(plateau/30.0)+
 0.10*(1.0-mass/1.5);
 printf("%6.0f %10.4f %12.2f %7.2f %12.2f %12.2f %8.3f\n",
 density[i],
 mass,
 energy,
 sea[i],
 plateau,
 efficiency,
 score);
 if(score>bestScore)
 {
 bestScore=score;
 bestIndex=i;
 }
 }
 printf("\n===================================================\n");
 printf("OPTIMUM ALUMINIUM FOAM\n");
 printf("===================================================\n");
 printf("Density : %.0f kg/m3\n",
 density[bestIndex]);
 printf("SEA : %.2f kJ/kg\n",
 sea[bestIndex]);
 printf("Optimization Score : %.3f\n",
 bestScore);
 printf("===================================================\n");
 return 0;
}
