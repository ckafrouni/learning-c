cc=clang
deps=general.c utils.c
runner=run.c
out=out.exe

$(out): $(runner) $(deps)
	$(cc) $^ -o $@

run:
	./$(out)

clean:
	del $(out)
