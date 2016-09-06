#include <deal.II/fe/fe_raviart_thomas.h>

#include "shapes.h"

int main()
{
  dealii::FE_RaviartThomas<2> fe(1);
  plot_shapes("rt1", fe);
}
