#include <stdio.h>
#include <stdlib.h>
#include "write.h"
#include "tree.h"

void write_pre(FILE * fptr, Tnode * root)
{
    if(!root)
        return;
    if(root -> label != -8)
    {
        fprintf(fptr, "%d(%.10le)\n", root -> label, root -> sink_f);
        return;
    }

    fprintf(fptr, "(%.10le %.10le)\n", root -> len_l, root -> len_r);
    write_pre(fptr, root -> left);
    write_pre(fptr, root -> right);
}

void write_elmore(FILE * fptr, Tnode * root)
{
    if(!root)
        return;
    if(root -> label != -8)
    {
        fwrite(&(root -> label), sizeof(int), 1, fptr);
        fwrite(&(root -> elmore_delay), sizeof(double), 1, fptr);
        return;
    }
    write_elmore(fptr, root -> left);
    write_elmore(fptr, root -> right);
}