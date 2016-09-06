template <int dim>
void Poisson<dim>::run(unsigned int n_steps)
{
  for (unsigned int cycle=0; cycle<n_steps; ++cycle)
  {
    refine_mesh ();
    setup_system ();
    assemble_matrix ();
    assemble_mg_matrix ();
    assemble_right_hand_side ();
    solve ();
    output_results(cycle);
  }
}
