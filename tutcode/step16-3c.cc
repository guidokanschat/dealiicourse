template <int dim>
void LaplaceProblem<dim>::assemble_system ()
{
  ...

  MeshWorker::Assembler::SystemSimple<SparseMatrix<double>, Vector<double> > assembler;
  assembler.initialize(constraints);
  assembler.initialize(system_matrix, system_rhs);
  
  LaplaceIntegrator<dim> matrix_integrator;
  MeshWorker::integration_loop<dim, dim> (
  dof_handler.begin_active(), dof_handler.end(),
  dof_info, info_box, matrix_integrator, assembler);
  
  for (unsigned int i=0; i<dof_handler.n_dofs(); ++i)
  if (constraints.is_constrained(i))
    system_matrix.set(i, i, 1.);
}
