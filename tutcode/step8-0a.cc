const double value_i = fe_shape_value(i, q_point);
const unsigned int comp_i =
  fe.system_to_component_index(i).first;
