SOURCE_FILES := STree.c STreeComp.c
HEADERS := STree.h STreeComp.h

build: main.c $(SOURCE_FILES) $(HEADERS)
		gcc -o tema2 main.c $(SOURCE_FILES) $(HEADERS)
run: build
	./tema2
clean:
	rm -rf tema2 rezultat_valgrind.txt
check:
	./checker.sh
	