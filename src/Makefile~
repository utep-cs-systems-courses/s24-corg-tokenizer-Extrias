OBJS= tokenizer.o uimain.o history.o

CFLAGS= -g -03


all: token

token: $(OBJS
	cc -o token $(CFLAGS) $(OBJS)

clean:
	rm -f *.o *.c~

run: token
	./token

