#include<stdio.h>
struct Material
{
 char name[30];
 float density;
 float sea;
};
int main()
{
 struct Material m[4]=
 {
 {"CFRP",1600,1.15},
 {"Al Honeycomb",80,26.30},
 {"Al Foam",450,4.77},
 {"PU Foam",120,9.20}
 };
 int i;
 printf("\n-----------------------------------------\n");
 printf("HYBRID MATERIAL DATABASE\n");
 printf("-----------------------------------------\n");
 printf("\nMaterial\t\tDensity\tSEA\n");
 for(i=0;i<4;i++)
 {
 printf("%-18s %.2f %.2f\n",
 m[i].name,
 m[i].density,
 m[i].sea);
 }
 return 0;
}
