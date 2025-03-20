#include<SFML/Graphics.hpp>
using namespace sf;

void updateBranches(int seed);
const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];
enum class side
{
LEFT,
RIGHT,
NONE
};
side branchPositions[NUM_BRANCHES];


int main(){
VideoMode vm(1920, 1080);   //VideoMode ---> class
RenderWindow window(vm,"TIMBER MAN GAME", Style::Fullscreen);   //RenderWindow ---> class

View view(FloatRect(0,0,1920,1080));
window.setView(view);

//Background
Texture textureBackground;
textureBackground.loadFromFile("graphics/background.png");
Sprite spriteBackground;
spriteBackground.setTexture(textureBackground);
spriteBackground.setPosition(0,0); 

//Tree
Texture textureTree;
textureTree.loadFromFile("graphics/tree.png");
Sprite spriteTree;
spriteTree.setTexture(textureTree);
spriteTree.setPosition(810,0); 

//Branches
Texture textureBranch;
textureBranch.loadFromFile("graphics/branch.png");
for(int i=0;i<NUM_BRANCHES;i++){
branches[i].setTexture(textureBranch);
branches[i].setPosition(1110,200);
branches[i].setOrigin(0,0);
}

//Bee
Texture textureBee;
textureBee.loadFromFile("graphics/bee.png");
Sprite spriteBee;
spriteBee.setTexture(textureBee);
spriteBee.setPosition(0, 800); 

bool beeActive=false;
float beeSpeed=0.0f;


//Clouds
Texture textureCloud;
textureCloud.loadFromFile("graphics/cloud.png");
Sprite spriteCloud1, spriteCloud2, spriteCloud3;
spriteCloud1.setTexture(textureCloud);
spriteCloud2.setTexture(textureCloud);
spriteCloud3.setTexture(textureCloud);
spriteCloud1.setPosition(0,0); 
spriteCloud2.setPosition(0,150); 
spriteCloud2.setScale(0.5,0.5);
spriteCloud3.setPosition(0,300); 

bool cloud1Active=false;
float cloud1Speed=0.0f;

bool cloud2Active=false;
float cloud2Speed=0.0f;

bool cloud3Active=false;
float cloud3Speed=0.0f;

//Timber Man
Texture textureman;
textureman.loadFromFile("graphics/player.png");
Sprite spriteman;
spriteman.setTexture(textureman);
spriteman.setPosition(580,720);

side playerSide = side::LEFT;

//Axe
Texture textureaxe;
textureaxe.loadFromFile("graphics/axe.png");
Sprite spriteaxe;
spriteaxe.setTexture(textureaxe);
spriteaxe.setPosition(700,830);

const float AXE_POSITION_LEFT = 700;
const float AXE_POSITION_RIGHT = 1075;

//log
Texture texturelog;
texturelog.loadFromFile("graphics/log.png");
Sprite spritelog;
spritelog.setTexture(texturelog);
spritelog.setPosition(810,720);

bool logActive = false;
float logspeedX=1000;
float logspeedY=-1500;
bool acceptInput=false;

//Gravestone
Texture texturerip;
texturerip.loadFromFile("graphics/rip.png");
Sprite spriterip;
spriterip.setTexture(texturerip);
spriterip.setPosition(600,860);



                          
Clock clock;


//---timeBar code ---
RectangleShape timeBar;     //timeBar---> Object
float timeBarStartWidth=400;
float timeBarHeight=80;
timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
timeBar.setFillColor(Color::Red);
timeBar.setPosition((1920/2)-200, 980);

//---starting timer, showing remianing time---
Time gameTimeTotal;
float timeRemaining=6.0f;
float timeBarWidthPerSecond= timeBarStartWidth/timeRemaining;

bool paused=true;
int score=0;

Text messageText;
Text scoreText;

Font font;       // font ---> Object 
font.loadFromFile("font/KOMIKAP_.ttf");
//setting font
messageText.setFont(font);
scoreText.setFont(font);
//setting text
messageText.setString("Press Enter to start!!");  //setString---> function inside text class
scoreText.setString("Score=0");
//setting size 
messageText.setCharacterSize(75);
scoreText.setCharacterSize(50);
//setting color
messageText.setFillColor(Color::White);
scoreText.setFillColor(Color::White);

FloatRect textRect=messageText.getLocalBounds();
messageText.setOrigin(textRect.left+textRect.width/2.0f, textRect.top+textRect.height/2.0f);
messageText.setPosition(960, 540);
scoreText.setPosition(10,10);

//---gaming loop section---
while(window.isOpen()){

Event event;
while(window.pollEvent(event)){
if(event.type==Event::KeyReleased&&!paused){
acceptInput=true;
spriteaxe.setPosition(2000,spriteaxe.getPosition().y);
}
}

Event event1;
while(window.pollEvent(event1)){
if(event1.type==Event::Closed){
window.close();
}
}

if(Keyboard::isKeyPressed(Keyboard::Escape)){    //KeyPressed ---> Function
window.close();
}
if(Keyboard::isKeyPressed(Keyboard::Return)){
paused=false;
score=0;
timeRemaining=5;
}

if(acceptInput){
if(Keyboard::isKeyPressed(Keyboard::Right)){
playerSide = side::RIGHT;
score++;
spriteaxe.setPosition(AXE_POSITION_RIGHT,spriteaxe.getPosition().y);
spriteman.setPosition(1200,720);
spritelog.setPosition(810,720);
logspeedX=-5000;
logActive=true;
acceptInput=false;
}
if(Keyboard::isKeyPressed(Keyboard::Left)){
playerSide = side::LEFT;
score++;
spriteaxe.setPosition(AXE_POSITION_LEFT,spriteaxe.getPosition().y);
spriteman.setPosition(580,720);
spritelog.setPosition(810,720);
logspeedX=5000;
logActive=true;
acceptInput=false;
}
}

Time dt=clock.restart();    //dt is an object of class "Time"

if(!paused){
timeRemaining-=dt.asSeconds();  //timeremaining--->6 
timeBar.setSize(Vector2f(timeBarWidthPerSecond*timeRemaining, timeBarHeight));
//if this game is running on 60fps, frame time =1/60=0.016=dt.asSecond. TimeRemaining=6=>6-0.016=5.99. timebar/remainingtime=400/6=66.6.
//Whenever we press enter, width 400 is reduced to 66.6*5.99=398.5	
if (timeRemaining<=0.0f){
messageText.setString("GAME OVER!");
messageText.setCharacterSize(75);
FloatRect textRect=messageText.getLocalBounds();
messageText.setOrigin(textRect.left+textRect.width/2.0f, textRect.top+textRect.height/2.0f);
messageText.setPosition(960, 540);
paused=true;
}


//---for bee---
if(!beeActive){
srand((int)time(0));             //srand for generating within a 'fraction of second'
beeSpeed=(rand() % 200)+200;     //rand for generating within a 'range'
float height=(rand() % 500)+500;
spriteBee.setPosition(2000,height);
beeActive=true;
}
else{
spriteBee.setPosition(spriteBee.getPosition().x-(beeSpeed*dt.asSeconds()), spriteBee.getPosition().y);
if(spriteBee.getPosition().x<-100){
beeActive=false;
}
}

//---for cloud 1---
if(!cloud1Active){
srand((int)time(0));             
cloud1Speed=(rand() % 80)+80;    
float height=(rand() % 500)+500;
spriteCloud1.setPosition(-100,0);
cloud1Active=true;
}
else{
spriteCloud1.setPosition(spriteCloud1.getPosition().x+(cloud1Speed*dt.asSeconds()), spriteCloud1.getPosition().y);
if(spriteCloud1.getPosition().x>2000){
cloud1Active=false;
}
}

//---for cloud 2---
if(!cloud2Active){
srand((int)time(0));             
cloud2Speed=(rand() % 50)+50;    
float height=(rand() % 500)+500;
spriteCloud2.setPosition(-100,150);
cloud2Active=true;
}
else{
spriteCloud2.setPosition(spriteCloud2.getPosition().x+(cloud2Speed*dt.asSeconds()), spriteCloud2.getPosition().y);
if(spriteCloud2.getPosition().x>2000){
cloud2Active=false;
}
}

//---for cloud 3---
if(!cloud3Active){
srand((int)time(0));             
cloud3Speed=(rand() % 110)+110;    
float height=(rand() % 500)+500;
spriteCloud3.setPosition(-100,300);
cloud3Active=true;
}
else{
spriteCloud3.setPosition(spriteCloud3.getPosition().x+(cloud3Speed*dt.asSeconds()), spriteCloud3.getPosition().y);
if(spriteCloud3.getPosition().x>2000){
cloud3Active=false;
}
}

updateBranches(1);
updateBranches(2);
updateBranches(3);
updateBranches(4);
updateBranches(5);

//placed branch in the game
for(int i=0;i<NUM_BRANCHES;i++){
float height = i*150;

if(branchPositions[i] == side::LEFT){
branches[i].setPosition(610,height);
branches[i].setOrigin(220,40);
branches[i].setRotation(180);
}
else if(branchPositions[i] == side::RIGHT){
branches[i].setPosition(1330,height);
branches[i].setOrigin(220,40);
branches[i].setRotation(0);
}
else{
branches[i].setPosition(3000,height);
}
}
}



window.clear();

window.draw(spriteBackground);
window.draw(spriteCloud1);
window.draw(spriteCloud2);
window.draw(spriteCloud3);
for(int i=0;i<NUM_BRANCHES;i++){
window.draw(branches[i]);
}
window.draw(spriteTree);
window.draw(spriteman);
window.draw(spriteaxe);
window.draw(spriterip);
window.draw(spriteBee);
window.draw(spritelog);
window.draw(timeBar);
if(paused){
window.draw(messageText);
}
window.draw(scoreText);
window.display();
}
return 0;
}

void updateBranches(int seed){
for(int j=NUM_BRANCHES-1;j>0;j--){
branchPositions[j] = branchPositions[j-1];
}
srand((int)time(0)+seed);
int r = (rand()%5);
switch(r){
case 0: branchPositions[0] = side::LEFT;
	break;
case 1: branchPositions[0] = side::RIGHT;
	break;
default:branchPositions[0] = side::NONE;
}
}
