
CXXFLAGS=`wx-config --cxxflags`

all: whitesheep

whitesheep: src/app.o src/taskbar.o
	$(CXX) src/app.o src/taskbar.o `wx-config --libs` -o whitesheep

clean:
	-rm src/*.o whitesheep

