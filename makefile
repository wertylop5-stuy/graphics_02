OBJS = main.o draw.o output.o

all: $(OBJS)
	gcc -o lines $(OBJS)

main.o: main.c include/draw.h include/output.h
	gcc -c main.c include/draw.h include/output.h

draw.o: draw.c include/draw.h
	gcc -c draw.c include/draw.h

output.o: output.c include/output.h
	gcc -c output.c include/output.h

clean:
	rm -rf *.o lines

