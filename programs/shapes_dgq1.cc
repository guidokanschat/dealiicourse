#include <deal.II/fe/fe_dgq.h>

#include "shapes.h"

int main()
{
  dealii::FE_DGQ<2> fe(1);
  plot_shapes("dgq1", fe);
}
