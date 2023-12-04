#include <stdio.h>
#include <stdlib.h>
#include "read.h"
#include "tree.h"

float read_time_constraint(char * tc_string)
{
    return atof(tc_string);
}

void read_inv_params(char * filename, double * in_f, double * out_f, double * out_r)
{
    FILE * fptr = fopen(filename, "r");

    fscanf(fptr, "%lf %lf %lf\n", in_f, out_f, out_r);

    fclose(fptr);
}

void read_wire_params(char * filename, double *  ohm_per_len, double * f_per_len)
{
    FILE * fptr = fopen(filename, "r");

    fscanf(fptr, "%lf %lf\n", ohm_per_len, f_per_len);

    fclose(fptr);
}

double ** read_RC_tree(char * filename, int * num_nodes)
{
    char name;
    FILE * fptr = fopen(filename, "r");

    int count = 0;
    for (char c = getc(fptr); c != EOF; c = getc(fptr))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    *num_nodes = count;

    rewind(fptr);

    double ** arr = malloc(sizeof(double *) * count);
    for(int i = 0; i < count; i++)
    {
        arr[i] = malloc(sizeof(double) * 4);
        if(arr[i] == NULL)
        {
            fprintf(stderr, "malloc fail");
        }
    }

    for(int i = 0; i < count; i++)
    {
        fscanf(fptr, "%c", &name);
        if(name == '(')
            fscanf(fptr, "%lf %lf)\n", arr[i] + 2, arr[i] + 3);
        else
            fscanf(fptr, "(%lf)\n", arr[i] + 1);
        arr[i][0] = name - 48;
        //printf("%d ", (int)arr[i][0]);
    }
    fclose(fptr);
    return arr;
}

void read_elmore(char * filename, int * labels, double * delays, int size)
{
    FILE * fptr = fopen(filename, "r");
    for(int i = 0; i < size; i++)
    {
        fread(labels + i, sizeof(int), 1, fptr);
        fread(delays + i, sizeof(double), 1, fptr);
    }
    fclose(fptr);
}