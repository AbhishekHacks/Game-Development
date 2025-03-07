#include <SFML/Graphics.hpp>
using namespace sf;

int main(){
	
	VideoMode vm(960, 540);                                      // OBJECT vm CREATED
	
	RenderWindow window(vm, "TIMBER MAN");						 // Add 3rd field <Style::Fullscreem> to open fullscreen by default
	
	View view(FloatRect(0,0,1920, 1080));                        // Claculates the coordinates according to the main resolution
	window.setView(view);                                        //(left, top, width, height)
	
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");   // creates texture background
	
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);              //pastes it on the bg like a sticker
	spriteBackground.setPosition(0,0);
	
	Texture textureTree;                                         //
	textureTree.loadFromFile("graphics/tree.png");               // adding tree onto bg
	Sprite spriteTree;                                           //
	spriteTree.setTexture(textureTree);                          //
	spriteTree.setPosition(810,0);                               //
	
	Texture textureBee;                                          //
	textureBee.loadFromFile("graphics/bee.png");                 // adding bee
	Sprite spriteBee;                                            //
	spriteBee.setTexture(textureBee);                            //
	spriteBee.setPosition(0,800);				     //

	bool beeActive=false;
	float beeSpeed=0.0f;
	
	Texture textureCloud;                                        //
	textureCloud.loadFromFile("graphics/cloud.png");             // cloud texture
	Sprite spriteCloud1, spriteCloud2, spriteCloud3;             // 3 cloud objects using same texture
	spriteCloud1.setTexture(textureCloud);                       //
	spriteCloud1.setPosition(0,0);                               //
	spriteCloud2.setTexture(textureCloud);                       //
	spriteCloud2.setScale(0.75, 0.75);
	spriteCloud2.setPosition(0,150);                             //
	spriteCloud3.setTexture(textureCloud);                       //
	spriteCloud3.setScale(0.89, 0.89);
	spriteCloud3.setPosition(0,300);                             //

	bool cloud1Active=false;
	float cloud1Speed=0.0f;


	bool cloud2Active=false;
	float cloud2Speed=0.0f;


	bool cloud3Active=false;
	float cloud3Speed=0.0f;

	bool stop = false;
	
	Clock clock; // clock is an object of class Clock

	RectangleShape timeBar; // timebar is an object of class RectangeShape
	float timeBarStartWidth=400;
	float timeBarHeight=80;
	timeBar.setSize(Vector2f(timeBarStartWidth,timeBarHeight)); //set the width and height of the timeBar
	timeBar.setFillColor(Color::Red); //set the color
	timeBar.setPosition(((1920/2)-200),980); //set the position of timeBar in window
	
	Time gameTimeTotal; // gameTimeTotal is an object of class Time
	float TimeRemaining = 6.0f; //game start at 6 seconds
	float timeBarWidthPerSecond = timeBarStartWidth/TimeRemaining; //every second the time bar reduces by timeBarWidthPerSecond pixels
	bool paused=true;
	int score=0;

	Text messageText;
	Text scoreText;
	
	Font font;
	font.loadFromFile("font/KOMIKAP_.ttf");
	
	messageText.setFont(font);
	scoreText.setFont(font);
	
	messageText.setString("Press Enter to start!!!");
	scoreText.setString("Score = 0");
	
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);
	
	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);
	
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0);
	messageText.setPosition(960,540);
	scoreText.setPosition(10,10);

	//Gaming Loop
	
	while(window.isOpen())
	{
	
		Event event;                                             //
		while(window.pollEvent(event))                           //
		{                                                        //
			if(event.type == Event::Closed)                      // ensures window stays open until close button pressed
			{                                                    //
				window.close();                                  //
			}                                                    //
		}                                                        //
		
		if(Keyboard::isKeyPressed(Keyboard::Escape))             //
		{                                                        // exits games on clicking escape
			window.close();                                      //
		}                                                        //

		Time dt = clock.restart();                               //dt is an object of class time

		if(!paused){
			TimeRemaining-=dt.asSeconds();
			timeBar.setSize(Vector2f(timeBarWidthPerSecond*TimeRemaining,timeBarHeight));

		if(TimeRemaining<=0.0f){
			paused=true;
		}
		}

		if(Keyboard::isKeyPressed(Keyboard::Return)||stop==true){
		stop=true;
		
		if(!beeActive){
			srand((int)time(0));				//srand for generating within a 'fraction of second'
			beeSpeed=(rand() %200)+200;			//rand for generating within a range
			float height = (rand() %500)+500;
			spriteBee.setPosition(2000,height);
			beeActive=true;
		}
		else{
			spriteBee.setPosition(spriteBee.getPosition().x-(beeSpeed*dt.asSeconds()),spriteBee.getPosition().y);
			if(spriteBee.getPosition().x<-100){
				beeActive=false;
			}
		}

		//Cloud 1

		if(!cloud1Active){
			srand((int)time(0));
			cloud1Speed=(rand() %120)+120;
			float height = (rand() %500)+500;
			spriteCloud1.setPosition(-100,0);
			cloud1Active=true;
		}
		else{
			spriteCloud1.setPosition(spriteCloud1.getPosition().x+(cloud1Speed*dt.asSeconds()),spriteCloud1.getPosition().y);
			if(spriteCloud1.getPosition().x>2000){
				cloud1Active=false;
			}
		}

		//Cloud 2
		
		if(!cloud2Active){
			srand((int)time(0));
			cloud2Speed=(rand() %110)+110;
			float height = (rand() %500)+500;
			spriteCloud2.setPosition(-100,150);
			cloud2Active=true;
		}
		else{
			spriteCloud2.setPosition(spriteCloud2.getPosition().x+(cloud2Speed*dt.asSeconds()),spriteCloud2.getPosition().y);
			if(spriteCloud2.getPosition().x>2000){
				cloud2Active=false;
			}
		}

		//Cloud 3
		
		if(!cloud3Active){
			srand((int)time(0));
			cloud3Speed=(rand() %100)+100;
			float height = (rand() %500)+500;
			spriteCloud3.setPosition(-100,300);
			cloud3Active=true;
		}
		else{
			spriteCloud3.setPosition(spriteCloud3.getPosition().x+(cloud3Speed*dt.asSeconds()),spriteCloud3.getPosition().y);
			if(spriteCloud3.getPosition().x>2000){
				cloud3Active=false;
			}
		    }
		}
		
		window.clear();                                          //
	    	window.draw(spriteBackground);                           // Draws bg
	    	window.draw(spriteCloud1);                               //
	    	window.draw(spriteCloud2);                               // Draws Clouds
	    	window.draw(spriteCloud3);                               //
	    	window.draw(spriteTree);                                 // Draws tree
	    	window.draw(spriteBee);                                  // Draws bee
		window.draw(timeBar);
		window.draw(scoreText);
		window.draw(messageText);
		window.display();                                        //display
	}
	
	return 0;	
	
}
