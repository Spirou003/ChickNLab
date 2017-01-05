#include "Punt.hpp"

Punt::Punt(double x, double y):
MapEntity(x, y){}

Punt::Punt(const Point2D<double> & position):
MapEntity(position){}

Punt::~Punt(){}

double Punt::GetSpeed() const
{
    return 0;
}

Direction Punt::GetDirection() const
{
    return None;
}

bool Punt::IsSuper() const
{
    return m_super;
}

void Punt::SetSuper(bool super)
{
    m_super = super;
}
