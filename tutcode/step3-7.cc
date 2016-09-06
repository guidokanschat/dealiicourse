  std::map<unsigned int,double> boundary_values;
  VectorTools::interpolate_boundary_values (
    dof_handler,
    0,
    ZeroFunction<2>(),
    boundary_values);
  MatrixTools::apply_boundary_values (
    boundary_values,
    system_matrix,
    solution,
    system_rhs);
