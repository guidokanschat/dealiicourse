template <int dim> class Poisson
{
  public:
    Poisson (const unsigned int deg);
    void run(unsigned int n_steps);
  private:
    void setup_system ();
    void setup_constraints ();
    void assemble_matrix ();
    void assemble_mg_matrix ();
    void assemble_right_hand_side ();
    void solve ();
    void refine_mesh (const bool global = false);
    void output_results (const unsigned int cycle) const;

    Triangulation<dim>   triangulation;
    MappingQ1<dim>       mapping;
    FE_Q<dim>            fe;
    DoFHandler<dim>&     dof_handler;

    SparsityPattern      sparsity_pattern;
    SparseMatrix<double> system_matrix;
    Vector<double>       solution, right_hand_side;
    ConstraintMatrix     constraints;
    
    MGDoFHandler<dim>    mg_dof_handler;
    MGConstrainedDoFs mg_constraints;
    MGLevelObject<SparsityPattern> mg_sparsity;
    MGLevelObject<SparseMatrix<double> > mg_matrices,
    mg_interface_matrices_up, mg_interface_matrices_down;
};
