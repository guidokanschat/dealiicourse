void decide_refinement(
  Triangulation<2>::active_cell_iterator& cell)
{
  for (unsigned int v=0; v < 4; ++v)
    {
      const double distance
	= center.distance (cell->vertex(v));
      
      if (std::fabs(distance - inner_radius) < 1e-10)
	{
	  cell->set_refine_flag ();
	  break;
	}
    }
}
