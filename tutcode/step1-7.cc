void second_grid ()
{
  Triangulation<2> triangulation;
  
  const Point<2> center (1,0);
  const double inner_radius = 0.5,
               outer_radius = 1.0;
  GridGenerator::hyper_shell (triangulation,
                              center, inner_radius, outer_radius,
                              10);
  const HyperShellBoundary<2> boundary_description(center);
  triangulation.set_boundary (0, boundary_description);
  
  for (unsigned int step=0; step<5; ++step)
    {
      Triangulation<2>::active_cell_iterator
        cell = triangulation.begin_active(),
        endc = triangulation.end();
      
      for (; cell!=endc; ++cell)
        for (unsigned int v=0; v < 4; ++v)
          {
            const double distance_from_center
              = center.distance (cell->vertex(v));
            
            if (std::fabs(distance_from_center - inner_radius) < 1e-10)
              {
                cell->set_refine_flag ();
                break;
              }
          }
      triangulation.execute_coarsening_and_refinement ();
    }
}
