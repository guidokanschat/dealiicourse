for (unsigned int level=0; level<n_levels; ++level)
  {
    DynamicSparsityPattern csp;
    csp.reinit(dof_handler.n_dofs(level),
	       dof_handler.n_dofs(level));
    MGTools::make_sparsity_pattern(dof_handler, csp, level);
    
    mg_sparsity_patterns[level].copy_from (csp);
    
    mg_matrices[level].reinit(mg_sparsity_patterns[level]);
    mg_interface_matrices[level].reinit(mg_sparsity_patterns[level]);
  }
