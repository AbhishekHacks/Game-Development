#include<SFML/Graphics.hpp>
using namespace sf;

class Ball{
	Vector2f m_Position;
	CircleShape m_Shape;
	float m_Speed=900.0f;
	float m_DirectionX=0.2f;
	float m_DirectionY=0.2f;
	
public:
	Ball(float startX,float startY);
	FloatRect getPosition();
	CircleShape getShape();
	void reboundSides(); //when thwball hit left or right side wall
	void reboundBatorTop(); //when the ball hit the bat or the top
	void reboundBottom(); //when the ball hit the bottom
	void update(Time dt);
};
