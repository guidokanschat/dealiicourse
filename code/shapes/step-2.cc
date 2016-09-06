/* ---------------------------------------------------------------------
 *
 * Copyright (C) 1999 - 2015 by the deal.II authors
 *
 * This file is part of the deal.II library.
 *
 * The deal.II library is free software; you can use it, redistribute
 * it, and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * The full text of the license can be found in the file LICENSE at
 * the top level of the deal.II distribution.
 *
 * ---------------------------------------------------------------------

 *
 * Author: Wolfgang Bangerth, University of Heidelberg, 1999
 */


#include <deal.II/grid/tria.h>
#include <deal.II/grid/grid_out.h>
#include <deal.II/grid/grid_generator.h>
#include <deal.II/grid/manifold_lib.h>

#include <deal.II/dofs/dof_handler.h>

#include <deal.II/fe/fe_q.h>
#include <deal.II/fe/fe_dgq.h>
#include <deal.II/numerics/data_out.h>
#include <deal.II/dofs/dof_tools.h>
#include <deal.II/lac/vector_memory.h>
#include <deal.II/lac/vector.h>

#include <deal.II/dofs/dof_renumbering.h>

#include <fstream>

using namespace dealii;


void make_grid (Triangulation<2> &triangulation)
{
  GridGenerator::hyper_cube (triangulation);
}


void plot_basis (const DoFHandler<2>& dof_handler,
		 std::string name)
{
  const unsigned int n = dof_handler.n_dofs();
  std::vector<Vector<double>> v(n);

  std::ofstream gridfile(name+"_grid.vtk");
  GridOut grid_out;
  grid_out.write_vtk(dof_handler.get_triangulation(), gridfile);
  
  DataOut<2> data_out;
  data_out.attach_dof_handler (dof_handler);

  for (unsigned int i=0;i<n;++i)
    {
      v[i].reinit(n);
      v[i][i] = 1.;
      char vname[100];
      sprintf(vname, "v%03d", i);
      data_out.add_data_vector(v[i], vname);
    }

  data_out.build_patches(10);
  std::string fname = name + ".vtk";
  std::ofstream output (fname);
  data_out.write_vtk (output);
}

int main ()
{
  Triangulation<2> triangulation;
  make_grid (triangulation);

  const FE_DGQ<2> dg(2);
  const FE_Q<2> cg(2);
  DoFHandler<2> dof_handler (triangulation);
  
  dof_handler.distribute_dofs (dg);
  plot_basis(dof_handler, "shapes");

  triangulation.refine_global(1);

  dof_handler.distribute_dofs (dg);
  plot_basis(dof_handler, "dgbasis1");

  dof_handler.distribute_dofs (cg);
  plot_basis(dof_handler, "cgbasis1");

  triangulation.begin_active()->set_refine_flag();
  triangulation.execute_coarsening_and_refinement();

  dof_handler.distribute_dofs (dg);
  plot_basis(dof_handler, "dgbasis2");

  dof_handler.distribute_dofs (cg);
  plot_basis(dof_handler, "cgbasis2");
}
