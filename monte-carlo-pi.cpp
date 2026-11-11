#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

const int TOTAL_POINTS = 1000000;

double random_fraction(unsigned int & seed);
double my_pi(int total_points, unsigned int & seed);

int main()
{
   // declaration section
   unsigned int seed = (unsigned int)time(0);

   // combined computation/output section
   cout << endl;
   cout << fixed << setprecision(6);
   cout << "my_pi = " << setw(10)
        << my_pi(TOTAL_POINTS, seed) << endl;
   cout << "M_PI  = " << setw(10) << M_PI << endl;
   cout << endl;

   return 0;
}

// function implementations
double random_fraction(unsigned int & seed)
{
   const double MODULUS_VALUE = 4294967296.0;
   const unsigned int MULTIPLIER_VALUE = 1664525;
   const unsigned int INCREMENT_VALUE = 1013904223;

   seed = MULTIPLIER_VALUE * seed + INCREMENT_VALUE;

   return seed / MODULUS_VALUE;
}

double my_pi(int total_points, unsigned int & seed)
{
   int i, points_inside_circle;
   double x, y, distance;

   points_inside_circle = 0;

   for (i = 1; i <= total_points; i++)
   {
      x = random_fraction(seed);
      y = random_fraction(seed);
      distance = sqrt(x * x + y * y);

      if (distance <= 1)
         points_inside_circle++;
   }

   return 4.0 * points_inside_circle / total_points;
}

/*
Sample output
-------------
my_pi =   3.143600
M_PI  =   3.141593
*/
