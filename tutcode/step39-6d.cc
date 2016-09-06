Assembler::CellsAndFaces<double> assembler;
NamedData<BlockVector<double>* > out_data;
BlockVector<double> *est = &estimates;
out_data.add(est, "cells");
assembler.initialize(out_data, false);
