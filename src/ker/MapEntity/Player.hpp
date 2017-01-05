#ifndef CHICKNLAB_KER_MAPENTITY_PLAYER_HPP
#define CHICKNLAB_KER_MAPENTITY_PLAYER_HPP

#include "../MapEntity.hpp"

class Player: public MapEntity
{
    public:
        Player(double x, double y);
        Player(const Point2D<double> & position);
        virtual ~Player();

        virtual double GetSpeed() const;
        virtual Direction GetDirection() const;

        void SetSpeedX(double speedX);
        void SetSpeedY(double speedY);
        void SetSpeed(Point2D<double> speed);

    private:
        double m_speed;
        Direction m_direction;
};


#endif

