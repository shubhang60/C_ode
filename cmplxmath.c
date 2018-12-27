#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct cmplx_st //Creating a complex datatype
{
    int real;
    int imaginary;
};
typedef struct cmplx_st cmplx;

int main()
{
    int choice;
    cmplx num[2], result;
    printf("Enter two complex numbers in format real imaginary.\n");
    for (int i = 0; i < 2; i++)
    {
        scanf("%d%d", &num[i].real, &num[i].imaginary);
    }

    printf("What you want to do with complex numbers.\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice no.");
    scanf(" %d", &choice);
    switch (choice)
    {
    case 1:
        result.real = num[0].real + num[1].real;
        result.imaginary = num[0].imaginary + num[1].imaginary;
        if (result.imaginary < 0)
        {
            printf("%d %di\n", result.real, result.imaginary);
        }
        else
        {
            printf("%d + %di\n", result.real, result.imaginary);
        }
        break;
    case 2:
        result.real = num[0].real - num[1].real;
        result.imaginary = num[0].imaginary - num[1].imaginary;
        if (result.imaginary < 0)
        {
            printf("%d %di\n", result.real, result.imaginary);
        }
        else
        {
            printf("%d + %di\n", result.real, result.imaginary);
        }
        break;
    case 3:
        result.real = num[0].real * num[1].real - num[0].imaginary * num[1].imaginary;
        result.imaginary = num[0].real * num[1].imaginary + num[1].real * num[0].imaginary;
        if (result.imaginary < 0)
        {
            printf("%d %di\n", result.real, result.imaginary);
        }
        else
        {
            printf("%d + %di\n", result.real, result.imaginary);
        }
        break;
    case 4:
        float a, b;
        a = (num[0].real * num[1].real - num[0].imaginary * num[1].imaginary) / (pow(num[1].real, 2) + pow(num[1].imaginary, 2));
        b = (num[0].real * num[1].imaginary + num[1].real * num[0].imaginary) / (pow(num[1].real, 2) + pow(num[1].imaginary, 2));
        if (b < 0)
        {
            printf("%f %fi\n", a, b);
        }
        else
        {
            printf("%f + %fi\n", a, b);
        }
        break;
    default:
        printf("Wrong Choice !!!.");
    }
    return 0;
}
