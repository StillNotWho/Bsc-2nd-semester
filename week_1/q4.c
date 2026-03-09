//q4
//to preform operations in matrix
#include <stdio.h>

int main()
{
    int A[10][10], B[10][10], C[10][10];
    int i, j, k, r1, c1, r2, c2, choice;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d",&A[i][j]);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d",&B[i][j]);

    printf("\nChoose Operation\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Transpose of Matrix A\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: // Addition
            if(r1==r2 && c1==c2)
            {
                for(i=0;i<r1;i++)
                    for(j=0;j<c1;j++)
                        C[i][j]=A[i][j]+B[i][j];

                printf("Result Matrix:\n");
                for(i=0;i<r1;i++)
                {
                    for(j=0;j<c1;j++)
                        printf("%d ",C[i][j]);
                    printf("\n");
                }
            }
            else
                printf("Addition not possible\n");
            break;

        case 2: // Subtraction
            if(r1==r2 && c1==c2)
            {
                for(i=0;i<r1;i++)
                    for(j=0;j<c1;j++)
                        C[i][j]=A[i][j]-B[i][j];

                printf("Result Matrix:\n");
                for(i=0;i<r1;i++)
                {
                    for(j=0;j<c1;j++)
                        printf("%d ",C[i][j]);
                    printf("\n");
                }
            }
            else
                printf("Subtraction not possible\n");
            break;

        case 3: // Multiplication
            if(c1==r2)
            {
                for(i=0;i<r1;i++)
                {
                    for(j=0;j<c2;j++)
                    {
                        C[i][j]=0;
                        for(k=0;k<c1;k++)
                            C[i][j]+=A[i][k]*B[k][j];
                    }
                }

                printf("Result Matrix:\n");
                for(i=0;i<r1;i++)
                {
                    for(j=0;j<c2;j++)
                        printf("%d ",C[i][j]);
                    printf("\n");
                }
            }
            else
                printf("Multiplication not possible\n");
            break;

        case 4: // Transpose
            printf("Transpose of Matrix A:\n");
            for(i=0;i<c1;i++)
            {
                for(j=0;j<r1;j++)
                    printf("%d ",A[j][i]);
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
