NamedData<Vector<double>* > solution_data;
solution_data.add(&solution, "solution");
info_box.cell_selector.add("solution", false, false, true);
info_box.boundary_selector.add("solution", true, true, false);
info_box.face_selector.add("solution", true, true, false);

info_box.add_update_flags_boundary(update_quadrature_points);
info_box.initialize(fe, mapping, solution_data);

DoFInfo<dim> dof_info(dof_handler);
