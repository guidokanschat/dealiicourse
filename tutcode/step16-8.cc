PreconditionMG<dim, Vector<double>,
	       MGTransferPrebuilt<Vector<double> > >
preconditioner(dof_handler, mg, mg_transfer);

cg.solve (system_matrix, solution,
          system_rhs,
          preconditioner);

constraints.distribute (solution);
