template <int dim>
void AllenCahnMatrix<dim>::cell(
  DoFInfo<dim>& dinfo,
  IntegrationInfo<dim>& info) const
{
  auto fe = info.fe_values(0);
  auto M = dinfo.matrix(0).matrix;

  std::vector<double> fu(fe.n_quadrature_points);
  for (unsigned int k=0;k<fu.size();++k)
    {
      const double u = info.values[0][0][k];
      fu[k] = (3.*u*u-1.);
    }
  Laplace::cell_matrix(M, fe, D);
  L2::weighted_mass_matrix(M, fe, fu);
  L2::mass_matrix(M, fe, 1./dt);
}
