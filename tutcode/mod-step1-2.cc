void first_grid ()
{
  Triangulation<2> triangulation;

  GridGenerator::hyper_cube (triangulation);
  triangulation.refine_global (1);
  triangulation.begin_active()->set_refine_flag();
  triangulation.execute_coarsening_and_refinement ();
  
  std::ofstream out ("grid-1.svg");
  GridOut grid_out;
  GridOutFlags::Svg flags;
  flags.width=1000;
  flags.polar_angle = 60;
  flags.azimuth_angle = 10;
  flags.convert_level_number_to_height = true;
  flags.level_height_factor = .6;
  flags.draw_legend = false;
  flags.draw_colorbar = false;
  grid_out.set_flags(flags);
  grid_out.write_svg (triangulation, out);
  std::cout << "Grid written to grid-1.eps" << std::endl;
}
