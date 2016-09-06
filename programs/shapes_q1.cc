#include <deal.II/fe/fe_q.h>

#include "shapes.h"

int main()
{
  dealii::FE_Q<2> fe(1);
  plot_shapes("q1", fe);
}
