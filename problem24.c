#include<stdio.h>
int main()
{
 float width,height;
 float tcfrp;
 float thoney;
 float tfoam;
 float tpu;
 float totalMass;
 float totalEnergy;
 float peakForce;
 float peakG;
 float overallSEA;
 int passed=0;
 int totalConstraints=8;
 printf("=============================================\n");
 printf(" IMPACT ATTENUATOR CONSTRAINT CHECKER\n");
 printf("=============================================\n\n");
 printf("Width (mm): ");
 scanf("%f",&width);
 printf("Height (mm): ");
 scanf("%f",&height);
 printf("CFRP Thickness (mm): ");
 scanf("%f",&tcfrp);
 printf("Honeycomb Thickness (mm): ");
 scanf("%f",&thoney);
 printf("Foam Thickness (mm): ");
 scanf("%f",&tfoam);
 printf("PU Thickness (mm): ");
 scanf("%f",&tpu);
 printf("Total Mass (kg): ");
 scanf("%f",&totalMass);
 printf("Total Energy (J): ");
 scanf("%f",&totalEnergy);
 printf("Peak Force (N): ");
 scanf("%f",&peakForce);
 printf("Peak g: ");
 scanf("%f",&peakG);
 printf("Overall SEA (kJ/kg): ");
 scanf("%f",&overallSEA);
 printf("\n========================================\n");
 printf("CONSTRAINT CHECK RESULTS\n");
 printf("========================================\n");
 if(width>=70 && width<=110)
 {
 printf("Width PASS\n");
 passed++;
 }
 else
 printf("Width FAIL\n");
 if(height>=140 && height<=220)
 {
 printf("Height PASS\n");
 passed++;
 }
 else
 printf("Height FAIL\n");
 if((tcfrp+thoney+tfoam+tpu)>=120 &&
 (tcfrp+thoney+tfoam+tpu)<=250)
 {
 printf("Thickness PASS\n");
 passed++;
 }
 else
 printf("Thickness FAIL\n");
 if(totalMass<=2.0)
 {
 printf("Mass PASS\n");
 passed++;
 }
 else
 printf("Mass FAIL\n");
 if(totalEnergy>=7358)
 {
 printf("Energy PASS\n");
 passed++;
 }
 else
 printf("Energy FAIL\n");
 if(peakForce<=80000)
 {
 printf("Peak Force PASS\n");
 passed++;
 }
 else
 printf("Peak Force FAIL\n");
 if(peakG<=40)
 {
 printf("Peak g PASS\n");
 passed++;
 }
 else
 printf("Peak g FAIL\n");
 if(overallSEA>=5.0)
 {
 printf("Overall SEA PASS\n");
 passed++;
 }
 else
 printf("Overall SEA FAIL\n");
 float compliance =
 (float)passed*100.0/totalConstraints;
 printf("\n========================================\n");
 printf("Constraints Passed : %d / %d\n",
 passed,
 totalConstraints);
 printf("Compliance : %.2f %%\n",
 compliance);
 if(passed==totalConstraints)
 printf("\nDESIGN STATUS : ACCEPTED\n");
 else
 printf("\nDESIGN STATUS : REJECTED\n");
 printf("========================================\n");
 return 0;
}
