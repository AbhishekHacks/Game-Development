//header file
#include<SFML/Graphics.hpp>
using namespace sf;

//main function
int main(){

//define a gaming window
VideoMode vm(1920,1080);

//create a gaming window
RenderWindow window(vm,"FISH CATCHER",Style::Fullscreen);

//set the view 
View view(FloatRect(0,0,1920,1080));
window.setView(view);

//Gaming loop
while(window.isOpen()){

//handle events
Event event;
while(window.pollEvent(event)){
if(event.type==Event::Closed){
window.close();
}
}

//if user presses Escape the window closes
if(Keyboard::isKeyPressed(Keyboard::Escape)){
window.close();
}

//clear the previous frame effects
window.clear();

//finally display your gaming window
window.display();
}

return 0;
}
