QGauss<2>  quadrature_formula(2);
FEValues<2> fe_values (fe, quadrature_formula,
		       update_values
		       | update_gradients
		       | update_JxW_values);
[...]
for (; cell!=endc; ++cell)
{
  fe_values.reinit (cell);
    
  for (unsigned i=0; i<dofs_per_cell; ++i)
    for (unsigned q_point=0;
	 q_point<n_q_points; ++q_point)
      cell_rhs(i) += (fe_values.shape_value(i,q_point)
		      * 1
		      * fe_values.JxW (q_point));
}
