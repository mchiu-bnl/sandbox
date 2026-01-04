
#include <iostream>
#include <cstdlib>
#include <numeric>

// Models a mathematical rational number
class SimpleRational
{
  int numerator;
  int denominator;

  public:
  // Initializes the components of a Rational object
  SimpleRational(int n, int d): numerator(n), denominator(d)
  {
    if (d == 0)
    {
      // Display error message
      std::cout << "Zero denominator error\n";
      exit(1);   // Exit the program
    }
  }

  // The default constructor makes a zero rational number
  // 0/1
  SimpleRational(): numerator(0), denominator(1) {}

  // Allows a client to reassign the numerator
  void set_numerator(int n) 
  {
    numerator = n;
  }

  // Allows a client to reassign the denominator.
  // Disallows an illegal fraction (zero denominator).
  void set_denominator(int d) 
  {
    if (d != 0)
    {
      denominator = d;
    }  
    else {
      // Display error message
      std::cout << "Zero denominator error\n";
      exit(1);   // Exit the program
    }

  }

  // Allows a client to see the numerator's value.
  int get_numerator()
  {
    return numerator;
  }

  // Allows a client to see the denominator's value.
  int get_denominator() 
  {
    return denominator;
  } 

  SimpleRational reduce()
  {
    int _gcd = std::gcd(numerator,denominator);

    return SimpleRational( numerator/_gcd, denominator/_gcd );
  }

};

// Returns the product of two rational numbers
SimpleRational multiply(SimpleRational  f1, SimpleRational f2)
{
  return {f1.get_numerator() * f2.get_numerator(),
    f1.get_denominator() * f2.get_denominator()};
}

void print_fraction(SimpleRational f)
{
  std::cout << f.get_numerator() << "/" << f.get_denominator() << std::endl;
}

//returns the rational number representing the sum of its two parameters. 
SimpleRational add(SimpleRational r1, SimpleRational r2)
{
  int r1num = r1.get_numerator();
  int r1den = r1.get_denominator();
  int r2num = r2.get_numerator();
  int r2den = r2.get_denominator();

  return { r2den*r1num + r1den*r2num, r1den*r2den };
}


void ch14_hw3()
{
  SimpleRational sr1(1,2);
  SimpleRational sr2(3,4);

  SimpleRational sr3 = add( sr1, sr2 );
  print_fraction( sr3 );

  SimpleRational sr4 = sr3.reduce();
  print_fraction( sr4 );

}

