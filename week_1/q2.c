//q2
//program to remove a word from string
#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], word[50], result[200];
    int i = 0, j = 0, k, len;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter word to remove: ");
    scanf("%s", word);

    len = strlen(word);

    while(str[i] != '\0')
    {
        k = 0;

        // check if word matches
        while(str[i + k] == word[k] && word[k] != '\0')
        {
            k++;
        }

        if(k == len) // word found
        {
            i = i + len; // skip the word
        }
        else
        {
            result[j] = str[i];
            j++;
            i++;
        }
    }

    result[j] = '\0';

    printf("Resulting string: %s", result);

    return 0;
}
