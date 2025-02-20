all:
	g++ -c MyBox/MyBox.cc -o MyBox.o
	g++ -c main.cc -o main.o
	g++ main.o MyBox.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -f app *.o
