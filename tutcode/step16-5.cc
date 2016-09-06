FullMatrix<double> coarse_matrix;
coarse_matrix.copy_from (mg_matrices[0]);
MGCoarseGridHouseholder<> coarse_grid_solver;
coarse_grid_solver.initialize (coarse_matrix);
