CXX       = clang++
CXXFLAGS  = -Wall -I.
LDFLAGS   = -fopenmp
PROGRAM   = omp_virus
SRCS      = omp_virus.cpp Random.cpp
OBJS      = $(SRCS:.cpp=.o)

.SUFFIXES: .cpp .o

.cpp.o: 
	$(CXX) -c $(CXXFLAGS) $<

all: $(PROGRAM) 

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $(SRCS) $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(PROGRAM)