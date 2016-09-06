template <int dim>
void AllenCahnResidual<dim>::cell(
  DoFInfo<dim>& dinfo, 
  IntegrationInfo<dim>& info) const
{
  auto fe = info.fe_values(0);
  auto V = dinfo.vector(0).block(0)
  
  std::vector<double> rhs (fe.n_quadrature_points, 0.);
  for (unsigned int k=0;k<rhs.size();++k)
    {
      const double u = info.values[0][0][k];
      const double u_old = info.values[1][0][k];
      rhs[k] += u*(u*u-1.) + 1./dt*(u-u_old);
    }
  Laplace::cell_residual(V, fe, info.gradients[0][0], D);
  L2::L2(V, fe, rhs);
}
