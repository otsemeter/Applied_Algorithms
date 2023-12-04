#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Tnode * new_node()
{
    Tnode * node = malloc(sizeof(Tnode));
    node -> total_f = 0;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

Tnode * build_tree(double ** node_arr, int * idx)
{
    Tnode * root = new_node();
    root -> label = (int)node_arr[*idx - 1][0];
    if(root -> label != -8)
    {
        root -> sink_f = node_arr[*idx - 1][1];
       // printf("%d ", num_nodes - 2);
        return root;
    }

    root -> len_l = node_arr[*idx - 1][2];
    root -> len_r = node_arr[*idx - 1][3];
    
    *idx -= 1;
    root -> right = build_tree(node_arr, idx);
    *idx -= 1;
    root -> left = build_tree(node_arr, idx);

    return root;
}

void print_post(Tnode * root)
{
    if(!root)
    {
        return;
    }
    print_post(root -> left);
    print_post(root -> right);
    printf("%d: %.10le\n", root -> label, root -> elmore_delay);
}

void destroy_tree(Tnode * root)
{
    if(!root)
    {
        return;
    }
    destroy_tree(root -> right);
    destroy_tree(root -> left);
    free(root);
}