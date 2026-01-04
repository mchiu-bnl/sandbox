#include <iostream>
#include <vector>
#include <cmath>
#include <TRandom3.h>

// Define the sinc function
Double_t mysinc(Double_t *x, Double_t *par)
{
  Double_t xx = x[0];
  if ( xx == 0. ) return par[0];

  Double_t f = par[0] * (sin(par[1]*xx) / (par[1]*xx));

  return f;
}

double sinc(double x) {
  if (x == 0.0) {
    return 1.0;
  } else {
    return std::sin(M_PI * x) / (M_PI * x);
  }
}

TF1 *fsinc {nullptr};

// Perform windowed sinc interpolation
std::vector<double> windowedSincInterpolation(
    const std::vector<double>& x,
    const std::vector<double>& y,
    const std::vector<double>& x_interp,
    double window_width
    )
{
  std::vector<double> interpolated_y(x_interp.size(), 0.0);


  for (size_t i = 0; i < x_interp.size(); ++i)
  {
    double x_target = x_interp[i];

    double window_sum = 0.0;
    for (size_t j = 0; j < x.size(); ++j)
    {
      //double sinc_value = sinc((x[j] - x_target) / (window_width / 2));
      double sinc_value = fsinc->Eval( (x[j] - x_target) / (window_width / 2) );

      interpolated_y[i] += y[j] * sinc_value;

      //window_sum += sinc( (x[j] - x_target) / (window_width / 2) );
      window_sum += fsinc->Eval( (x[j] - x_target) / (window_width / 2) );
    }

    /*
       double window_sum = 0.0;
       for (size_t j = 0; j < x.size(); ++j)
       {
       window_sum += sinc((x[j] - x_target) / (window_width / 2));
       }
       */

    interpolated_y[i] /= window_sum;
  }

  return interpolated_y;
}

// Perform windowed sinc interpolation
double SincInterpolate(TGraph *g, const double x_target, const double window_width)
{
  double window_sum = 0.;
  double interpolated_y = 0.;

  for (size_t j = 0; j < g->GetN(); ++j)
  {
    double x, y;
    g->GetPoint(j,x,y);
    double sinc_value = fsinc->Eval( (x - x_target) / (window_width / 2) );

    interpolated_y += y * sinc_value;

    window_sum += fsinc->Eval( (x - x_target) / (window_width / 2) );
  }

  interpolated_y /= window_sum;

  return interpolated_y;
}

std::vector<double> windowedSincInterpolation(TGraph *g, const std::vector<double>& x_interp, double window_width)
{
  std::vector<double> interpolated_y(x_interp.size(), 0.0);

  for (size_t i = 0; i < x_interp.size(); ++i)
  {

    interpolated_y[i] = SincInterpolate( g, x_interp[i], window_width);
    /*
    double x_target = x_interp[i];
    double window_sum = 0.0;

    for (size_t j = 0; j < g->GetN(); ++j)
    {
      double x, y;
      g->GetPoint(j,x,y);
      double sinc_value = fsinc->Eval( (x - x_target) / (window_width / 2) );

      interpolated_y[i] += y * sinc_value;

      window_sum += fsinc->Eval( (x - x_target) / (window_width / 2) );
    }

    interpolated_y[i] /= window_sum;
    */
  }

  return interpolated_y;
}


int sinc_interpolate()
{
  // Example usage
  const int NSAMPLES = 31;
  TF1 *gaussian = new TF1("gaussian","gaus",0,NSAMPLES-1);
  gaussian->SetParameters(100,14.4,2);

  TRandom3 rand3(0);

  std::vector<double> x;
  std::vector<double> y;
  for (double isamp=0.; isamp<NSAMPLES; isamp+=1.0)
  {
    x.push_back( isamp );
    y.push_back( gaussian->Eval(isamp) + rand3.Gaus(0,4) );
  }

  std::vector<double> x_interp;
  for (double ix=0.1; ix<NSAMPLES; ix+=0.1)
  {
    x_interp.push_back( ix );
  }

  double window_width = 3.0;
  fsinc = new TF1("fsinc",mysinc,0,NSAMPLES,2);
  fsinc->SetParameter(0,1);     // ampl
  fsinc->SetParameter(1,M_PI);  // period

  TGraph *g0 = new TGraph(x.size(),x.data(),y.data());

  //std::vector<double> interpolated_y = windowedSincInterpolation(x, y, x_interp, window_width);
  std::vector<double> interpolated_y = windowedSincInterpolation( g0, x_interp, window_width);

  /*
     for (size_t i = 0; i < interpolated_y.size(); ++i) {
     std::cout << "Interpolated y[" << i << "] = " << interpolated_y[i] << std::endl;
     }
     */

  TGraph *gint = new TGraph(x_interp.size(),x_interp.data(),interpolated_y.data());

  g0->SetMarkerStyle(20);
  g0->SetMinimum(-10);
  g0->Draw("ap");
  gint->SetMarkerStyle(20);
  gint->SetMarkerSize(0.6);
  gint->SetMarkerColor(2);
  gint->Draw("p");
  g0->Draw("p");
  gaussian->DrawCopy("same");

  return 0;
}

