#include <signal.h>
#include <iostream>

using namespace std;

void termination_handler (int signum)
{
  cout << "good bye" << endl;
  exit(1);
}

int main (void)
{
  struct sigaction new_action, old_action;

  /* Set up the structure to specify the new action. */
  new_action.sa_handler = termination_handler;
  sigemptyset (&new_action.sa_mask);
  new_action.sa_flags = 0;

  sigaction (SIGTERM, NULL, &old_action);
  if (old_action.sa_handler != SIG_IGN)
    sigaction (SIGTERM, &new_action, NULL);

  while ( true )
    {
      cout << "hello" << endl;
      sleep(10);
    }

  return 1;
}

