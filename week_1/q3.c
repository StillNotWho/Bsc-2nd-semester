//q3
//program to find number of vowels , consonants , digits , and whitespace
#include <stdio.h>

int main()
{
    char str[200];
    int i;
    int vowels = 0, consonants = 0, digits = 0, whitespace = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
           str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
        {
            vowels++;
        }
        else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            consonants++;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            digits++;
        }
        else if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            whitespace++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Whitespace characters: %d\n", whitespace);

    return 0;
}
