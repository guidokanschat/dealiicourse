for (Triangulation<2>::cell_iterator
       cell = triangulation.begin(level);
     cell != triangulation.end(level);
     ++cell)
  {
    do_something(cell);
  }
