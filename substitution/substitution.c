#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[]) {

        //Check key length
        if (argc != 2)
            {
                printf("Usage: %s Key\n", argv[0]);
                return 1;
            }
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: %s Key\n", argv[0]);
                return 1;
            }
        }
        //Check for string length
        int strl = strlen(argv[1]);
        if (strl < 26 ||strl > 26)
        {
            printf("Usage: %s Key\n", argv[0]);
            return 1;
        }
        //Check for repeated characters (case-insensitive)
        int counter = 0;
        int cnt = 0;
        for (int i = 0; i < strl; i++)
        {
            for (int j = 0; argv[1][j] != '\0'; j++)
            {
                cnt++;
                if (argv[1][j] == argv[1][i])
                {
                    counter++;
                }
            }
        }
        if (counter != strl)
            {
                printf("Usage: %s Key\n", argv[0]);
                return 1;
            }
        //Prompt user to type plaintext
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        //Convert plaintext to ciphertext
        int textinput = strlen(plaintext);
        for (int z = 0; z < textinput; z++)
        {
            for (int m = 0; m < 26; m++)
            {
                if (plaintext[z] == 'a' + m)
                {
                    //Check the key - caiptal or not
                    if (argv[1][m] >= 'a' && argv[1][m] <= 'z')
                    {
                        printf("%c", argv[1][m]);
                    }
                    else
                    {
                        char let1 = argv[1][m] + 32;
                        printf("%c", let1);
                    }
                }
                else if (plaintext[z] == 'A' + m)
                {
                    //Check the key - caiptal or not
                    if (argv[1][m] >= 'a' && argv[1][m] <= 'z')
                    {
                        char let2 = argv[1][m] - 32;
                        printf("%c", let2);
                    }
                    else
                    {
                        printf("%c", argv[1][m]);
                    }
                }
            }
    //Print non-alphabetical plaintext
            if (!isalpha(plaintext[z]))
            {
                printf("%c", plaintext[z]);
            }
    }
    //print newline - end of the program
        printf("\n");
        return 0;
}
