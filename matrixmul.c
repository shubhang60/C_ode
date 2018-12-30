#include<stdio.h>
#include<stdlib.h>
int main()
{
    int or_A, oc_A, or_B, oc_B;
    printf("Enter the order of first matrix as m<space>n.\n");
    scanf("%d%d", &or_A,&oc_A);
    printf("Enter the order of second matrix as m<space>n.\n");
    scanf("%d%d", &or_B,&oc_B);
    if(oc_A!=or_B)
    {
        printf("These matrices cannot be multiplied.\n");
        exit(0);
    }

    int A[or_A][oc_A], B[or_B][oc_B], C[or_A][oc_B];

    for(int i=0; i<or_A; i++)
	{
		for(int j=0; j<oc_A; j++)
		{
			printf("Enter element A(%d%d) of matrix A :", i+1, j+1);
			scanf("%d",&A[i][j]);
		}
	}
	
	for(int i=0; i<or_B; i++)
	{
		for(int j=0; j<oc_B; j++)
		{
			printf("Enter element B(%d%d) of matrix B :",i+1,j+1);
			scanf("%d",&B[i][j]);
		}
	}

    printf("\nThe resultant matrix is.\n");
    for(int i=0; i<or_A; i++)
	{
		for(int j=0; j<oc_B; j++)
		{
			C[i][j]=0;
			for(int n=0; n<oc_A; n++)
			{
				C[i][j] = C[i][j] + A[i][n] * B[n][j];
			}
            printf("%d ",C[i][j]);
		}
        printf("\n");
	}
    return 0;
}