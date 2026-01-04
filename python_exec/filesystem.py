# filesystem operations

import errno
import os

def createdir(run_no):
  directory = str(run_no)
  try:
    os.mkdir(directory)
  except OSError as exc:  # Python >2.5
    if exc.errno == errno.EEXIST and os.path.isdir(directory):
      pass
    else:
      raise
  command = "mv *.txt " + str(run_no)
  os.system(command)


