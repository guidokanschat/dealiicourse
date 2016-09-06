template <int dim>
void Poisson<dim>::output_results (unsigned int cycle) const
{
  DataOut<dim> data_out;

  data_out.attach_dof_handler (mg_dof_handler);
  data_out.add_data_vector (solution, "solution");
  data_out.build_patches ();

  std::ostringstream filename;
  filename << "solution-" << cycle << ".gpl";

  std::ofstream output (filename.str().c_str());
  data_out.write_gnuplot (output);
}
