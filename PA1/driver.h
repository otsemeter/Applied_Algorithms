#ifndef __DRIVER__
#define __DRIVER__
#include "tree.h"
void calc_total_f(Tnode * node, double f_per_len, double parent_f);
Tnode * fill_total_f(Tnode * root, double f_per_len, double parent_f);
double sum_f(Tnode * node);
void elmore_delay(Tnode * node, double parent_delay, double parent_ohm, double ohm_per_len);
#endif