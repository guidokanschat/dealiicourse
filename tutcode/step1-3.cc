void second_grid ()
{
  Triangulation<2> triangulation;
  
  const Point<2> center (1,0);
  const double inner_radius = 0.5,
               outer_radius = 1.0;
  GridGenerator::hyper_shell (triangulation,
                              center,
			      inner_radius,
			      outer_radius,
                              10);
  triangulation.set_all_manifold_ids(0);
  const SphericalManifold<2> manifold_description(center);
  triangulation.set_manifold (0, manifold_description);
  
