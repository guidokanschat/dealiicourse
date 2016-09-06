for (unsigned int cycle=0; cycle<6; ++cycle)
  {
    if (cycle != 0)
      triangulation.refine_global (1);
    
    setup_system ();
    assemble_system ();
    solve ();
    output_results (cycle);
  }
