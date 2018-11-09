compile:
	@gcc -c sigs.c
run: sigs.o
	@gcc sigs.o
	@./a.out
de: sigs.o
	@gcc sigs.o
	@gdb ./a.out
bug:
	@gcc -g sigs.o
clean: sigs.o
	@rm *.o ./a.out
