template <int dim>
class LaplaceProblem
{
  MGLevelObject<SparsityPattern>
     mg_sparsity_patterns;
  MGLevelObject<SparseMatrix<double> >
     mg_matrices;
  MGLevelObject<SparseMatrix<double> >
     mg_interface_matrices;
  MGConstrainedDoFs mg_constrained_dofs;
};
