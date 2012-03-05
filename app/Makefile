SRCS := $(shell ls *.cpp)

OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(TARGET_OBJ)

$(TARGET_OBJ): $(OBJS)
	ld -r -g -o $(TARGET_OBJ) $(OBJS)

%.o: %.cpp
	g++ $(CFLAGS) -c $^

clean:
	rm -f *.o
	rm -f *~

