#include<stdio.h>
int main()
{
 float cellSize[6]={3.2,4.8,6.4,9.5,12.7,19.0};
 float density;
 float width;
 float height;
 float thickness;
 float sea;
 float volume;
 float mass;
 float energy;
 float stress;
 float efficiency;
 float score;
 float bestScore=0;
 float bestCell=0;
 printf("===============================================\n");
 printf(" ALUMINIUM HONEYCOMB CELL SIZE OPTIMIZATION\n");
 printf("===============================================\n\n");
 printf("Density (kg/m3) : ");
 scanf("%f",&density);
 printf("Width (mm) : ");
 scanf("%f",&width);
 printf("Height (mm) : ");
 scanf("%f",&height);
 printf("Thickness (mm) : ");
 scanf("%f",&thickness);
 printf("SEA (kJ/kg) : ");
 scanf("%f",&sea);
 volume=width*height*thickness;
 volume/=1000000000.0;

printf("\n====================================================================================\n");
 printf("Cell(mm) Mass(kg) Energy(J) CrushStress(MPa) Efficiency(%%) Score\n");

printf("====================================================================================\n");
 for(int i=0;i<6;i++)
 {
 mass=density*volume;
 energy=sea*mass*1000;
 stress=250.0/cellSize[i];
 efficiency=100.0/cellSize[i];
 score=(energy*efficiency)/(stress+1);
 printf("%7.1f %10.4f %12.2f %15.2f %15.2f %12.2f\n",
 cellSize[i],
 mass,
 energy,
 stress,
 efficiency,
 score);
 if(score>bestScore)
 {
 bestScore=score;
 bestCell=cellSize[i];
 }
 }
 printf("\n===============================================\n");
 printf("OPTIMUM CELL SIZE = %.1f mm\n",bestCell);
 printf("BEST SCORE = %.2f\n",bestScore);
 printf("===============================================\n");
 return 0;
}
