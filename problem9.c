#include<stdio.h>
int main()
{
 float energy;
 float mass;
 float sea;
 printf("SPECIFIC ENERGY ABSORPTION CALCULATOR\n\n");
 printf("Energy Absorbed (J): ");
 scanf("%f",&energy);
 printf("Mass (kg): ");
 scanf("%f",&mass);
 sea=energy/(1000.0*mass);
 printf("\n--------------------------------\n");
 printf("SEA = %.4f kJ/kg\n",sea);
 printf("--------------------------------\n");
 return 0;
}