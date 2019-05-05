all: mainNotation

mainNotation: mainNotation.cpp
		g++ -o NotationConverter mainNotation.cpp



clean:
		rm mainNotation
