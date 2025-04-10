//adding a  bat at the bottom of window
#include<SFML/Graphics.hpp>
using namespace sf;

class Bat
{
   Vector2f m_Position; // 2d vector with floating point coordinate
   RectangleShape m_Shape; //graphical repersentation of the bat
   float m_speed = 600.0f; //control how fast the bats movs
   bool m_MovingLeft = false; //flags to track movement direction
   bool m_MovingRight = false;
   
   public:
   Bat(float startX,float startY);
   
   FloatRect getPosition();
   RectangleShape getShape();
   void moveLeft();
   void moveRight();
   void stopLeft();
   void stopRight();
   void update(Time dt); //moves the bat based on the time

 };
