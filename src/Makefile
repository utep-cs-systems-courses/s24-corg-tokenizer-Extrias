all: uimain

tokenizer.o : tokenizer.c
	cc -c tokenizer.c

uimain.o: uimain.c
	cc -c uimain.c

uimain: uimain.o tokenizer.o
	cc -o uimain tokenizer.o uimain.o

clean:
	rm -f *.o *.c~ uimain
