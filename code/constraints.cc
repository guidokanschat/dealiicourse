template <int dim>
void Poisson<dim>::setup_constraints()
{
  constraints.clear();

  typename FunctionMap<dim>::type homogen_bc;
  ZeroFunction<dim> zero_function;
  homogen_bc[0] = &zero_function;
  VectorTools::interpolate_boundary_values (
    mapping,
    dof_handler,
    homogen_bc,
    constraints);

  DoFTools::make_hanging_node_constraints (
    mg_dof_handler,
    constraints);
  constraints.close();
}
