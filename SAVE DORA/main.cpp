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


//Fish -- Nemo
Texture textureFish;
textureFish.loadFromFile("coverphoto.png");
Sprite spriteFish;
spriteFish.setTexture(textureFish);
spriteFish.setPosition(2892,680);
spriteFish.setScale(2.5f,2.5f);
spriteFish.setOrigin(spriteFish.getLocalBounds().width/2,spriteFish.getLocalBounds().height/2);


//Fish - Dory
Texture textureDory;
textureDory.loadFromFile("dory-removebg-preview.png");
Sprite spriteDory;
spriteDory.setTexture(textureDory);
spriteDory.setScale(2.0f,2.0f);
spriteDory.setPosition(-500,2160/2-500);


//Assists - Dory
Texture textureAssist1;
textureAssist1.loadFromFile("Blue_Thought_Cloud_Quote_Instagram_Post__5_-removebg-preview.png");
Sprite spriteAssist1;
spriteAssist1.setTexture(textureAssist1);
spriteAssist1.setScale(2.5f,2.5f);
spriteAssist1.setPosition(spriteDory.getPosition().x+spriteDory.getLocalBounds().width+1450,spriteDory.getPosition().y-500);

Texture textureAssist2;
textureAssist2.loadFromFile("Blue_Thought_Cloud_Quote_Instagram_Post__1_-removebg-preview (1).png");
Sprite spriteAssist2;
spriteAssist2.setTexture(textureAssist2);
spriteAssist2.setScale(2.5f,2.5f);
spriteAssist2.setPosition(spriteDory.getPosition().x+spriteDory.getLocalBounds().width+1450,spriteDory.getPosition().y-500);


//font-1
Font font1;
font1.loadFromFile("font/KOMIKAP_.ttf");
Text text1;
text1.setFont(font1);
text1.setString("Press Enter To Play");
text1.setCharacterSize(100);
text1.setFillColor(Color::White);
text1.setPosition(3856/4-150,1500);
text1.setScale(2.0f,2.0f);


//font-2
Font font2;
font2.loadFromFile("font/KOMIKAP_.ttf");
Text text2;
text2.setFont(font2);
text2.setString("Press Space Bar to Continue");
text2.setCharacterSize(100);
text2.setFillColor(Color::White);
text2.setPosition(3856/4-200,1800);
text2.setScale(1.5f,1.5f);


//font-3
Font font3;
font3.loadFromFile("font/KOMIKAP_.ttf");
Text text3;
text3.setFont(font3);
text3.setString("Press Enter to Start");
text3.setCharacterSize(100);
text3.setFillColor(Color::White);
text3.setPosition(3856/4,1800);
text3.setScale(1.5f,1.5f);


float fishSpeed = 350.0f;
float text1Speed = 4000.0f;
bool movingright=false;
bool movingupward=false;


Clock clock;
while(window.isOpen()){
Time dt = clock.restart();
if(!movingright&&!movingupward){
spriteFish.setPosition(spriteFish.getPosition().x-(dt.asSeconds()*fishSpeed),spriteFish.getPosition().y);
if(spriteFish.getPosition().x<=930){
movingright=true;
spriteFish.setScale(-2.5f,2.5f);
}
}
else if(movingright){
spriteFish.setPosition(spriteFish.getPosition().x+(dt.asSeconds()*fishSpeed),spriteFish.getPosition().y);
if(spriteFish.getPosition().x>=2892){
movingright=false;
spriteFish.setScale(2.5f,2.5f);
}
}
if(Keyboard::isKeyPressed(Keyboard::Return)){
fishSpeed=4000.0f;
movingupward=true;
}
if(movingupward){
movingright=false;
movingupward=true;
if(spriteFish.getPosition().y>=-300){
spriteFish.setPosition(spriteFish.getPosition().x,spriteFish.getPosition().y-(fishSpeed*dt.asSeconds()));
text1.setPosition(text1.getPosition().x,text1.getPosition().y+(fishSpeed*dt.asSeconds()));
}
else{
break;
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

bool assist1=false;
bool assist2=false;
bool dorymovingright=true;
bool position_x_dory=3856/2-1500;

while(window.isOpen()){
Time dt= clock.restart();
if(dorymovingright){
spriteDory.setPosition(spriteDory.getPosition().x+(3000*dt.asSeconds()),spriteDory.getPosition().y);
if(spriteDory.getPosition().x>=position_x_dory+spriteDory.getLocalBounds().width){
dorymovingright=false;
assist1=true;
}
}
Event event;
while(window.pollEvent(event)){
if(event.type==Event::Closed){
window.close();
}
}
if(Keyboard::isKeyPressed(Keyboard::Escape)){
window.close();
}
window.clear();
window.draw(spriteBackground);
window.draw(spriteDory);
if(assist1){
window.draw(spriteAssist1);
window.draw(text2);
if(Keyboard::isKeyPressed(Keyboard::Space)){
assist1=false;
assist2=true;
}
}
else if(assist2){
window.draw(spriteAssist2);
window.draw(text3);
}
window.display();
}
return 0;
}
