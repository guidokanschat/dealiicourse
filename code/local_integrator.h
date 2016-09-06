template <int dim>
class LocalIntegrator
{
  public:
    void cell(DoFInfo<dim>& dinfo,
	      IntegrationInfo<dim>& info) const;
    void boundary(DoFInfo<dim>& dinfo,
		  IntegrationInfo<dim>& info) const;
    void face(DoFInfo<dim>& dinfo1,
	      DoFInfo<dim>& dinfo2,
              IntegrationInfo<dim>& info1,
	      IntegrationInfo<dim>& info2) const;
};
