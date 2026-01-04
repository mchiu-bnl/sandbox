#!/usr/bin/env python3

import argparse

# set up command line parser
parser = argparse.ArgumentParser()
parser.add_argument('runtype', nargs='?', default='noise')

args = parser.parse_args()
#print(args.runtype)

if ( args.runtype == 'noise' ):
    print("Taking a noise run")
elif ( args.runtype == 'xtalk' ):
    print("Taking a xtalk run")
else:
    print(f"Error, '{args.runtype}' is an unknown run type, must specify 'noise' or 'xtalk'")
    exit(1)


