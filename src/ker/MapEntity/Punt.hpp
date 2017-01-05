#ifndef CHICKNLAB_KER_MAPENTITY_PUNT_HPP
#define CHICKNLAB_KER_MAPENTITY_PUNT_HPP

#include "../MapEntity.hpp"

class Punt: public MapEntity
{
    public:
        Punt(double x, double y);
        Punt(const Point2D<double> & position);
        virtual ~Punt();

        virtual double GetSpeed() const;
        virtual Direction GetDirection() const;

        bool IsSuper() const;
        void SetSuper(bool super);

    private:
        bool m_super;
};


#endif
