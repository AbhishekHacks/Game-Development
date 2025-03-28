//header files
#include<SFML/Graphics.hpp>
#include "Bat.cpp"
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
	Bat bat(960,1060); 
	
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

		//clear the window
		window.clear();

		//draw shapes
		window.draw(bat.getShape());
	
		//finally display the window
		window.display();
	}

	return 0;
}
