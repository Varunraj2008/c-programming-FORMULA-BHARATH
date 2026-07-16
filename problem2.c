#include<stdio.h>
int main()
{
 float width;
 float height;
 float area;
 printf("Enter Width (mm): ");
 scanf("%f",&width);
 printf("Enter Height (mm): ");
 scanf("%f",&height);
 area=width*height;
 printf("\nArea = %.2f mm^2\n",area);
 return 0;
}
