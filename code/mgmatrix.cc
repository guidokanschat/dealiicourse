template <int dim>
void Poisson<dim>::assemble_mg_matrix () 
{  
  IntegrationInfoBox<dim> info_box;
  UpdateFlags update_flags = update_values | update_gradients;
  info_box.add_update_flags_all(update_flags);
  info_box.initialize(fe, mapping);

  DoFInfo<dim> dof_info(mg_dof_handler);

  Assembler::MGMatrixSimple<SparseMatrix<double> > assembler;
  assembler.initialize(mg_matrices);
  assembler.initialize(mg_constraints);
  assembler.initialize_interfaces(mg_interface_matrices_up, 
      mg_interface_matrices_down);
  
  integration_loop<dim, dim> (
    mg_dof_handler.begin(), mg_dof_handler.end(),
    dof_info, info_box,
    &MatrixIntegrator<dim>::cell, 0, 0,
    assembler);
}
