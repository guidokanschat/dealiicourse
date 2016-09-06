template <int dim>
void LaplaceIntegrator<dim>::cell(
   MeshWorker::DoFInfo<dim> &dinfo,
   MeshWorker::IntegrationInfo<dim> &info) const
{
  LocalIntegrators::Laplace::cell_matrix(
     dinfo.matrix(0,false).matrix,
     info.fe_values(0));
}
