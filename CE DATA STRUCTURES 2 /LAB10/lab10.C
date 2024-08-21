#include <stdio.h>
#include <stdlib.h>

int findIndex(FILE *fp, int tree[63],int start, int end, int height, int key)
{

    for (int i = start; i < end; i++)
    {
        FILE * fp = fopen("btree.txt", "rb+");

        fseek(fp, sizeof(int)* i, SEEK_SET);
        int treeKey; 

        fread(&treeKey , sizeof(int) * 1, 1, fp);

        fclose(fp);

        if(key < (int)treeKey)
        {
            printf("%d %d ", i, 3*i + 3*height); 
            printf("\n");
            
            return 3*i + 3*height;
        }

    }
    
    printf("%d ", end);
    printf("%d ", 3*(end) + 3*height); 
    printf("\n");
    return 3*(end) + 3*height;
}

void insert(int key)
{
    int tree[63];

    FILE * fp = fopen("btree.txt", "rb+");

    fread(tree, sizeof(int)*63, 1, fp);
    fclose(fp);

    int height = 1, newIndex = 0;

    while (height <= 3 && (key < tree[newIndex] || key < tree[newIndex+1]))
    {
        printf("new Index : %d height: %d\n" , newIndex, height);
        newIndex = findIndex(fp, tree, newIndex, newIndex + 3, height, key);

        if(key > tree[newIndex])
        {
            printf("%d ", newIndex);
                printf("%d ", 3*(newIndex) + 3*height); 
                printf("\n");
        }

        height++;
    }
    
    printf("\n%d" , tree[newIndex]);
    if(tree[newIndex] == 0)
        tree[newIndex] = key;

    
    fclose(fp);
}

int main(int argc, char const *argv[])
{
    int tree[63] = { 50, 110, 185, 20, 30, 45, 60, 95, 100,115, 125, 140, 200, 210, 345, 5, 10, 20, 25, 25, 30, 35, 40, 40, 45, 50, 50, 55,
                00, 00, 85, 90, 00, 100, 00, 00, 105, 110, 00, 115, 00, 00, 120, 120, 00, 130, 135, 00, 145, 175, 180, 190, 195, 00, 210, 
                00, 00, 220, 245, 00, 350, 400, 460};

    int size = 63;

    FILE *file;
    file = fopen("btree.txt", "wb+");

    fwrite(tree, sizeof(int)*63, 1, file);


    fclose(file);

    insert(25);

    return 0;
}
