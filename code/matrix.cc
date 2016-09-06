template <int dim>
void Poisson<dim>::assemble_matrix () 
{  
  IntegrationInfoBox<dim> info_box;
  UpdateFlags update_flags = update_values | update_gradients;
  info_box.add_update_flags_all(update_flags);
  info_box.initialize(fe, mapping);

  DoFInfo<dim> dof_info(dof_handler);
  
  Assembler::MatrixSimple<SparseMatrix<double> > assembler;
  assembler.initialize(system_matrix);
  assembler.initialize(constraints);

  integration_loop<dim, dim>(
    dof_handler.begin_active(), dof_handler.end(),
    dof_info, info_box,
    &MatrixIntegrator<dim>::cell, 0, 0,
    assembler);
}
