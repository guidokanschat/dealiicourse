typedef PreconditionSOR<SparseMatrix<double> > Smoother;
mg::SmootherRelaxation<Smoother, Vector<double> >
  mg_smoother;
mg_smoother.initialize(mg_matrices);
mg_smoother.set_steps(2);
mg_smoother.set_symmetric(true);
