template <int dim>
void
Matrix<dim>::cell(MeshWorker::DoFInfo<dim>& dinfo,
                  MeshWorker::IntegrationInfo<dim>& info) const
{
  AssertDimension(dinfo.n_matrices(), 4);
  Laplace::cell_matrix(dinfo.matrix(0, false).matrix,
                       info.fe_values(0));
  
  Divergence::cell_matrix(dinfo.matrix(2, false).matrix,
                          info.fe_values(0),
                          info.fe_values(1));
  dinfo.matrix(1, false).matrix.copy_transposed(
     dinfo.matrix(2, false).matrix);
}
