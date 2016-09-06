Assembler::MGMatrixSimple<SparseMatrix<double> >
  assembler;
assembler.initialize(mg_matrix);
assembler.initialize_fluxes(mg_matrix_dg_up,
                            mg_matrix_dg_down);
