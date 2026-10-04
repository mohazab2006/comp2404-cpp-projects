CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

OBJECTS = main.o Control.o View.o Lab.o Entity.o LabWorkList.o LabWork.o LabTech.o Patient.o Tester.o
TESTOBJECTS = test.o TestControl.o View.o Lab.o Entity.o LabWorkList.o LabWork.o LabTech.o Patient.o Tester.o

all: a3 a3test

a3: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o a3 $(OBJECTS)

a3test: $(TESTOBJECTS)
	$(CXX) $(CXXFLAGS) -o a3test $(TESTOBJECTS)

main.o: main.cc Control.h
	$(CXX) $(CXXFLAGS) -c main.cc

test.o: test.cc TestControl.h
	$(CXX) $(CXXFLAGS) -c test.cc

Control.o: Control.cc Control.h Lab.h View.h Tester.h
	$(CXX) $(CXXFLAGS) -c Control.cc

TestControl.o: TestControl.cc TestControl.h Lab.h View.h Tester.h
	$(CXX) $(CXXFLAGS) -c TestControl.cc

View.o: View.cc View.h
	$(CXX) $(CXXFLAGS) -c View.cc

Lab.o: Lab.cc Lab.h Patient.h LabTech.h LabWork.h
	$(CXX) $(CXXFLAGS) -c Lab.cc

Entity.o: Entity.cc Entity.h
	$(CXX) $(CXXFLAGS) -c Entity.cc

LabWorkList.o: LabWorkList.cc LabWorkList.h LabWork.h
	$(CXX) $(CXXFLAGS) -c LabWorkList.cc

LabWork.o: LabWork.cc LabWork.h
	$(CXX) $(CXXFLAGS) -c LabWork.cc

LabTech.o: LabTech.cc LabTech.h Entity.h LabWorkList.h
	$(CXX) $(CXXFLAGS) -c LabTech.cc

Patient.o: Patient.cc Patient.h Entity.h LabWorkList.h
	$(CXX) $(CXXFLAGS) -c Patient.cc

Tester.o: Tester.cc Tester.h
	$(CXX) $(CXXFLAGS) -c Tester.cc

clean:
	rm -f a3 a3test *.o