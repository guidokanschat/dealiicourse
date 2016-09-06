Triangulation<dim> triangulation
GridGenerator::hyper_cube(triangulation);
triangulation.refine_global(5);

FE_Q<dim> element(3);
DoFHandler<dim> dof_handler(triangulation);
dof_handler.distribute_dofs(element);
