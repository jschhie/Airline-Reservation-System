targets     := airline.out
objects     := main.o flight.o plane.o utilities.o

CC          := g++
CFLAGS      := -Wall
CFLAGS      += -g

# Enable verbose output if debugging
ifneq ($(V), 1)
Q = @
endif

all: $(targets)

airline.out: $(objects)
	@echo "G++		$@"
	$(Q) $(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	@echo "G++		$@"
	$(Q) $(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "CLEAN"
	$(Q) rm -f $(targets) $(objects)
