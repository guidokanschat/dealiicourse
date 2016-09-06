using namespace dealii::LocalIntegrators;

template <int dim>
void MatrixIntegrator<dim>::face(
  DoFInfo<dim> &dinfo1,
  DoFInfo<dim> &dinfo2,
  IntegrationInfo<dim> &info1,
  IntegrationInfo<dim> &info2) const
{
  const unsigned int deg
     = info1.fe_values(0).get_fe().tensor_degree();
  Laplace::ip_matrix(
    dinfo1.matrix(0,false).matrix,
    dinfo1.matrix(0,true).matrix,
    dinfo2.matrix(0,true).matrix,
    dinfo2.matrix(0,false).matrix,
    info1.fe_values(0), info2.fe_values(0),
    Laplace::compute_penalty(dinfo1, dinfo2, deg, deg));
}
