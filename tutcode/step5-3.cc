MappingQ1<dim> mapping;
QGauss<dim> quadrature(3);
Vector<double> cell_errors(triangulation.n_active_cells());
VectorTools::integrate_difference(
  mapping, dof_handler,
  solution, exact_solution,
  cell_errors, quadrature, VectorTools::H1_seminorm);
std::cout << "Error " << cell_errors.l2_norm() << std::endl;
