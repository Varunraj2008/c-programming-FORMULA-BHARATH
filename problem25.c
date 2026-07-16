#include<stdio.h>
int main()
{
 float density[4]={1600,80,450,120};
 float materialSEA[4]={1.15,26.30,4.77,9.20};
 float bestScore=-1;
 float bestMass;
 float bestEnergy;
 float bestSEA;
 float bestForce;
 float bestPeakG;
 float bestSafety;
 int bestTc,bestTh,bestTf,bestTp;
 int bestWidth,bestHeight;
 printf("Searching Complete Design Space...\n");
 for(int tc=10;tc<=20;tc+=1)
 {
 for(int th=140;th<=180;th+=1)
 {
 for(int tf=10;tf<=30;tf+=1)
 {
 for(int tp=20;tp<=50;tp+=1)
 {
 for(int width=200;width<=260;width+=1)
 {
 for(int height=200;height<=260;height+=20)
 {
 int thickness[4]={tc,th,tf,tp};
 float totalMass=0;
 float totalEnergy=0;
 for(int i=0;i<4;i++)
 {
 float volume;
 volume=
 width*
 height*
 thickness[i];
 volume=
 volume/1000000000.0;
 float mass=
 density[i]*volume;
 float energy=
 materialSEA[i]*mass*1000;
 totalMass+=mass;
 totalEnergy+=energy;
 }
 float overallSEA=
 totalEnergy/
 (1000*totalMass);
 float totalThickness=
 tc+th+tf+tp;
 float peakForce=
 totalEnergy/
 (totalThickness/1000.0);
 float peakG=
 peakForce/
 (300*9.81);
 float safety=
 40.0/peakG;
 if(totalEnergy>=10000 &&
 totalMass<=2.0 &&
 peakForce<=80000 &&
 peakG<=40 &&
 overallSEA>=5.0)
 {
 float score=
 0.45*(totalEnergy/10000.0)+
 0.30*(1.0-totalMass/2.0)+
 0.15*(overallSEA/6.0)+
 0.05*(40.0/peakG)+
 0.05*(80000.0/peakForce);
 if(score>bestScore)
 {
 bestScore=score;
 bestMass=totalMass;
 bestEnergy=totalEnergy;
 bestSEA=overallSEA;
 bestForce=peakForce;
 bestPeakG=peakG;
 bestSafety=safety;
 bestTc=tc;
 bestTh=th;
 bestTf=tf;
 bestTp=tp;
 bestWidth=width;
 bestHeight=height;
 }
 }
 }
 }
 }
 }
 }
 }
 printf("\n==============================================\n");
 printf("FINAL OPTIMUM DESIGN\n");
 printf("==============================================\n");
 printf("CFRP Thickness : %d mm\n",bestTc);
 printf("Honeycomb Thickness : %d mm\n",bestTh);
 printf("Al Foam Thickness : %d mm\n",bestTf);
 printf("PU Foam Thickness : %d mm\n",bestTp);
 printf("Width : %d mm\n",bestWidth);
 printf("Height : %d mm\n",bestHeight);
 printf("Total Mass : %.3f kg\n",bestMass);
 printf("Total Energy : %.2f J\n",bestEnergy);
 printf("Overall SEA : %.2f kJ/kg\n",bestSEA);
 printf("Peak Force : %.2f N\n",bestForce);
 printf("Peak Deceleration : %.2f g\n",bestPeakG);
 printf("Safety Factor : %.2f\n",bestSafety);
 printf("Optimization Score : %.3f\n",bestScore);
 printf("==============================================\n");
 return 0;
}