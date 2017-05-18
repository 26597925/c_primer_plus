#include <stdio.h>
#include <stdio_ext.h>

int main(void)
{
    const float OVERTIME_LIMIT = 40.0f;
    const float OVERTIME_RATE = 1.5f;
    const float TAX_LIMIT1 = 300.0f;
    const float TAX_RATE1 = 0.15f;
    const float TAX_LIMIT2 = 150.0f;
    const float TAX_RATE2 = 0.20f;
    const float TAX_RATE3 = 0.25f;

    float gross = 0.0f;
    float tax = 0.0f;
    float work_hours = 0.0f;
    float pay_rate = 0.0f;
    int selection = 0;

    do
    {
        printf("*****************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("1)$8.75/hr\t\t\t\t\t2)$9.33/hr\n");
        printf("3)$10.00/hr\t\t\t\t\t4)$11.20/hr\n");
        printf("5)quit\n");
        printf("*****************************************************************\n");
        __fpurge(stdin);
        if ((1 == scanf("%d", &selection)) && selection >= 1 && selection <=4)
        {
            switch (selection)
            {
                case 1:
                    pay_rate = 8.75f;
                    break;
                case 2:
                    pay_rate = 9.33f;
                    break;
                case 3:
                    pay_rate = 10.00f;
                    break;
                case 4:
                    pay_rate = 11.20f;
                    break;
            }
            printf("Please enter working hours: ");
            scanf("%f", &work_hours);
            if (work_hours > OVERTIME_LIMIT)
            {
                work_hours = OVERTIME_LIMIT + (work_hours - OVERTIME_LIMIT) * OVERTIME_RATE; 
            }
            gross = work_hours * pay_rate;
            if (gross <= TAX_LIMIT1)
            {
                tax = gross * TAX_RATE1;
            }
            else if (gross <= (TAX_LIMIT1 + TAX_LIMIT2))
            {
                tax = TAX_LIMIT1 * TAX_RATE1 + (gross - TAX_LIMIT1) * TAX_RATE2;
            }
            else
            {
                tax = TAX_LIMIT1 * TAX_RATE1 + TAX_LIMIT2 * TAX_RATE2 + (gross - TAX_LIMIT1 - TAX_LIMIT2) * TAX_RATE3;
            }
            printf("Gross: %.2f\n", gross);
            printf("Tax: %.2f\n", tax);
            printf("Net income: %.2f\n\n", gross - tax);
        }
    } while (selection != 5);

    return 0;
}
