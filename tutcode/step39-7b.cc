YourFavoriteIntegrator<dim> integrator;

integration_loop<dim, dim> (
  dof_handler.begin_mg(),
  dof_handler.end_mg(),
  dof_info, info_box,
  integrator, assembler);
