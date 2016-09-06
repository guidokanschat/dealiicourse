Assembler::ResidualSimple<Vector<double> > assembler;
NamedData<Vector<double>* > data;
Vector<double> *rhs = &right_hand_side;
data.add(rhs, "RHS");
assembler.initialize(data);
