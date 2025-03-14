#include<SFML/Graphics.hpp>
using namespace sf;
int main(){


VideoMode vm(3856,2160);
RenderWindow window(vm,"Fishing Game",Style::Fullscreen);
View view(FloatRect(0,0,3856,2160));
window.setView(view);


//background
Texture textureBackground;
textureBackground.loadFromFile("graphics1/underwaterplant.jpg");
Sprite spriteBackground;
spriteBackground.setTexture(textureBackground);
spriteBackground.setPosition(0,0);


//Fish
Texture textureFish;
textureFish.loadFromFile("coverphoto.png");
Sprite spriteFish;
spriteFish.setTexture(textureFish);
spriteFish.setPosition(2892,680);
spriteFish.setScale(2.5f,2.5f);
spriteFish.setOrigin(spriteFish.getLocalBounds().width/2,spriteFish.getLocalBounds().height/2);


//font
Font font1;
font1.loadFromFile("font/KOMIKAP_.ttf");
Text text1;
text1.setFont(font1);
text1.setString("Press Enter To Play");
text1.setCharacterSize(100);
text1.setFillColor(Color::White);
text1.setPosition(3856/4-150,1500);
text1.setScale(2.0f,2.0f);


float fishSpeed = 200.0f;
bool movingright=false;


Clock clock;
while(window.isOpen()){
Time dt = clock.restart();
if(!movingright){
spriteFish.setPosition(spriteFish.getPosition().x-(dt.asSeconds()*fishSpeed),spriteFish.getPosition().y);
if(spriteFish.getPosition().x<=930){
movingright=true;
spriteFish.setScale(-2.5f,2.5f);
}
}
else{
spriteFish.setPosition(spriteFish.getPosition().x+(dt.asSeconds()*fishSpeed),spriteFish.getPosition().y);
if(spriteFish.getPosition().x>=2892){
movingright=false;
spriteFish.setScale(2.5f,2.5f);
}
}
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
window.draw(text1);
window.display();
}
}
