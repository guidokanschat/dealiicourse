for (Triangulation<2>::active_cell_iterator cell
       = triangulation.begin_active();
     cell != triangulation.end();
     ++cell)
  {
    do_something(cell);
  }
