all: ozone.c
	gcc -o ozone ozone.c
clean:
	rm *~
	rm a.out
	rm ozone
run: all
	./ozone
