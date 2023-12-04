#ifndef __read__
#define __read__
float read_time_constraint(char * tc_string);
void read_inv_params(char * filename, double * in_f, double * out_f, double * out_r);
void read_wire_params(char * filename, double *  ohm_per_len, double * f_per_len);
double ** read_RC_tree(char * filename, int * num_nodes);
void read_elmore(char * filename, int * labels, double * delays, int size);
#endif