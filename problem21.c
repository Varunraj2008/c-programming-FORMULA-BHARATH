#include<stdio.h>
#define DISTANCES 9
#define FACTORS 4
int main()
{
 float crushDistance[DISTANCES]=
 {
 40,50,60,70,80,90,100,110,120
 };
 float peakFactor[FACTORS]=
 {
 1.20,1.30,1.40,1.50
 };
 float energy=7358.0;
 float vehicleMass=300.0;
 float avgForce;
 float peakForce;
 float acceleration;
 float peakG;
 float safety;
 float score;
 float bestScore=-1;
 float bestDistance=0;
 float bestFactor=0;

printf("=============================================================\n");
 printf(" PEAK IMPACT FORCE OPTIMIZATION PROGRAM\n");

printf("=============================================================\n\n");

printf("===============================================================================================================\n");
 printf("Distance Factor AvgForce(N) PeakForce(N) PeakG Safety Score\n");

printf("===============================================================================================================\n");
 for(int i=0;i<DISTANCES;i++)
 {
 avgForce=energy/(crushDistance[i]/1000.0);
 for(int j=0;j<FACTORS;j++)
 {
 peakForce=
 avgForce*peakFactor[j];
 acceleration=
 peakForce/vehicleMass;
 peakG=
 acceleration/9.81;
 safety=
 40.0/peakG;
 score=
 0.5*safety+
 0.3*(100000.0/peakForce)+
 0.2*(40.0/peakG);
 printf("%7.0f %7.2f %12.0f %13.0f %8.2f %8.2f %8.3f\n",
 crushDistance[i],
 peakFactor[j],
 avgForce,
 peakForce,
 peakG,
 safety,
 score);
 if(score>bestScore)
 {
 bestScore=score;
 bestDistance=
 crushDistance[i];
 bestFactor=
 peakFactor[j];
 }
 }
 }
 printf("\n=====================================================\n");
 printf("OPTIMUM DESIGN\n");
 printf("=====================================================\n");
 printf("Crush Distance : %.0f mm\n",
 bestDistance);
 printf("Peak Factor : %.2f\n",
 bestFactor);
 printf("Best Score : %.3f\n",
 bestScore);
 printf("=====================================================\n");
 return 0;
}
