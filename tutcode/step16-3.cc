template <int dim>
class LaplaceIntegrator
  : public MeshWorker::LocalIntegrator<dim>
{
public:
  LaplaceIntegrator();
  virtual void cell(MeshWorker::DoFInfo<dim> &,
	    MeshWorker::IntegrationInfo<dim> &) const;
};

template <int dim>
LaplaceIntegrator<dim>::LaplaceIntegrator()
  :
  MeshWorker::LocalIntegrator<dim>(true, false, false)
{}
