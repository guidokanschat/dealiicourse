template <int dim>
void Poisson<dim>::setup_system ()
{
  system_matrix.clear();
  dof_handler.distribute_dofs (fe);
  setup_constraints ();
  const unsigned int n_dofs = dof_handler.n_dofs();
  
  CompressedSparsityPattern csp (n_dofs, n_dofs);
  DoFTools::make_sparsity_pattern(dof_handler, csp,
				  constraints);
  sparsity_pattern.copy_from (csp);
  system_matrix.reinit (sparsity_pattern);

  solution.reinit(n_dofs);
  right_hand_side.reinit(n_dofs);
  
  // multigrid
}
