
objects = View.o ProjectManager.o AssetStore.o ProjectArray.o Project.o AssetArray.o Asset.o Tester.o 

all: a2 a2test

a2: main.o $(objects) Control.o
	g++ -o  a2 main.o $(objects) Control.o

a2test: testmain.o $(objects) TestControl.o
	g++ -o a2test testmain.o $(objects) TestControl.o

testmain.o: testmain.cc
	g++ -c testmain.cc

main.o: main.cc
	g++ -c main.cc 

View.o: View.h View.cc 
	g++ -c View.cc

Control.o: Control.h Control.cc
	g++ -c Control.cc

TestControl.o: TestControl.h TestControl.cc 
	g++ -c TestControl.cc

ProjectManager.o: ProjectManager.h ProjectManager.cc 
	g++ -c ProjectManager.cc

AssetStore.o: AssetStore.h AssetStore.cc
	g++ -c AssetStore.cc

ProjectArray.o: ProjectArray.h ProjectArray.cc
	g++ -c ProjectArray.cc

Project.o: Project.cc Project.h
	g++ -c Project.cc

AssetArray.o: AssetArray.cc AssetArray.h
	g++ -c AssetArray.cc
	
Asset.o: Asset.cc Asset.h 
	g++ -c Asset.cc

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc

clean:
	rm -f a2 a2test *.o	