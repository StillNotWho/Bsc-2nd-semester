//q5
//to preform operation on string
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], result[200];
    int choice, i, length;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    printf("\nChoose Operation\n");
    printf("1. Addition (Concatenation)\n");
    printf("2. Copy\n");
    printf("3. Reverse\n");
    printf("4. Length\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: // Concatenation
            strcpy(result, str1);
            strcat(result, str2);
            printf("Concatenated String: %s", result);
            break;

        case 2: // Copy
            strcpy(result, str1);
            printf("Copied String: %s", result);
            break;

        case 3: // Reverse
            length = strlen(str1);

            printf("Reversed String: ");
            for(i = length - 1; i >= 0; i--)
            {
                printf("%c", str1[i]);
            }
            break;

        case 4: // Length
            length = strlen(str1);
            printf("Length of first string: %d", length);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
