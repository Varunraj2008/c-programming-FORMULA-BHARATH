#include<stdio.h>
int main()
{
 float width;
 float height;
 float thickness;
 float volume_mm3;
 float volume_m3;
 printf("Width (mm): ");
 scanf("%f",&width);
 printf("Height (mm): ");
 scanf("%f",&height);
 printf("Thickness (mm): ");
 scanf("%f",&thickness);
 volume_mm3=width*height*thickness;
 volume_m3=volume_mm3/1000000000.0;
 printf("\nVolume = %.2f mm^3\n",volume_mm3);
 printf("Volume = %.8f m^3\n",volume_m3);
 return 0;
}