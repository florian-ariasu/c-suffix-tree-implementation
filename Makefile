SOURCE_FILES := stree.c stree_comp.c
HEADERS := stree.h stree_comp.h

build: main.c $(SOURCE_FILES) $(HEADERS)
		gcc -o stree main.c $(SOURCE_FILES) $(HEADERS)
run: build
	./stree
clean:
	rm -rf stree rezultat_valgrind.txt
check:
	./checker.sh