CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
OBJS = main.o Escape.o Position.o Pit.o Participant.o PartArray.o Hero.o Snorc.o random.o

escape: $(OBJS)
	$(CXX) $(CXXFLAGS) -o escape $(OBJS)

main.o: main.cc Escape.h PartArray.h
	$(CXX) $(CXXFLAGS) -c main.cc

Escape.o: Escape.cc Escape.h Pit.h Hero.h Snorc.h Participant.h PartArray.h defs.h
	$(CXX) $(CXXFLAGS) -c Escape.cc

Position.o: Position.cc Position.h defs.h
	$(CXX) $(CXXFLAGS) -c Position.cc

Pit.o: Pit.cc Pit.h Position.h PartArray.h Participant.h Hero.h defs.h
	$(CXX) $(CXXFLAGS) -c Pit.cc

Participant.o: Participant.cc Participant.h Position.h defs.h
	$(CXX) $(CXXFLAGS) -c Participant.cc

PartArray.o: PartArray.cc PartArray.h Participant.h defs.h
	$(CXX) $(CXXFLAGS) -c PartArray.cc

Hero.o: Hero.cc Hero.h Participant.h Pit.h Position.h defs.h
	$(CXX) $(CXXFLAGS) -c Hero.cc

Snorc.o: Snorc.cc Snorc.h Participant.h Pit.h Position.h defs.h
	$(CXX) $(CXXFLAGS) -c Snorc.cc

random.o: random.cc
	$(CXX) $(CXXFLAGS) -c random.cc

clean:
	rm -f $(OBJS) escape
