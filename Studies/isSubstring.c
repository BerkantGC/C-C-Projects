#include "stdio.h"
 #include <strings.h> // correct header

int isSubstring(char full[50], char search[50]){
    int fullLength = strlen(full);
    int searchLength = strlen(search);

    int i = 0;
    int j = 0;
    int k, m;
    char tmp[30];
    //albara
    //bar
    
        while (j<fullLength)
        {
            i = 0;
            if(search[i] == full[j])
            {
                k = j;
                while(search[i] == full[k]){
                    tmp[i] = search[i];
                    if(i == searchLength-1){
                        printf("%s", tmp);
                        return 1;
                    }
                    i++;
                    k++;
                }
            }
            j++;
        }
        printf("no");
    return 0;    
}

int main(){
    printf("\n%d", isSubstring("halellluya", "halelluya"));
    return 0;
}