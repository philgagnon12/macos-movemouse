SRC=src
BUILD=build
BIN=${BUILD}/bin
INCLUDE=include

CC=xcrun -sdk macosx cc

MOVEMOUSE_MAX_DISPLAYS:=64

${BIN}/movemouse: ${SRC}/movemouse.c | ${BIN}
	$(CC) $^ -o $@ -framework CoreGraphics -DMOVEMOUSE_MAX_DISPLAYS=${MOVEMOUSE_MAX_DISPLAYS}

${BUILD}:
	mkdir ${BUILD}

${BIN}: | ${BUILD}
	mkdir ${BIN}

clean:
	rm -rf ${BUILD}/*
