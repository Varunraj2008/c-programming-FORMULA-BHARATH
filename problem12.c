#include <stdio.h>

int main()
{
    float density;
    float height;
    float thickness;
    float sea;

    int wMin;
    int wMax;
    int step;

    float area;
    float volume;
    float mass;
    float energy;

    float bestMass = 100000.0;
    int bestWidth = 0;

    printf("=========================================\n");
    printf("WIDTH SWEEP OPTIMIZATION PROGRAM\n");
    printf("=========================================\n\n");

    printf("Density (kg/m3) : ");
    scanf("%f", &density);

    printf("Height (mm) : ");
    scanf("%f", &height);

    printf("Thickness (mm) : ");
    scanf("%f", &thickness);

    printf("SEA (kJ/kg) : ");
    scanf("%f", &sea);

    printf("Minimum Width (mm) : ");
    scanf("%d", &wMin);

    printf("Maximum Width (mm) : ");
    scanf("%d", &wMax);

    printf("Width Step (mm) : ");
    scanf("%d", &step);

    printf("\n=========================================================================\n");
    printf("Width\tArea(mm2)\tMass(kg)\tEnergy(J)\n");
    printf("=========================================================================\n");

    for (int width = wMin; width <= wMax; width += step)
    {
        area = width * height;
        volume = area * thickness;
        volume = volume / 1000000000.0;

        mass = density * volume;
        energy = sea * mass * 1000.0;

        printf("%5d\t%10.2f\t%8.4f\t%10.2f\n",
               width,
               area,
               mass,
               energy);

        if (energy >= 7350.0)
        {
            if (mass < bestMass)
            {
                bestMass = mass;
                bestWidth = width;
            }
        }
    }

    printf("\n=========================================\n");

    if (bestWidth == 0)
    {
        printf("No feasible width satisfies 7350 J.\n");
    }
    else
    {
        printf("OPTIMUM WIDTH = %d mm\n", bestWidth);
        printf("Minimum Mass = %.4f kg\n", bestMass);
    }

    printf("=========================================\n");

    return 0;
}