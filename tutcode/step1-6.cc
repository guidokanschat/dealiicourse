for (unsigned int step=0; step<5; ++step)
  {
    refinement_selection_loop(triangulation);
    triangulation.execute_coarsening_and_refinement ();
  }
