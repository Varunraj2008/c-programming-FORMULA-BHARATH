#include<stdio.h>
int main()
{
 float area[4];
 float totalArea=0;
 float percentage[4];
 int i;
 printf("AREA PERCENTAGE CALCULATOR\n\n");
 for(i=0;i<4;i++)
 {
 printf("Enter Area of Layer %d (mm2): ",i+1);
 scanf("%f",&area[i]);
 totalArea+=area[i];
 }
 printf("\n-----------------------------------------------\n");
 printf("Layer\tArea(mm2)\tArea Percentage\n");
 printf("-----------------------------------------------\n");
 for(i=0;i<4;i++)
 {
 percentage[i]=(area[i]/totalArea)*100.0;
 printf("%d\t%.2f\t\t%.2f %%\n",
 i+1,
 area[i],
 percentage[i]);
 }
 printf("-----------------------------------------------\n");
 printf("Total Area = %.2f mm2\n",totalArea);
 return 0;
}