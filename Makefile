CC = gcc
LDFLAGS = -lm
TARGET = main
OBJFILES = main.o vec3.o color.o ray.o utils.o list.o sphere.o
DESTINATION = image.ppm
ERRORFILE = err.txt

all: $(TARGET)

$(TARGET): $(OBJFILES)
	echo "Linking and producing the final app"
	$(CC) $(CLFAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	echo "Cleaning all but final"
	rm $(OBJFILES)

fresh:
	echo "Cleaning all"
	-rm $(OBJFILES) $(TARGET) $(DESTINATION) $(ERRORFILE)


render: fresh all
	echo "Rendering..."
	./$(TARGET) 1> $(DESTINATION)

debug: fresh all
	echo "Debug..."
	./$(TARGET) 1> $(DESTINATION) 2> $(ERRORFILE) 

test:
	gcc -c a.c a.o
	gcc -c list.c list.o
	gcc -c utils.c utils.o
	gcc -c sphere.c sphere.o
	gcc -o a a.o list.o utils.o sphere.o -lm

clrtest:
	-rm a a.o list.o sphere.o utils.o