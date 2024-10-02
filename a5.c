#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int x;
    int y;
} Point_t;

int main(int argc, char ** argv) 
{
    char*filename;
    if(argc == 1)
    {
        filename = argv[0];
    }
    else
    {
        return EXIT_FAILURE;
    }

    FILE* fp = fopen(filename, "r");
    Point_t p;
    while (fscanf(fp, "%d %d\n", &p.x, &p.y) != EOF) {
        printf("X: %d, Y: %d\n", p.x, p.y);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
