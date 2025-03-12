#include<SFML/Graphics.hpp>
using namespace sf;
int main(){


VideoMode vm(3856,2160);
RenderWindow window(vm,"Fishing Game",Style::Fullscreen);
View view(FloatRect(0,0,3856,2160));
window.setView(view);


//background
Texture textureBackground;
textureBackground.loadFromFile("graphics/underwaterplant.jpg");
Sprite spriteBackground;
spriteBackground.setTexture(textureBackground);
spriteBackground.setPosition(0,0);


//Fish
Texture textureFish;
textureFish.loadFromFile("graphics/fish-picaai-Photoroom.png");
Sprite spriteFish;
spriteFish.setTexture(textureFish);
FloatRect bounds = spriteFish.getLocalBounds();
float width = bounds.width;
spriteFish.setPosition(0,2160/2-350);



while(window.isOpen()){
if(Keyboard::isKeyPressed(Keyboard::Escape)){
window.close();
}
Event event;
while(window.pollEvent(event)){
if(event.type==Event::Closed){
window.close();
}
}
window.clear();
window.draw(spriteBackground);
window.draw(spriteFish);
window.display();
}
}
