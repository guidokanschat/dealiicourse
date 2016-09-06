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
    void refine_mesh (bool global = false);
    void output_results (unsigned int cycle) const;
};
