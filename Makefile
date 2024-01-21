CC = gcc
LDFLAGS = -lm
TARGET = main
OBJFILES = main.o vec3.o color.o ray.o
DESTINATION = image.ppm

all: $(TARGET)

$(TARGET): $(OBJFILES)
	echo "Linking and producing the final app"
	$(CC) $(CLFAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	echo "Cleaning all but final"
	rm $(OBJFILES)

fresh:
	echo "Cleaning all"
	rm $(OBJFILES) $(TARGET) $(DESTINATION)

render: all
	echo "Rendering..."
	./$(TARGET) > $(DESTINATION) 