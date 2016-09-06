dof_handler.distribute_dofs (fe);
dof_handler.distribute_mg_dofs (fe);
mg_constrained_dofs.clear();
mg_constrained_dofs.initialize(dof_handler, dirichlet_boundary);

mg_interface_matrices.resize(0, n_levels-1);
mg_interface_matrices.clear ();
mg_matrices.resize(0, n_levels-1);
mg_matrices.clear ();
mg_sparsity_patterns.resize(0, n_levels-1);
