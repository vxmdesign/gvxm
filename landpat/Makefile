SRCS := ResChip.cpp BaseChip.cpp Pad.cpp PcbPad.cpp StdPackages.cpp SoicChip.cpp QfpChip.cpp RqfpChip.cpp DfnChip.cpp PatternDb.cpp UsbChip.cpp

OBJS := $(patsubst %.cpp,%.o,$(SRCS))

$(TARGET_OBJ): $(OBJS)
	ld -r -g -o $(TARGET_OBJ) $(OBJS)

%.o: %.cpp
	g++ $(CFLAGS) -c $^

clean:
	rm -f *.o
	rm -f *~
