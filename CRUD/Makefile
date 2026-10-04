CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJS = main.o Category.o Date.o Reservation.o Rental.o HomeShare.o Tester.o

a1: $(OBJS)
	$(CXX) $(CXXFLAGS) -o a1 $(OBJS)

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

Category.o: Category.cc Category.h
	$(CXX) $(CXXFLAGS) -c Category.cc

Date.o: Date.cc Date.h
	$(CXX) $(CXXFLAGS) -c Date.cc

Reservation.o: Reservation.cc Reservation.h Date.h
	$(CXX) $(CXXFLAGS) -c Reservation.cc

Rental.o: Rental.cc Rental.h Reservation.h Category.h defs.h
	$(CXX) $(CXXFLAGS) -c Rental.cc

HomeShare.o: HomeShare.cc HomeShare.h Rental.h defs.h
	$(CXX) $(CXXFLAGS) -c HomeShare.cc

Tester.o: Tester.cc Tester.h
	$(CXX) $(CXXFLAGS) -c Tester.cc

clean:
	rm -f *.o a1
