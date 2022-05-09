cc=clang
deps=vectors.c
runner=run.c
out=run.exe

$(out):  $(runner) $(deps)
	$(cc) $^ -o $@

run:
	./$(out)

clean:
	-del $(out)