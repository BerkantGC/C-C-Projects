#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPalindromic(int text[50])
{
    int k= 0;

    for (int i = 0; i < size/2; i++)
    {
        if (text[i] == text[size-i-1])
        {
            k++;
        }   
    }
    if(k == size/2)
        return k;
    else return -1;
}

 char* split(char string[20], int start, int end)
{
    int size = end-start+1;
    char *new = malloc(100);

    for(int i = 0; i < size; i++)
    {
        new[i] = string[start];
        start++;
    }
    return new;
    
}
void longestPalindromic(char full[20] ){

    int size = strlen(full);
    
    int max = 0; 
    char *tmp;
     for (int i = 0; i < size; i++)
     {
        for (int j = i+1; j < size; j++)
        {
        char* new = split(full, i, j);
            int count= isPalindromic(new);
            printf("%d\n", count);
            if(count != -1)
            {
                if(max<count){
                tmp = new;
                max = count;
                }

            }
        }
     }
                     printf("%s", tmp);

}
int main(){
    longestPalindromic("cbbd");
    return 0;
}