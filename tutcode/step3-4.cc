void LaplaceProblem::make_grid_and_dofs ()
{
  dof_handler.distribute_dofs (fe);
   
  DynamicSparsityPattern
     dsp(dof_handler.n_dofs());
  DoFTools::make_sparsity_pattern(dof_handler,dsp);
  sparsity_pattern.copy_from(dsp);
   
  system_matrix.reinit (sparsity_pattern);
   
  solution.reinit (dof_handler.n_dofs());
  system_rhs.reinit (dof_handler.n_dofs());
}
