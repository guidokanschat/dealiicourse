Triangulation<2>::active_cell_iterator
cell = triangulation.begin_active(),
endc = triangulation.end();

for (; cell!=endc; ++cell)
  {
    decide_refinement(cell);
  }
