template <int dim>
Poisson<dim>::Poisson (const unsigned int degree)
		:
		triangulation (Triangulation<dim>::limit_level_difference_at_vertices),
		fe (degree),
		mg_dof_handler (triangulation),
		dof_handler(mg_dof_handler)
{
  GridGenerator::hyper_cube (triangulation, -1, 1);
}
