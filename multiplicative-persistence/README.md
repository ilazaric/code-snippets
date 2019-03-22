# Setup
Install GMP (C++ multiple precision library).  
`sudo apt-get install libgmp-dev`  

# Compiling
`g++ -std=c++14 -Ofast -march=native search.cpp -o search -lpthread -lgmpxx -lgmp`  
