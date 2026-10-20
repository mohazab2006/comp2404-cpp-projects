CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
TARGET = a2
OBJS = Control.o Date.o Msg.o MsgArray.o Subscriber.o Telco.o Time.o View.o main.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

Control.o: Control.cc Control.h Telco.h Subscriber.h MsgArray.h Msg.h Date.h Time.h View.h defs.h
	$(CXX) $(CXXFLAGS) -c Control.cc -o Control.o

Date.o: Date.cc Date.h defs.h
	$(CXX) $(CXXFLAGS) -c Date.cc -o Date.o

Msg.o: Msg.cc Msg.h Date.h Time.h defs.h
	$(CXX) $(CXXFLAGS) -c Msg.cc -o Msg.o

MsgArray.o: MsgArray.cc MsgArray.h Msg.h Date.h Time.h defs.h
	$(CXX) $(CXXFLAGS) -c MsgArray.cc -o MsgArray.o

Subscriber.o: Subscriber.cc Subscriber.h MsgArray.h Msg.h Date.h Time.h defs.h
	$(CXX) $(CXXFLAGS) -c Subscriber.cc -o Subscriber.o

Telco.o: Telco.cc Telco.h Subscriber.h MsgArray.h Msg.h Date.h Time.h defs.h
	$(CXX) $(CXXFLAGS) -c Telco.cc -o Telco.o

Time.o: Time.cc Time.h defs.h
	$(CXX) $(CXXFLAGS) -c Time.cc -o Time.o

View.o: View.cc View.h defs.h
	$(CXX) $(CXXFLAGS) -c View.cc -o View.o

main.o: main.cc Control.h Telco.h Subscriber.h MsgArray.h Msg.h Date.h Time.h View.h defs.h
	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
