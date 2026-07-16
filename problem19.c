#include<stdio.h>
#define LAYUPS 6
struct CFRP
{
 char layup[40];
 float sea;
 float stiffness;
 float delamination;
};
int main()
{
 struct CFRP laminate[LAYUPS]=
 {
 {"[0]8",0.95,10,4},
 {"[0/90]2s",1.10,9,6},
 {"[+45/-45]2s",1.45,6,10},
 {"[0/+45/-45/90]s",1.35,8,9},
 {"[0/45/-45/90]s",1.30,8,9},
 {"[0/0/+45/-45/90]s",1.20,9,8}
 };
 float width,height,thickness,density;
 float volume,mass,energy;
 float score;
 float bestScore=-1;
 int bestIndex=0;
 printf("=============================================\n");
 printf(" CFRP PLY ORIENTATION OPTIMIZATION\n");
 printf("=============================================\n\n");
 printf("Width (mm): ");
 scanf("%f",&width);
 printf("Height (mm): ");
 scanf("%f",&height);
 printf("Thickness (mm): ");
 scanf("%f",&thickness);
 printf("Density (kg/m3): ");
 scanf("%f",&density);
 volume=width*height*thickness;
 volume/=1000000000.0;

printf("\n=========================================================================================================\n");
 printf("Layup Mass Energy SEA Stiffness Delamination Score\n");

printf("=========================================================================================================\n");
 for(int i=0;i<LAYUPS;i++)
 {
 mass=density*volume;
 energy=laminate[i].sea*mass*1000;
 score=
 0.40*(energy/7350.0)+
 0.30*(laminate[i].sea/1.50)+
 0.20*(laminate[i].stiffness/10.0)+
 0.10*(laminate[i].delamination/10.0);
 printf("%-24s %7.4f %9.2f %6.2f %10.2f %14.2f %10.3f\n",
 laminate[i].layup,
 mass,
 energy,
 laminate[i].sea,
 laminate[i].stiffness,
 laminate[i].delamination,
 score);
 if(score>bestScore)
 {
 bestScore=score;
 bestIndex=i;
 }
 }
 printf("\n====================================================\n");
 printf("OPTIMUM CFRP LAMINATE\n");
 printf("====================================================\n");
 printf("Layup : %s\n",
 laminate[bestIndex].layup);
 printf("SEA : %.2f kJ/kg\n",
 laminate[bestIndex].sea);
 printf("Optimization Score : %.3f\n",
 bestScore);
 printf("====================================================\n");
 return 0;
}
