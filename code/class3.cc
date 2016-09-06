template <int dim> class Poisson
{
  private:
    MGDoFHandler<dim>    mg_dof_handler;
    MGConstrainedDoFs mg_constraints;
    MGLevelObject<SparsityPattern> mg_sparsity;
    MGLevelObject<SparseMatrix<double> > mg_matrices;
    MGLevelObject<SparseMatrix<double> > mg_interface_matrices_up;
    MGLevelObject<SparseMatrix<double> > mg_interface_matrices_down;
};

