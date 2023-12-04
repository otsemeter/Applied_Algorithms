#ifndef __RC_TREE__
#define __RC_TREE__

typedef struct _Tnode
{
    int label;
    double sink_f;
    double len_l, len_r;
    double total_f;
    double sum_f;
    double elmore_delay;
    struct _Tnode * left;
    struct _Tnode * right;
}Tnode;

Tnode * new_node();
Tnode * build_tree(double ** node_arr, int *idx);
void print_post(Tnode * root);
void destroy_tree(Tnode * root);
#endif