all: libfilewrap.a libmemwrap.a

lib%.a : %.o
	ar -rc $@ $<
	ranlib $@

%.o : %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o *.a
