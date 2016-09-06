template <int dim>
void Poisson<dim>::solve () 
{
  MGTransferPrebuilt<Vector<double> > mg_transfer(hnc, mg_constraints);
  mg_transfer.build_matrices(mg_dof_handler);

  FullMatrix<double> coarse_matrix;
  coarse_matrix.copy_from (mg_matrices[0]);
  MGCoarseGridHouseholder<double, Vector<double> > mg_coarse;
  mg_coarse.initialize(coarse_matrix);

  typedef PreconditionSSOR<SparseMatrix<double> > RELAXATION;
  MGSmootherRelaxation<SparseMatrix<double>, RELAXATION, Vector<double> >
    mg_smoother;
  mg_smoother.initialize(mg_matrices);

  MGMatrix<SparseMatrix<double>, Vector<double> >
    mg_matrix(&mg_matrices);
  MGMatrix<SparseMatrix<double>, Vector<double> >
    mg_interface_up(&mg_interface_matrices_up);
  MGMatrix<SparseMatrix<double>, Vector<double> >
    mg_interface_down(&mg_interface_matrices_down);

  Multigrid<Vector<double> > mg(mg_dof_handler,
      mg_matrix, mg_coarse, mg_transfer,
      mg_smoother, mg_smoother);
  mg.set_edge_matrices(mg_interface_down, mg_interface_up);

  PreconditionMG<dim, Vector<double>,
    MGTransferPrebuilt<Vector<double> > >
      preconditioner(mg_dof_handler, mg, mg_transfer);
  
  ...
}
