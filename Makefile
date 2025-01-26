all:
	g++ main.cc MyBox/MyBox.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -f app
