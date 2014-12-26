#!/bin/bash

# Download the Columbia University printer status page, parse the results, and
# append to a file of aggregate printer status over time.
# 
# Requires that ninjas.c has been compiled into ninjas.out in the same
# directory as this script. Appends to a file named "ninjastats.txt" in the
# same directory as this script.
# 
# Micah Smith <micahjsmith@gmail.com>

SCRIPT_DIR=`dirname $0`
curl -s "http://www.columbia.edu/acis/facilities/printers/ninja_status.html" | sed 's/.*/"&"/' | xargs $SCRIPT_DIR/ninjas.out >> $SCRIPT_DIR/ninjastats.txt
