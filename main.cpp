

#include <stdio.h>
#include <stdlib.h>



struct node //yek sakhtar gere dorost mikonim, ke daray do farzand chap va rast ast
{
     int data;
     struct node* chap;
     struct node* rast;
};

struct node* nodejadid(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));//yek hafeze barmidarad
     node->chap = NULL;//farzand chap  va rast khali hastand
     node->rast = NULL;
     return(node);
}
void deletet(struct node *node)
{
    if (node == NULL) return;//age vojod nadasht ya resid be hichi
    deletet(node->chap);// farzand samt chap pak mishavad
    deletet(node->rast);//farzand samt rast pak mishavad
    printf("\n pak shod . ");//sepas sar on gere pak mishavad va bazgashti
    free(node);//hafze ra khali kon
}

int main()
{
     struct node *root  = nodejadid(1);
     root->chap         = nodejadid(2);
     root->rast         = nodejadid(3);
     root->chap->chap   = nodejadid(4);
     root->chap->rast   = nodejadid(5);
     root->rast->rast   = nodejadid(6);

    deletet(root);
    root = NULL;

    printf("\n done ! ");

    return 0;
}

