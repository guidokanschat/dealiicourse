void LaplaceProblem::run ()
{
  make_grid_and_dofs ();
  assemble_system ();
  solve ();
  output_results ();
}
