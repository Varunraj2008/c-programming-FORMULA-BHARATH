#include<stdio.h>
int main()
{
 float density;
 float volume;
 float mass;
 printf("Density (kg/m3): ");
 scanf("%f",&density);
 printf("Volume (m3): ");
 scanf("%f",&volume);
 mass=density*volume;
 printf("\nMass = %.4f kg\n",mass);
 return 0;
}
