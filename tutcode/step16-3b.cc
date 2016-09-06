template <int dim>
void LaplaceProblem<dim>::assemble_system ()
{
  MappingQ1<dim> mapping;
  MeshWorker::IntegrationInfoBox<dim> info_box;
  UpdateFlags update_flags = update_values
    | update_gradients | update_JxW_values;
  info_box.add_update_flags_all(update_flags);
  info_box.initialize(fe, mapping);
  
  MeshWorker::DoFInfo<dim> dof_info(dof_handler);
  ...
}
