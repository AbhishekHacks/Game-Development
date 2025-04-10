#include<SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include<sstream>
#include "Bat.cpp"
#include "Ball.cpp"
int main()
{
   VideoMode vm(1920,1080);
   RenderWindow window(vm,"pongGame");  //creating a window
 
   View view(FloatRect(0,0,1920,1080)); //we are set the value for calculation based on these
   window.setView(view);
Clock clock;
Bat bat(835,1000);
Ball ball(1920/2,0);

//game loop
  while(window.isOpen())
   {
     Event event;
     while(window.pollEvent(event))
     { 
        if(event.type== Event::Closed){
         window.close();
      }
     
       if(Keyboard::isKeyPressed(Keyboard:: Left))
          bat.moveLeft();
       else
        bat.stopLeft();
       
       if(Keyboard::isKeyPressed(Keyboard:: Right))
          bat.moveRight();
       else 
           bat.stopRight();
     }  
       Time dt =clock.restart();
     bat.update(dt);
     window.clear(Color::Black);
     window.draw(bat.getShape());
     window.draw(ball.getShape());
     window.display();
   }
 return 0;
}
