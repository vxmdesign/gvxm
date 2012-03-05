SRCS := DslInterface.cpp NodeModule.cpp

OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(TARGET_OBJ) 

$(TARGET_OBJ): $(OBJS) y.tab.o lex.yy.o 
	ld -r -g -o $(TARGET_OBJ) $(OBJS) y.tab.o lex.yy.o

lex.yy.o: lex.yy.c
	g++ -g -c lex.yy.c -I../include/

y.tab.o: y.tab.c
	g++ -g -c y.tab.c -I../include/

lex.yy.c: vxm.l
	flex vxm.l

y.tab.c: vxm.y
	bison -y -d vxm.y

%.o: %.cpp
	g++ $(CFLAGS) -c $^

clean:
	rm -f *.o
	rm -f *~

