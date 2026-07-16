#include <stdio.h>

int main()
{
    float density[4];
    float width[4];
    float height[4];
    float thickness[4];
    float sea[4];
    float volume[4];
    float mass[4];
    float energy[4];

    float totalMass = 0;
    float totalEnergy = 0;
    float overallSEA;

    int i;

    printf("HYBRID IMPACT ATTENUATOR CALCULATOR\n\n");

    for(i = 0; i < 4; i++)
    {
        printf("\nLayer %d\n", i + 1);

        printf("Density (kg/m3): ");
        scanf("%f", &density[i]);

        printf("Width (mm): ");
        scanf("%f", &width[i]);

        printf("Height (mm): ");
        scanf("%f", &height[i]);

        printf("Thickness (mm): ");
        scanf("%f", &thickness[i]);

        printf("SEA (kJ/kg): ");
        scanf("%f", &sea[i]);

        volume[i] = width[i] * height[i] * thickness[i];
        volume[i] = volume[i] / 1000000000.0;

        mass[i] = density[i] * volume[i];

        energy[i] = sea[i] * mass[i] * 1000.0;

        totalMass += mass[i];
        totalEnergy += energy[i];
    }

    overallSEA = totalEnergy / (1000.0 * totalMass);

    printf("\n====================================================================\n");
    printf("Layer\tMass(kg)\tEnergy(J)\tSEA(kJ/kg)\n");
    printf("====================================================================\n");

    for(i = 0; i < 4; i++)
    {
        printf("%d\t%.4f\t\t%.2f\t\t%.2f\n",
               i + 1,
               mass[i],
               energy[i],
               sea[i]);
    }

    printf("====================================================================\n");

    printf("Total Mass   : %.4f kg\n", totalMass);
    printf("Total Energy : %.2f J\n", totalEnergy);
    printf("Overall SEA  : %.4f kJ/kg\n", overallSEA);

    printf("====================================================================\n");

    return 0;
}