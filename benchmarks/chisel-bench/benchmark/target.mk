all: lib

lib:
	make -C $(CHISEL_BENCHMARK_HOME)/benchmark/lib

reduce: lib
	cp $(SRC).origin.c $(SRC)
	$(CC) -w $(SRC) -o $(ORIGIN_BIN) $(CFLAGS) $(LFLAGS)
	timeout 10800 /chisel_ProbDD/build/bin/chisel --save_temp --skip_local_dep --skip_global_dep --skip_dce ./$(ORACLE) $(SRC)
	cp $(SRC).chisel.c $(SRC).reduced.c

clean:
	rm -f $(NAME).origin $(NAME).reduced $(NAME).c

distclean: clean
	rm -rf chisel-out
