SRCS := MapNode.cpp LeafNode.cpp ListNode.cpp KeyValNode.cpp MapList.cpp SymbolTable.cpp StrQueue.cpp StringNode.cpp  VxmUtilities.cpp TreeUtilities.cpp CommandBase.cpp BaseTreeProc.cpp VxmTest.cpp



OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(TARGET_OBJ)

$(TARGET_OBJ): $(OBJS)
	ld -r -g -o $(TARGET_OBJ) $(OBJS)

%.o: %.cpp
	g++ $(CFLAGS) -c $^

clean:
	rm -f *.o
	rm -f *~

