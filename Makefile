CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = quadris
OBJECTS = main.o cell.o block.o grid.o level.o level5.o level4.o level0.o level1.o level2.o level3.o textdisplay.o graphicsdisplay.o command.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX}-5 ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	 rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
