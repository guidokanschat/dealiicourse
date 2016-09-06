dealii::MeshWorker::loop<d,d,DOFINFO,INFOBOX>
  (dof_handler.begin_active(), dof_handler.end(),dof_info, info_box,
   [](DOFINFO& dinfo, typename INFOBOX::CellInfo& info)
   {
     Laplace::cell_matrix(dinfo.matrix(0,false).matrix,info.fe_values(0));
   },
   nullptr, nullptr, assembler);
