  template <int dim>
  void MatrixIntegrator<dim>::cell(
    DoFInfo<dim> &dinfo,
    IntegrationInfo<dim> &info) const
  {
    LocalIntegrators::Laplace::cell_matrix(
       dinfo.matrix(0,false).matrix,
       info.fe_values());
  }
