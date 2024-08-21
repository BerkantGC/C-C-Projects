#include <stdio.h>
#include <string.h>
#include <time.h>

int isValid(char* str1, char* str2)
{
    return strcmp(str1, str2);
}

int bruteForce(char *text)
{
    char tmp[] = "00000";
    printf("%c", tmp[4] );
    int i = 0;

    for(i = 48; i <= 57; i++)
    {
        for (int j = 48; j <= 57; j++)
        {
            for (int k = 48; k <= 57; k++)
            {
                for(int l = 48; l <= 57; l++)
                {   
                    for(int m = 48; m <= 57; m++)
                    {
                        tmp[0] = i;
                        tmp[1] = j;
                        tmp[2] = k;
                        tmp[3] = l;
                        tmp[4] = m;

                        printf("%s\n", tmp);
                        if(isValid(text, tmp) == 0)
                        {
                            printf("We found!!! %s\n", tmp);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}

int main(int argc, char const *argv[])
{
    float start = clock();

    //Function to do
    char str[10];

    FILE *file;
    file = fopen("password.txt", "w+");
    fputs("76541", file);

    rewind(file);
    fscanf(file, "%s", str);

    printf("Read String: |%s|\n", str);

    bruteForce(str);
    float end = clock();

    printf("time spent: %f", end - start);
    
    return 0;
}

