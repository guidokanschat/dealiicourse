template <int dim>
void Poisson<dim>::solve () 
{
  PreconditionSSOR<SparseMatrix<double> > preconditioner;
  preconditioner.initialize(system_matrix);
  
  ReductionControl solver_control (100, 1.e-20, 1.e-10);
  SolverCG<> cg (solver_control);

  solution = 0;

  cg.solve (system_matrix, solution, right_hand_side,
	    preconditioner);
  
  constraints.distribute (solution);
}
