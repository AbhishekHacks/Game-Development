/**/
//header file
#include<SFML/Graphics.hpp>
using namespace sf;

//main function
int main(){

//lets define a window
VideoMode vm(1920,1080);

//create a window
RenderWindow window(vm,"Pong Game",Style::Fullscreen);

//view 
View view(FloatRect(0,0,1920,1080));
window.setView(view);

//create a rectangle
RectangleShape rect;
float X=500;
float Y=100;
rect.setSize(Vector2f(X,Y));
rect.setFillColor(Color::Red);
rect.setPosition(2000,540-Y/2);

//setting the speed of the rect
float speed = 0.0f;

//set the Clock
Clock clock;

//gaming loop
while(window.isOpen()){

//try to handle events
Event event;
while(window.pollEvent(event)){
if(event.type==Event::Closed){
window.close();
}
}

//if user press escape button than close the window
if(Keyboard::isKeyPressed(Keyboard::Escape)){
window.close();
}

Time dt = clock.restart();
if(rect.getPosition().x>-X){
srand((int)time(0));
speed = (rand()%200)+500;
rect.setPosition(rect.getPosition().x-(speed*dt.asSeconds()),rect.getPosition().y);
}
else{
rect.setPosition(2000,540-Y/2);
}

//if user press right move right or left than move left
if(Keyboard::isKeyPressed(Keyboard::Left)){
rect.move(-1.0f,0.0f);
}
if(Keyboard::isKeyPressed(Keyboard::Right)){
rect.move(1.0f,0.0f);
}

//clear the window
window.clear();

//draw the shapes on window
window.draw(rect);

//display the shapes
window.display();

}

return 0;
}
