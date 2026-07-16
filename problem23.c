#include<stdio.h>
int main()
{
 float density[4]={1600,80,450,120};
 float seaMaterial[4]={1.15,26.3,4.77,9.2};
 float bestScore=-1;
 float bestMass;
 float bestEnergy;
 float bestSEA;
 float bestForce;
 float bestG;
 int bestCFRP;
 int bestHoney;
 int bestFoam;
 int bestPU;
 int bestWidth;
 int bestHeight;
 printf("\nSearching Design Space...\n");
 for(int tc=10;tc<=30;tc+=10)
 {
 for(int th=40;th<=90;th+=10)
 {
 for(int tf=30;tf<=80;tf+=10)
 {
 for(int tp=20;tp<=70;tp+=10)
 {
 for(int width=70;width<=110;width+=10)
 {
 for(int height=140;height<=220;height+=20)
 {
 float volume[4];
 int t[4]={tc,th,tf,tp};
 float totalMass=0;
 float totalEnergy=0;
 for(int i=0;i<4;i++)
 {
 volume[i]=
 width*
 height*
 t[i];
 volume[i]/=1000000000.0;
 float mass=
 density[i]*
 volume[i];
 float energy=
 seaMaterial[i]*
 mass*
 1000;
 totalMass+=mass;
 totalEnergy+=energy;
 }
 float overallSEA=
 totalEnergy/
 (1000*totalMass);
 float totalThickness=
 tc+th+tf+tp;
 float force=
 totalEnergy/
 (totalThickness/1000.0);
 float peakG=
 force/
 (300*9.81);
 float score=
 0.35*(overallSEA/10.0)+
 0.35*(totalEnergy/7358.0)+
 0.20*(1.5-totalMass)+
 0.10*(40.0/peakG);
 if(score>bestScore)
 {
 bestScore=score;
 bestMass=totalMass;
 bestEnergy=totalEnergy;
 bestSEA=overallSEA;
 bestForce=force;
 bestG=peakG;
 bestCFRP=tc;
 bestHoney=th;
 bestFoam=tf;
 bestPU=tp;
 bestWidth=width;
 bestHeight=height;
 }
 }
 }
 }
 }
 }
 }
 printf("\n============================================\n");
 printf("OPTIMUM IMPACT ATTENUATOR DESIGN\n");
 printf("============================================\n");
 printf("CFRP Thickness : %d mm\n",bestCFRP);
 printf("Honeycomb Thickness : %d mm\n",bestHoney);
 printf("Al Foam Thickness : %d mm\n",bestFoam);
 printf("PU Foam Thickness : %d mm\n",bestPU);
 printf("Width : %d mm\n",bestWidth);
 printf("Height : %d mm\n",bestHeight);
 printf("Total Mass : %.3f kg\n",bestMass);
 printf("Total Energy : %.2f J\n",bestEnergy);
 printf("Overall SEA : %.2f kJ/kg\n",bestSEA);
 printf("Peak Force : %.2f N\n",bestForce);
 printf("Peak g : %.2f\n",bestG);
 printf("Optimization Score : %.3f\n",bestScore);
 printf("============================================\n");
 return 0;
}