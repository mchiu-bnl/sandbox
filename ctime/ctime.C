#include <ctime>

void ctime()
{
  time_t now{0};
  //sleep(2);
  time_t now2 = time(0); // Get the current time
  time_t tdiff = now2 - now;
  std::cout << tdiff << "\t" << now2 << std::endl; // Print the Unix timestamp
  return 0;
}
