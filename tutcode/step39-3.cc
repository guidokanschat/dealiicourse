using namespace dealii::LocalIntegrators;

template <int dim>
void MatrixIntegrator<dim>::boundary(
  DoFInfo<dim> &dinfo,
  IntegrationInfo<dim> &info) const
{
  const unsigned int deg
    = info.fe_values(0).get_fe().tensor_degree();
  Laplace::nitsche_matrix(
    dinfo.matrix(0,false).matrix, info.fe_values(0),
    Laplace::compute_penalty(dinfo, dinfo, deg, deg));
}
