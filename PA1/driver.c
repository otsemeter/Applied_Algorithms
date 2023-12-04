#include <stdio.h>
#include <stdlib.h>
#include "driver.h"
#include "tree.h"

void calc_total_f(Tnode * node, double f_per_len, double parent_f)
{
    if(!node)
        return;
    node -> total_f = parent_f / 2;
    if(node -> label == -8)
        node -> total_f += (node -> len_l + node -> len_r) * f_per_len / 2;
    else
        node -> total_f += node -> sink_f;
}

Tnode * fill_total_f(Tnode * root, double f_per_len, double parent_f)
{
    if(!root)
        return NULL;
    calc_total_f(root, f_per_len, parent_f);
    parent_f = root -> len_l * f_per_len;
    root -> left = fill_total_f(root -> left, f_per_len, parent_f);
    parent_f = root -> len_r * f_per_len;
    root -> right = fill_total_f(root -> right, f_per_len, parent_f);
    return root;
}

double sum_f(Tnode * node)
{
    if(!node)
        return 0;
    node -> sum_f = node -> total_f + sum_f(node -> left) + sum_f(node -> right);
    return node -> sum_f;
}

void elmore_delay(Tnode * node, double parent_delay, double parent_ohm, double ohm_per_len)
{
    if(!node)
        return;
    node ->elmore_delay = parent_delay + parent_ohm * node -> sum_f;
    elmore_delay(node -> left, node -> elmore_delay, (node -> len_l * ohm_per_len), ohm_per_len);
    elmore_delay(node -> right, node -> elmore_delay, (node -> len_r * ohm_per_len), ohm_per_len);
}