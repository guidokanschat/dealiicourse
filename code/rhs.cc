template <int dim>
void Poisson<dim>::assemble_right_hand_side()
{
  rhs = 0.;
  IntegrationInfoBox<dim> info_box;
  info_box.initialize_update_flags();
  info_box.add_update_flags_all(update_flags);
  info_box.initialize(fe, mapping);
  
  DoFInfo<dim> dof_info(dof_handler);
  Assembler::ResidualSimple<Vector<double> > assembler;
  AnyData data;
  data.add<Vector<double> >(right_hand_side, "rhs");

  assembler.initialize(data);
  assembler.initialize(constraints);
  integration_loop<dim, dim>(
    dof_handler.begin_active(), dof_handler.end(),
    dof_info, info_box,
    &RHSIntegrator<dim>::cell, 0, 0,
    assembler);
}
