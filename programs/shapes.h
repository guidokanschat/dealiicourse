#include <deal.II/grid/tria.h>
#include <deal.II/grid/grid_generator.h>
#include <deal.II/dofs/dof_handler.h>
#include <deal.II/numerics/vector_tools.h>
#include <deal.II/numerics/data_out.h>

#include <fstream>

using namespace dealii;

template <int dim>
void plot_shapes (const char* filebase,
		  const FiniteElement<dim>& fe)
{
  Triangulation<dim> tr;
  GridGenerator::subdivided_hyper_cube(tr, 5, -1., 1.);
  DoFHandler<dim> dof(tr);
  dof.distribute_dofs(fe);
  
  // Search center cell
  typename DoFHandler<dim>::active_cell_iterator cell = dof.begin();
  cell = cell->neighbor(1)->neighbor(1);
  cell = cell->neighbor(3)->neighbor(3);
  if (dim>2)
    cell = cell->neighbor(5)->neighbor(5);
  
  std::vector<unsigned int> indices(fe.dofs_per_cell);
  cell->get_dof_indices(indices);
  
  std::vector<Vector<double> > v(fe.dofs_per_cell, Vector<double>(dof.n_dofs()));
  for (unsigned int i=0;i<v.size();++i)
    v[i](indices[i]) = 1.;
  
  DataOut<dim> out;
  out.attach_dof_handler(dof);
  for (unsigned int i=0;i<v.size();++i)
    out.add_data_vector(v[i], "phi");
  out.build_patches(5);

  std::ostringstream filename;
  filename << filebase
	   << ".gpl";

  std::ofstream output (filename.str().c_str());
  out.write_gnuplot (output);
}
