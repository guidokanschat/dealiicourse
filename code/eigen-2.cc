StokesIntegrators::Eigen<d> matrix_integrator;
AmandusApplication<d> app(tr, *fe);
app.parse_parameters(param);
ComponentMask boundary_components(d + 1, true);
boundary_components.set(d, false);
app.set_boundary(0, boundary_components);

app.set_number_of_matrices(2);
AmandusArpack<d> solver(app, matrix_integrator);

global_refinement_eigenvalue_loop(
  param.get_integer("Steps"),
  param.get_integer("Eigenvalues"),
  app, solver);
