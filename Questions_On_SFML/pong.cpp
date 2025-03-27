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

//creating five circle shapes
CircleShape circle[5];
for(int i=0;i<5;i++){
circle[i].setRadius(50);
if(i==4){
circle[i].setFillColor(Color::Red);
}
else{
circle[i].setFillColor(Color::Green);
}
}

//1st circle
circle[0].setPosition(0,10);

//2nd circle
circle[1].setPosition(1800,10);

//3rd circle
circle[2].setPosition(0,980);

//4th circle
circle[3].setPosition(1800,980);

//5th Circle
circle[4].setPosition(880,490);

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

//clear the window
window.clear();

//draw the shapes on window
for(int i=0;i<5;i++){
window.draw(circle[i]);
}

//display the shapes
window.display();

}

return 0;
}
