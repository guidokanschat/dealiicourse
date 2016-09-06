MGTransferPrebuilt<Vector<double> >
  mg_transfer(hanging_node_constraints,
	      mg_constrained_dofs);

mg_transfer.build_matrices(dof_handler);
