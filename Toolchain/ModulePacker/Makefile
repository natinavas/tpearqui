MP=mp.bin
SOURCES=$(wildcard *.c)

all: $(MP)

$(MP): $(SOURCES)
	gcc -largp $(SOURCES) -o $(MP)

clean:
	rm -rf $(MP)

.PHONY: all clean
