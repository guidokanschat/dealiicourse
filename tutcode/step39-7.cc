YourFavoriteIntegrator<dim> integrator;

integration_loop<dim, dim> (
  dof_handler.begin_active(),
  dof_handler.end(),
  dof_info, info_box,
  integrator, assembler);
