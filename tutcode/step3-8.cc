void LaplaceProblem::solve ()
{
  SolverControl solver_control (1000, 1e-12);
  SolverCG<> solver (solver_control);

  solver.solve (system_matrix,
		solution, system_rhs,
                PreconditionIdentity());
}
