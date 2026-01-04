#include <TGraph.h>

std::unique_ptr<TGraph> get_scorr(const int ifeech)
{
  std::array<double,2> x{0,1};
  std::array<double,2> y{1,2};
  auto a = std::make_unique<TGraph>(2,x.data(),y.data());
  return a;
}

void x()
{
  auto g = get_scorr(0);
  g->SetMarkerStyle(20);
  g->SetMarkerSize(1);
  g->Draw();

  gPad->Modified();
  gPad->Update();

  string junk;
  cin >> junk;
}

