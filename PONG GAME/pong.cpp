//header files
#include<SFML/Graphics.hpp>
#include<sstream>
#include "Bat.cpp"
#include "Ball.cpp"
using namespace sf;

//main function
int main(){

	//define a window
	VideoMode vm(1920,1080);

	//create a window
	RenderWindow window(vm,"PONG GAME",Style::Fullscreen);

	//view 
	View view(FloatRect(0,0,1920,1080));
	window.setView(view);
	
	//draw a bat
	Bat bat(960,1000); 
	
	//ball object
	Ball ball(950,10);
	
	//Text objext
	int score=0;
	int lives=3;
	
	Text hud;
	Font font;
	font.loadFromFile("font/KOMIKAP_.ttf");
	hud.setFont(font);
	hud.setCharacterSize(50);
	hud.setFillColor(Color::White);
	hud.setPosition(0,0);
	
	Clock clock; //Clock class

	//Gaming loop
	while(window.isOpen()){

		//handle events
		Event event;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed){
				window.close();
			}
		}

		//if user press Escape than close the window
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}
		
		//if user press right key go right
		if(Keyboard::isKeyPressed(Keyboard::Right)){
			bat.moveRight();
		}
		else{
			bat.stopRight();
		}
		
		//if user press left go left
		if(Keyboard::isKeyPressed(Keyboard::Left)){
			bat.moveLeft();
		}
		else{
			bat.stopLeft();
		}
		
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);
		std::stringstream ss;
		ss<<"Score:"<<score<<std::endl<<"Lives:"<<lives;
		hud.setString(ss.str());

		//clear the window
		window.clear();

		//draw shapes
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.draw(hud);
	
		//finally display the window
		window.display();
	}

	return 0;
}
