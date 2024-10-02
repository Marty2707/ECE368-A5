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

typedef struct _Tnode
{ 
int left;
int right;
Point_t point;
} Tnode;

int binary_search(Tnode *root, Circle_t key)
{
    int i = 0;
        if ( (key.x - key.r) > (root -> point.x) )
            i+= binary_search(root ->right, key);

        else if ( (key.x + key.r) < (root -> point.x) )
            i+= binary_search(root ->left, key);

        else if ( (key.x + key.r) >= (root -> point.x) && (key.x - key.r) <= (root -> point.x))
            i+= binary_search(root ->left, key) + binary_search(root ->right, key);
    
    return i;
}

Tnode * build_bst (Point_t * arr, int l, int r)
{
    if (l>r) return NULL;

    int m = (1+r) / 2;

    Tnode* node = (struct Tnode*) malloc(sizeof( Tnode));
    node -> point = arr[m];
    node -> left = build_bst (arr, l, m-1);
    node -> right = build_bst(arr, m+1, r);

    return node;

}

static int linecount(FILE * fp)
{
    int ch;
    int line_count = 1;

    while ((ch = fgetc(fp)) != EOF) 
    {
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

    free(points);
    return EXIT_SUCCESS;
}


