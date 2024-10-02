#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int x;
    int y;
} Point_t;

typedef struct 
{
    int x;
    int y;
    int r;
} Circle_t;


static int linecount(FILE * fp)
{
    int ch;
    int line_count = 1;

    while ((ch = fgetc(fp)) != EOF) 
    {
        printf("ch = %c\n", ch);
        if (ch == '\n') 
        {
            line_count++;
        }
    }

    rewind(fp);
    return line_count;
}

int main(int argc, char ** argv) 
{
    char* filename;
    if(argc == 2)
    {
        filename = argv[1];
    }
    else
    {
        return EXIT_FAILURE;
    }

    FILE* fp = fopen(filename, "r");
    Point_t p;
    size_t bytes = linecount(fp) * sizeof(Point_t);
    int len = 0;

    Point_t* points = malloc(bytes);
    while (fscanf(fp, "%d %d\n", &p.x, &p.y) != EOF) {
        points[len] = p;
        len++;
    }

    fclose(fp);

    for(int i = 0; i < len; i++)
    {
        printf("X: %d, Y: %d\n", points[i].x, points[i].y);  
    }

    Circle_t circle;

    scanf("%d %d %d", &circle.x, &circle.y, &circle.r);
    printf("X: %d, Y: %d, R: %d\n", circle.x, circle.y, circle.r);
    return EXIT_SUCCESS;
}