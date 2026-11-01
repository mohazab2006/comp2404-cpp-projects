CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o Date.o Account.o Customer.o Transaction.o Bank.o
TARGET = a1

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cc defs.h Bank.h
	$(CXX) $(CXXFLAGS) -c main.cc

Date.o: Date.cc Date.h defs.h
	$(CXX) $(CXXFLAGS) -c Date.cc

Account.o: Account.cc Account.h defs.h
	$(CXX) $(CXXFLAGS) -c Account.cc

Customer.o: Customer.cc Customer.h Account.h defs.h
	$(CXX) $(CXXFLAGS) -c Customer.cc

Transaction.o: Transaction.cc Transaction.h Date.h Account.h defs.h
	$(CXX) $(CXXFLAGS) -c Transaction.cc

Bank.o: Bank.cc Bank.h Customer.h Transaction.h Account.h Date.h defs.h
	$(CXX) $(CXXFLAGS) -c Bank.cc

clean:
	rm -f $(OBJS) $(TARGET)
