FE_Q<dim> q1(1);
FE_Q<dim> q2(2);
FE_DGQ<dim> dgq1(1);
FE_RaviartThomas<dim> rt1(1);

FESystem<dim> elasticity(q1,dim);
FESystem<dim> taylor_hood(q2, dim, q1, 1);
FESystem<dim> darcy(rt1, 1, dgq1,1);
