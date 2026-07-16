#include<stdio.h>
int main()
{
 float mass[4];
 float totalMass=0;
 int i;
 printf("TOTAL MASS CALCULATOR\n\n");
 for(i=0;i<4;i++)
 {
 printf("Enter Mass of Layer %d (kg): ",i+1);
 scanf("%f",&mass[i]);
 totalMass+=mass[i];
 }
 printf("\n---------------------------------\n");
 printf("Total Mass = %.4f kg\n",totalMass);
 printf("---------------------------------\n");
 return 0;
}