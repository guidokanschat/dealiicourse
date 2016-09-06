void LaplaceProblem::make_grid ()
{
  GridGenerator::hyper_cube (triangulation,-1,1);
  triangulation.refine_global (5);
}
