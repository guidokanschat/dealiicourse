template <int dim>
void MatrixIntegrator<dim>::cell(
  DoFInfo<dim>& dinfo, IntegrationInfo<dim>& info)
{
  const FEValuesBase<dim>& fe = info.fe_values();
  FullMatrix<double>& local_matrix
         = dinfo.matrix(0,false).matrix;
  
  for (unsigned int k=0; k<fe.n_quadrature_points; ++k)
    for (unsigned int i=0; i<fe.dofs_per_cell; ++i)
      for (unsigned int j=0; j<fe.dofs_per_cell; ++j)
	
        local_matrix(i,j) += (fe.shape_grad(i,k)
                              * fe.shape_grad(j,k))
                              * fe.JxW(k);
}
