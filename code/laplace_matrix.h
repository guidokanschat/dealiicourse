template <int dim>
void LaplaceMatrix<dim>::cell(
  DoFInfo<dim>& dinfo,
  IntegrationInfo<dim>& info) const
{
  Laplace::cell_matrix(dinfo.matrix(0).matrix,
		       info.fe_values(0));
}
