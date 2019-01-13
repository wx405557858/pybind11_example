CC = clang++
CFLAGS = -g -Wall -std=c++11 -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup `python3 -m pybind11 --includes` -I ./
SRCS = example.cpp
# PROG = find_marker
PROG = example`python3-config --extension-suffix`

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)


$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS) 
