template <int dim> class Poisson
{
  private:
    Triangulation<dim>   triangulation;
    MappingQ1<dim>       mapping;
    FE_Q<dim>            fe;
    DoFHandler<dim>&     dof_handler;

    SparsityPattern      sparsity_pattern;
    SparseMatrix<double> system_matrix;
    Vector<double>       solution;
    Vector<double>       right_hand_side;
    ConstraintMatrix     constraints;
    ConstraintMatrix     hnc;
};
