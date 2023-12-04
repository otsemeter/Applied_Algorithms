#include <stdio.h>
#include <stdlib.h>
#include "read.h"
#include "tree.h"
#include "write.h"
#include "driver.h"

int main(int argc, char ** argv)
{
    int num_nodes;

    double in_f, out_f, out_r, ohm_per_len, f_per_len;
    float time_constraint = read_time_constraint(argv[1]);
    printf("Time Constraint: %f\n", time_constraint);
    read_inv_params(argv[2], &in_f, &out_f, &out_r);
    read_wire_params(argv[3], &ohm_per_len, &f_per_len);
    double ** node_arr = read_RC_tree(argv[4], &num_nodes);
    int idx = num_nodes;
    Tnode * root = build_tree(node_arr, &idx);
    FILE * fptr = fopen(argv[5], "w");
    write_pre(fptr, root);
    fclose(fptr);

    root = fill_total_f(root, f_per_len, 2 * out_f);
    root -> sum_f = sum_f(root);
    elmore_delay(root,0, out_r, ohm_per_len);
    fptr = fopen(argv[6], "w");
    write_elmore(fptr, root);
    fclose(fptr);

    for(int i  = 0; i < num_nodes; i++)
    {
        free(node_arr[i]);
    }
    free(node_arr);
    destroy_tree(root);
    return EXIT_SUCCESS;
}