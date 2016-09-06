cell->get_dof_indices (local_dof_indices);

for (unsigned int i=0; i<dofs_per_cell; ++i)
  for (unsigned int j=0; j<dofs_per_cell; ++j)
    system_matrix.add (local_dof_indices[i],
		       local_dof_indices[j],
		       cell_matrix(i,j));
