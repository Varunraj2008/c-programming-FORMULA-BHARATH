#include<stdio.h>
int main()
{
 char material[30];
 float density;
 float width;
 float height;
 float thickness;
 float sea;
 float area;
 float volume_mm3;
 float volume_m3;
 float mass;
 float energy;
 printf("Material Name : ");
 scanf("%s",material);
 printf("Density (kg/m3): ");
 scanf("%f",&density);
 printf("Width (mm): ");
 scanf("%f",&width);
 printf("Height (mm): ");
 scanf("%f",&height);
 printf("Thickness (mm): ");
 scanf("%f",&thickness);
 printf("SEA (kJ/kg): ");
 scanf("%f",&sea);
 area=width*height;
 volume_mm3=area*thickness;
 volume_m3=volume_mm3/1000000000.0;
 mass=density*volume_m3;
 energy=sea*mass*1000.0;
 printf("\n=========================================\n");
 printf("LAYER PROPERTIES\n");
 printf("=========================================\n");
 printf("Material : %s\n",material);
 printf("Density : %.2f kg/m3\n",density);
 printf("Width : %.2f mm\n",width);
 printf("Height : %.2f mm\n",height);
 printf("Thickness : %.2f mm\n",thickness);
 printf("Area : %.2f mm2\n",area);
 printf("Volume : %.8f m3\n",volume_m3);
 printf("Mass : %.4f kg\n",mass);
 printf("SEA : %.2f kJ/kg\n",sea);
 printf("Energy : %.2f J\n",energy);
 printf("=========================================\n");
 return 0;
}