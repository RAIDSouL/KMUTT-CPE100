#include <stdio.h>
#include <math.h>
#include <cstdlib>

double getDoubleInput ()
{
    int endCheck, invalid, startDecimal, decimalIndex;
    char input;
    double output, num, decimal;
    do
    {
        endCheck = 0;
        invalid = 0;
        startDecimal = 0;
        decimalIndex = 0;
        output = 0;
        num = 0;
        decimal = 0.0;
        rewind(stdin);
        while (endCheck == 0)
        {
            input = getchar();
            if (input >= '0' && input <= '9')
            {
                if (startDecimal == 1)
                {
                    decimal = decimal + ((double)input - '0') / pow(10, decimalIndex);
                    decimalIndex++;
                }
                else num = num * 10 + (input - '0'); // Regular number
            }
            else if (input == '.')
            {
                decimalIndex = 1;
                startDecimal = 1;
            }
            else if (input == '\n')
            {
                endCheck = 1;
            } else {
                invalid = 1;
                endCheck = 1;
            }
        }

        if (invalid == 1)
            printf("\nInvalid input ! Please enter again: ");

        rewind(stdin);
    } while(invalid == 1);
    return num + decimal;
}


int main ()
{
    double angle, u, x, t;
    double ux, uy, ty, airTime;
    double gx, gy, gt;
    double r, h, sy, sx;
    double g = 9.81;
    char playAgain;

    do
    {
        // Clear screen
        system("cls");

        // Introduce
        printf("******************************");
        printf("\n*                            *");
        printf("\n*   Freekick calculator      *");
        printf("\n*   v.1 by Nitipoom Unrrom   *");
        printf("\n*                            *");
        printf("\n******************************\n\n");

        // Enter input
        printf("Enter Velocity (m/s): ");
        u = getDoubleInput();
        printf("Enter Angle (degree): ");
        angle = getDoubleInput();
        printf("Enter Distance (m): ");
        x = getDoubleInput();

        // Calculation
        r = angle * M_PI / 180.0;
        uy = u * sin(r);
        ux = u * cos(r);
        ty = uy / g;
        airTime = 2 * (ty);
        sy = pow(uy, 2)/( 2 * g);
        sx = ux * airTime;
        gt = x/ux; // Time at goal line
        gy = uy * gt + 0.5 * (-g) * pow(gt, 2); // Height at goal line

        // Print result
        printf("\n=========== RESULT ============");
        printf("\n  Highest: %gm", sy);
        printf("\n  Longest distance: %gm", sx);
        printf("\n  Air Time: %gs", airTime);

        if (gy > 0 && gt > 0)
            printf("\n  Height at goal line %gm in %gs", gy, gt);
        else printf("\n  *  Ball fall to the ground before reach goal");

        if (gt <= 0.5 && gy < 2.44 && gy > 0)
        {
            printf("\n  >>>>>> GOAL ! ");
        } else {
            if (gy < 2.44 && gy > 0)
                printf("\n  *  Goal keeper get the ball");
            else if (gy >= 2.44)
                printf("\n  *  Ball over the goal");
            printf("\n  >>>>>> NOT GOAL");
        }
        rewind(stdin);
        printf("\n\nDo you want to play again ? [Y/n]: ");
        scanf("%c", &playAgain);
        while(playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')
        {
            printf("\nInvalid input ! Please enter Y or N");
            scanf("%c", &playAgain);
            rewind(stdin);
        }

    } while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}
