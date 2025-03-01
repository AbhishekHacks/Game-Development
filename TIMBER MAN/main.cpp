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
	spriteBee.setPosition(0,800);                                //
	
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
		
		window.clear();                                          //
	    window.draw(spriteBackground);                           // Draws bg
	    window.draw(spriteCloud1);                               //
	    window.draw(spriteCloud2);                               // Draws Clouds
	    window.draw(spriteCloud3);                               //
	    window.draw(spriteTree);                                 // Draws tree
	    window.draw(spriteBee);                                  // Draws bee
		window.display();                                        //
	}
	
	return 0;	
	
}
