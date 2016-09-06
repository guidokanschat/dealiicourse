mg::Matrix<> mg_matrix(&mg_matrices);
mg::Matrix<> mg_in(&mg_interface_matrices);
mg::Matrix<> mg_out(&mg_interface_matrices);

Multigrid<Vector<double> >
  mg(dof_handler,
     mg_matrix,
     coarse_grid_solver,
     mg_transfer,
     mg_smoother,
     mg_smoother);
mg.set_edge_matrices(mg_in, mg_out);
