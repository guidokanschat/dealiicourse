GridIn<dim> grid_in;
grid_in.attach_triangulation (triangulation);
std::ifstream input_file("circle-grid.inp");
grid_in.read_ucd (input_file);
