objects = main.o View.o Controller.o SummitStream.o Conference.o Talk.o Player.o Search.o
testobjects = test.o View.o TestControl.o Tester.o SummitStream.o Conference.o Talk.o Player.o Search.o

all: a4 a4test

a4: $(objects)
	g++ -o a4 $(objects)

main.o: main.cc List.h
	g++ -c main.cc 

a4test: $(testobjects)
	g++ -o a4test $(testobjects)

test.o: test.cc List.h
	g++ -c test.cc

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc

TestControl.o: TestControl.cc TestControl.h
	g++ -c TestControl.cc

View.o: View.h View.cc List.h
	g++ -c View.cc

Controller.o: Controller.h Controller.cc List.h
	g++ -c Controller.cc


SummitStream.o: SummitStream.h SummitStream.cc List.h
	g++ -c SummitStream.cc


Conference.o: Conference.cc Conference.h List.h
	g++ -c Conference.cc

Talk.o: Talk.cc Talk.h
	g++ -c Talk.cc
	
Player.o: Player.cc Player.h
	g++ -c Player.cc


Search.o: Search.cc Search.h
	g++ -c Search.cc

clean:
	rm -f a4 a4test *.o	