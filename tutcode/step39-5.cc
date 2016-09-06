IntegrationInfoBox<dim> info_box;
UpdateFlags update_flags
  = update_values | update_gradients;
info_box.add_update_flags_all(update_flags);
info_box.initialize(fe, mapping);

DoFInfo<dim> dof_info(dof_handler);
