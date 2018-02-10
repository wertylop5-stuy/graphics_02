OBJS = draw.o output.o main.o
OUTPUT = picture.ppm

all: $(OBJS)
	gcc -o lines $(OBJS)

main.o: main.c include/draw.h include/output.h
	gcc $(DBG) -c main.c include/draw.h include/output.h

draw.o: draw.c include/draw.h include/output.h include/dimen.h
	gcc $(DBG) -c draw.c include/draw.h include/output.h include/dimen.h

output.o: output.c include/output.h include/draw.h
	gcc $(DBG) -c output.c include/output.h include/draw.h

clean:
	rm -rf *.o $(OUTPUT)

