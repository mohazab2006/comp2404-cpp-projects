CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
TARGET = a3
OBJS = main.o Control.o View.o Time.o Date.o Subscriber.o SubArray.o \
       Msg.o ExternMsg.o InternMsg.o MsgList.o Telco.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cc defs.h Control.h
	$(CXX) $(CXXFLAGS) -c main.cc
Control.o: Control.cc Control.h Telco.h View.h
	$(CXX) $(CXXFLAGS) -c Control.cc
View.o: View.cc View.h defs.h
	$(CXX) $(CXXFLAGS) -c View.cc
Time.o: Time.cc Time.h defs.h
	$(CXX) $(CXXFLAGS) -c Time.cc
Date.o: Date.cc Date.h defs.h
	$(CXX) $(CXXFLAGS) -c Date.cc
Subscriber.o: Subscriber.cc Subscriber.h defs.h
	$(CXX) $(CXXFLAGS) -c Subscriber.cc
SubArray.o: SubArray.cc SubArray.h Subscriber.h
	$(CXX) $(CXXFLAGS) -c SubArray.cc
Msg.o: Msg.cc Msg.h Date.h Time.h
	$(CXX) $(CXXFLAGS) -c Msg.cc
ExternMsg.o: ExternMsg.cc ExternMsg.h Msg.h
	$(CXX) $(CXXFLAGS) -c ExternMsg.cc
InternMsg.o: InternMsg.cc InternMsg.h Subscriber.h Msg.h
	$(CXX) $(CXXFLAGS) -c InternMsg.cc
MsgList.o: MsgList.cc MsgList.h Msg.h
	$(CXX) $(CXXFLAGS) -c MsgList.cc
Telco.o: Telco.cc Telco.h InternMsg.h ExternMsg.h SubArray.h MsgList.h
	$(CXX) $(CXXFLAGS) -c Telco.cc

clean:
	rm -f $(OBJS) $(TARGET)
