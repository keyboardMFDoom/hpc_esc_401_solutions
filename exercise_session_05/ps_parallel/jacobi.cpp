#include "jacobi.h"
#include <math.h>
#include <omp.h>
/**
 * @brief      Computes norm of the difference between two matrices
 *
 * @param[in]  p     Parameters
 * @param      mat1  The matrix 1
 * @param      mat2  The matrix 2
 *
 * @return     Returns \sqrt{\sum(mat1_{ij} - mat2_{ij})^2/(nx*ny)}
 */
double norm_diff(params p, double** mat1, double** mat2){
    double sum = 0.0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < p.nx; ++i){
        for (int j = 0; j < p.ny; ++j){
            double d = mat1[i][j] - mat2[i][j];
            sum += d * d;
        }
    }
    double mean = sum / double(p.nx * p.ny);
    return std::sqrt(mean);
}
/**
 * @brief      Compute a Jacobi iteration to solve Poisson equation. This function updates
 *             u_new and u_old in-place.
 *
 * @param[in]  p      Parameters
 * @param      u_new  The new solution
 * @param      u_old  The old solution
 * @param      f      The source term
 */

void jacobi_step(params p, double** u_new, double** u_old, double** f) {

    double dx = 1.0 / double(p.nx - 1);
    double dy = 1.0 / double(p.ny - 1);
    double dx2 = dx * dx;  
    #pragma omp parallel for
    for (int i = 0; i < p.nx; ++i) {
        for (int j = 0; j < p.ny; ++j) {
            u_old[i][j] = u_new[i][j];
        }
    }
    #pragma omp parallel for
    for (int i = 1; i < p.nx - 1; ++i) {
        for (int j = 1; j < p.ny - 1; ++j) {
            u_new[i][j] = 0.25 * (
                u_old[i-1][j] +
                u_old[i+1][j] +
                u_old[i][j-1] +
                u_old[i][j+1] -
                dx2 * f[i][j]
            );
        }
    }
    #pragma omp parallel for
    for (int i = 0; i < p.nx; ++i) {
        u_new[i][0] = f[i][0];
        u_new[i][p.ny - 1] = f[i][p.ny - 1];
    }
    #pragma omp parallel for
    for (int j = 0; j < p.ny; ++j) {
        u_new[0][j] = f[0][j];
        u_new[p.nx - 1][j] = f[p.nx - 1][j];
    }
}      
