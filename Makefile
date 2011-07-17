
CXXFLAGS=$(shell wx-config --cxxflags) -arch i386
LIBS=$(shell wx-config --libs)


all: whitesheep

whitesheep: src/app.o src/taskbar.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	-rm src/*.o whitesheep

