#include<stdio.h>
#define DISTANCES 9
#define FACTORS 4
int main()
{
 float distance[DISTANCES]={40,50,60,70,80,90,100,110,120};
 float factor[FACTORS]={1.20,1.30,1.40,1.50};
 float energy=7358.0;
 float vehicleMass=300.0;
 float avgForce;
 float peakForce;
 float acceleration;
 float peakG;
 float injury;
 float safety;
 float score;
 float bestScore=-1;
 float bestDistance=0;
 float bestFactor=0;

printf("=============================================================\n");
 printf(" PEAK DECELERATION OPTIMIZATION PROGRAM\n");

printf("=============================================================\n\n");

printf("=============================================================================================================================\n");
 printf("Dist(mm) Factor AvgForce(N) PeakForce(N) Accel(m/s2) PeakG Injury Safety Score\n");

printf("=============================================================================================================================\n");
 for(int i=0;i<DISTANCES;i++)
 {
 avgForce=energy/(distance[i]/1000.0);
 for(int j=0;j<FACTORS;j++)
 {
 peakForce=avgForce*factor[j];
 acceleration=peakForce/vehicleMass;
 peakG=acceleration/9.81;
 injury=peakG/40.0;
 safety=40.0/peakG;
 score=
 0.40*safety+
 0.30*(1.0-peakG/100.0)+
 0.30*(distance[i]/120.0);
 printf("%6.0f %6.2f %12.0f %12.0f %13.2f %8.2f %8.2f %8.2f %8.3f\n",
 distance[i],
 factor[j],
 avgForce,
 peakForce,
 acceleration,
 peakG,
 injury,
 safety,
 score);
 if(score>bestScore)
 {
 bestScore=score;
 bestDistance=distance[i];
 bestFactor=factor[j];
 }
 }
 }

printf("\n=============================================================\n");
 printf("OPTIMUM DESIGN\n");

printf("=============================================================\n");
 printf("Crush Distance : %.0f mm\n",bestDistance);
 printf("Peak Factor : %.2f\n",bestFactor);
 printf("Best Score : %.3f\n",bestScore);

printf("=============================================================\n");
 return 0;
}
