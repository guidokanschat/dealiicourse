  constraints.clear ();
  DoFTools::make_hanging_node_constraints (
    dof_handler, constraints);
  constraints.close ();
