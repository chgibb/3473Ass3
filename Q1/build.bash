#!/bin/bash
(set -o igncr) 2>/dev/null && set -o igncr; # For Cygwin on Windows compatibilit

g++ -std=c++11 -Werror -o q1 *.cpp -lpthread