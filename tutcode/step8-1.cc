cell_matrix(i,j)
+= (
  (fe_values.shape_grad(i,q_point)[comp_i] *
   fe_values.shape_grad(j,q_point)[comp_j] *
   lambda_values[q_point])
  +
  (fe_values.shape_grad(i,q_point)[comp_j] *
   fe_values.shape_grad(j,q_point)[comp_i] *
   mu_values[q_point])
  +
  ((comp_i == comp_j) ?
   (fe_values.shape_grad(i,q_point) *
    fe_values.shape_grad(j,q_point) *
    mu_values[q_point])  : 0)
) * fe_values.JxW(q_point);
