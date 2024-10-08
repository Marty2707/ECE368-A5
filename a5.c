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
struct _Tnode * left;
struct _Tnode * right;
Point_t point;
} Tnode;

int binary_search(Tnode *root, Circle_t key)
{
    int i = 0;
    if (root == NULL)
        return 0;
    else if ( (key.x - key.r) > (root -> point.x) )
        i+= binary_search(root ->right, key);

    else if ( (key.x + key.r) < (root -> point.x) )
        i+= binary_search(root ->left, key);

    else if ( (key.x + key.r) >= (root -> point.x) && (key.x - key.r) <= (root -> point.x)){

        if (key.r*key.r >= ((root -> point.x) - (key.x)) * ((root -> point.x) - (key.x)) + ((root -> point.y) - (key.y)) * ((root -> point.y) - (key.y))) 
        {
            i++;
        }
        i+= binary_search(root ->left, key) + binary_search(root ->right, key);
    }
    
    return i;
}

Tnode * build_bst (Point_t * arr, int l, int r)
{
    if (l>r) return NULL;

    int m = (l+r) / 2;

    Tnode* node = (Tnode*) malloc(sizeof( Tnode));
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

int compare(const void* a, const void* b) {
   return ((*(Point_t*)a).x - (*(Point_t*)b).x);
}


void BT_Delete (Tnode *bt_ptr)
{ if (bt_ptr != NULL) {
    BT_Delete (bt_ptr->left);
    BT_Delete (bt_ptr->right);
    free(bt_ptr);
}
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

    // for(int i = 0; i < len; i++)
    // {
    //     printf("X: %d, Y: %d\n", points[i].x, points[i].y);  
    // }

    qsort(points, len, sizeof(Point_t), compare);

    Tnode* root = build_bst(points, 0, len-1);
    Circle_t circle;

    while(scanf("%d %d %d", &circle.x, &circle.y, &circle.r) == 3)
    {
        printf("%d\n", binary_search(root, circle));
    }
        
    //printf("X: %d, Y: %d, R: %d\n", circle.x, circle.y, circle.r);

    free(points);
    BT_Delete(root);
    return EXIT_SUCCESS;
}


