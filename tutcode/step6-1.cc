template <int dim>
void LaplaceProblem<dim>::refine_grid ()
{
  Vector<float> cell_errors (
    triangulation.n_active_cells());
  
  KellyErrorEstimator<dim>::estimate (
    dof_handler, QGauss<dim-1>(3),
    typename FunctionMap<dim>::type(),
    solution, cell_errors);

  GridRefinement::refine_and_coarsen_fixed_number (
    triangulation, cell_errors, 0.3, 0.0);
  
  triangulation.execute_coarsening_and_refinement ();
}
