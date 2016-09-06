cell_rhs(i)
  += fe_values.shape_value(i,q_point) *
     rhs_values[q_point](comp_i) *
     fe_values.JxW(q_point);
