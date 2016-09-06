StokesIntegrators::Matrix<d> matrix_integrator;
StokesIntegrators::PolynomialRHS<d>
  rhs_integrator(rhs_function);
StokesIntegrators::PolynomialError<d>
  error_integrator(true_solution);

AmandusApplication<d> app(tr, *fe);
app.parse_parameters(param);
ComponentMask boundary_components(d + 1, true);
boundary_components.set(d, false);
app.set_boundary(0, boundary_components);
AmandusSolve<d> solver(app, matrix_integrator);
AmandusResidual<d> residual(app, rhs_integrator);

global_refinement_linear_loop(5, app, solver,
                              residual,
                              &error_integrator);
