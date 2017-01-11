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

void Player::SetSpeed(double speed)
{
    m_speed = (speed >= 0 ? speed : m_speed);
}

void Player::SetDirection(Direction direction)
{
    m_direction = direction;
}
