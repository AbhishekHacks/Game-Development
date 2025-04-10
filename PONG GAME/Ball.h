#include <SFML/Graphics.hpp>
#include <iostream>
#include<sstream>
using namespace sf;

class Ball{
    Vector2f m_Position; //2D vector with floating point coordinates
    CircleShape m_Shape; //Graphical representation of the ball
    float m_Speed = 300.0f; // speed of ball 300pxiels per seconds
    float m_DirectionX = 0.2f; //+ve because ball move horizontally left to right
    float m_DirectionY =0.2f; //+ve because ball move vertically top to bottom
  
  public:
     Ball(float startX, float startY);
     
     FloatRect getPosition();
     
     CircleShape getShape();
      
     void reboundSides(); //change the ball direction when it collide with diffrent surface 
     //called when it hit the left or right walls //change the horizontal direction.
    
     void reboundBatOrTop(); //changes the vertical direction ....decrease the y position
    
     void reboundBottom(); //game over and reset the ball position
     void update(Time dt); //ball update the position according to time
};

