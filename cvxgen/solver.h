/* Produced by CVXGEN, 2017-09-29 03:21:00 -0400.  */
/* CVXGEN is Copyright (C) 2006-2012 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2012 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.h. */
/* Description: Header file with relevant definitions. */
#ifndef SOLVER_H
#define SOLVER_H
/* Uncomment the next line to remove all library dependencies. */
/*#define ZERO_LIBRARY_MODE */
#ifdef MATLAB_MEX_FILE
/* Matlab functions. MATLAB_MEX_FILE will be defined by the mex compiler. */
/* If you are not using the mex compiler, this functionality will not intrude, */
/* as it will be completely disabled at compile-time. */
#include "mex.h"
#else
#ifndef ZERO_LIBRARY_MODE
#include <stdio.h>
#endif
#endif
/* Space must be allocated somewhere (testsolver.c, csolve.c or your own */
/* program) for the global variables vars, params, work and settings. */
/* At the bottom of this file, they are externed. */
#ifndef ZERO_LIBRARY_MODE
#include <math.h>
#define pm(A, m, n) printmatrix(#A, A, m, n, 1)
#endif
typedef struct Params_t {
  double y_0[1];
  double r_0[1];
  double q[1];
  double R[1];
  double r_1[1];
  double r_2[1];
  double r_3[1];
  double r_4[1];
  double r_5[1];
  double r_6[1];
  double r_7[1];
  double r_8[1];
  double r_9[1];
  double r_10[1];
  double r_11[1];
  double q_final[1];
  double A[9];
  double x_0[3];
  double B[3];
  double C[3];
  double u_max[1];
  double *y[1];
  double *r[12];
  double *x[1];
} Params;
typedef struct Vars_t {
  double *u_0; /* 1 rows. */
  double *y_1; /* 1 rows. */
  double *u_1; /* 1 rows. */
  double *y_2; /* 1 rows. */
  double *u_2; /* 1 rows. */
  double *y_3; /* 1 rows. */
  double *u_3; /* 1 rows. */
  double *y_4; /* 1 rows. */
  double *u_4; /* 1 rows. */
  double *y_5; /* 1 rows. */
  double *u_5; /* 1 rows. */
  double *y_6; /* 1 rows. */
  double *u_6; /* 1 rows. */
  double *y_7; /* 1 rows. */
  double *u_7; /* 1 rows. */
  double *y_8; /* 1 rows. */
  double *u_8; /* 1 rows. */
  double *y_9; /* 1 rows. */
  double *u_9; /* 1 rows. */
  double *y_10; /* 1 rows. */
  double *u_10; /* 1 rows. */
  double *y_11; /* 1 rows. */
  double *t_01; /* 1 rows. */
  double *t_02; /* 1 rows. */
  double *t_03; /* 1 rows. */
  double *t_04; /* 1 rows. */
  double *t_05; /* 1 rows. */
  double *t_06; /* 1 rows. */
  double *t_07; /* 1 rows. */
  double *t_08; /* 1 rows. */
  double *t_09; /* 1 rows. */
  double *t_10; /* 1 rows. */
  double *t_11; /* 1 rows. */
  double *x_1; /* 3 rows. */
  double *x_2; /* 3 rows. */
  double *x_3; /* 3 rows. */
  double *x_4; /* 3 rows. */
  double *x_5; /* 3 rows. */
  double *x_6; /* 3 rows. */
  double *x_7; /* 3 rows. */
  double *x_8; /* 3 rows. */
  double *x_9; /* 3 rows. */
  double *x_10; /* 3 rows. */
  double *x_11; /* 3 rows. */
  double *u[11];
  double *y[12];
  double *x[12];
} Vars;
typedef struct Workspace_t {
  double h[33];
  double s_inv[33];
  double s_inv_z[33];
  double b[44];
  double q[66];
  double rhs[176];
  double x[176];
  double *s;
  double *z;
  double *y;
  double lhs_aff[176];
  double lhs_cc[176];
  double buffer[176];
  double buffer2[176];
  double KKT[376];
  double L[392];
  double d[176];
  double v[176];
  double d_inv[176];
  double gap;
  double optval;
  double ineq_resid_squared;
  double eq_resid_squared;
  double block_33[1];
  /* Pre-op symbols. */
  double quad_804345917440[1];
  double quad_255575560192[1];
  double quad_896928452608[1];
  double quad_273478123520[1];
  double quad_833971425280[1];
  double quad_81086394368[1];
  double quad_357213134848[1];
  double quad_359950311424[1];
  double quad_786544324608[1];
  double quad_427454472192[1];
  double quad_9091186688[1];
  double quad_937999876096[1];
  int converged;
} Workspace;
typedef struct Settings_t {
  double resid_tol;
  double eps;
  int max_iters;
  int refine_steps;
  int better_start;
  /* Better start obviates the need for s_init and z_init. */
  double s_init;
  double z_init;
  int verbose;
  /* Show extra details of the iterative refinement steps. */
  int verbose_refinement;
  int debug;
  /* For regularization. Minimum value of abs(D_ii) in the kkt D factor. */
  double kkt_reg;
} Settings;
extern Vars vars;
extern Params params;
extern Workspace work;
extern Settings settings;
/* Function definitions in ldl.c: */
void ldl_solve(double *target, double *var);
void ldl_factor(void);
double check_factorization(void);
void matrix_multiply(double *result, double *source);
double check_residual(double *target, double *multiplicand);
void fill_KKT(void);

/* Function definitions in matrix_support.c: */
void multbymA(double *lhs, double *rhs);
void multbymAT(double *lhs, double *rhs);
void multbymG(double *lhs, double *rhs);
void multbymGT(double *lhs, double *rhs);
void multbyP(double *lhs, double *rhs);
void fillq(void);
void fillh(void);
void fillb(void);
void pre_ops(void);

/* Function definitions in solver.c: */
double eval_gap(void);
void set_defaults(void);
void setup_pointers(void);
void setup_indexed_params(void);
void setup_indexed_optvars(void);
void setup_indexing(void);
void set_start(void);
double eval_objv(void);
void fillrhs_aff(void);
void fillrhs_cc(void);
void refine(double *target, double *var);
double calc_ineq_resid_squared(void);
double calc_eq_resid_squared(void);
void better_start(void);
void fillrhs_start(void);
long solve(void);

/* Function definitions in testsolver.c: */
int main(int argc, char **argv);
void load_default_data(void);

/* Function definitions in util.c: */
void tic(void);
float toc(void);
float tocq(void);
void printmatrix(char *name, double *A, int m, int n, int sparse);
double unif(double lower, double upper);
float ran1(long*idum, int reset);
float randn_internal(long *idum, int reset);
double randn(void);
void reset_rand(void);

Vars start_calc(int argc, char **argv);

#endif
