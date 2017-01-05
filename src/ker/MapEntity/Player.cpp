#include "Player.hpp"

Player::Player(double x, double y):
MapEntity(x, y), m_speed(0), m_direction(None){}

Player::Player(const Point2D<double> & position):
MapEntity(position), m_speed(0), m_direction(None){}

Player::~Player(){}

double Player::GetSpeed() const
{
    return m_speed;
}

Direction Player::GetDirection() const
{
    return m_direction;
}

void Player::SetSpeedX(double vx)
{
    ;
}

void Player::SetSpeedY(double vy)
{

}

void Player::SetSpeed(Point2D<double> v)
{
    ;
}
