#include <cstdio>
#include "Range.hpp"

r__IteratorStepOne::r__IteratorStepOne(int32_t v):n(v){}
int32_t r__IteratorStepOne::operator*() const{return n;}
r__IteratorStepOne r__IteratorStepOne::operator++()
{
    return ++n;
}
r__IteratorStepOne r__IteratorStepOne::operator++(int)
{
    return n++;
}
bool r__IteratorStepOne::operator==(const r__IteratorStepOne & other) const
{return (n == other.n);}
bool r__IteratorStepOne::operator!=(const r__IteratorStepOne & other) const
{return (n != other.n);}


r__RangeStepOne::r__RangeStepOne(int32_t start, int32_t stop):
m_start(start), m_stop(stop){}

r__IteratorStepOne r__RangeStepOne::begin() const
{return m_start;}
r__IteratorStepOne r__RangeStepOne::end() const
{return m_stop;}


r__IteratorStepVariable::r__IteratorStepVariable(int32_t v, int32_t s):n(v), step(s){}
int32_t r__IteratorStepVariable::operator*() const{return n;}
r__IteratorStepVariable r__IteratorStepVariable::operator++()
{
    n += step;
    return *this;
}
r__IteratorStepVariable r__IteratorStepVariable::operator++(int)
{
    r__IteratorStepVariable it = *this;
    n += step;
    return it;
}
bool r__IteratorStepVariable::operator==(const r__IteratorStepVariable & other) const
{return (n == other.n);}
bool r__IteratorStepVariable::operator!=(const r__IteratorStepVariable & other) const
{return (n != other.n);}


r__RangeStepVariable::r__RangeStepVariable(int32_t start, int32_t stop, int32_t step):
m_start(0), m_stop(0), m_step(0)
{
    if (step == 0 || (start < stop && step < 0) || (start > stop && step > 0) || start == stop)
        return;
    m_start = start;
    m_step = step;
    int32_t modstart = (step+(start%step))%step;
    int32_t modstop = (step+(stop%step))%step;
    int32_t divstart = start/step;
    int32_t divstop = stop/step;
    int mod = 0;
    if (step < 0)
    {
        if (modstart < 0 && (modstop < modstart || modstop == 0))
            mod++;
    }
    else
    {
        if (modstop>modstart && modstart>=0)
            mod++;
    }
    if (start < 0)
    {
        if (modstart < 0)
            mod--;
        else if (modstart > 0)
            mod++;
    }
    if (stop < 0)
    {
        if (modstop < 0)
            mod++;
        else if (modstop > 0)
            mod--;
    }
    m_stop = (divstop-divstart+mod)*step+start;
}

r__IteratorStepVariable r__RangeStepVariable::begin() const
{return r__IteratorStepVariable(m_start, m_step);}
r__IteratorStepVariable r__RangeStepVariable::end() const
{return r__IteratorStepVariable(m_stop, m_step);}

r__RangeStepOne range(int32_t stop)
{
    return r__RangeStepOne(0, stop);
}

r__RangeStepOne range(int32_t start, int32_t stop)
{
    return r__RangeStepOne(start, stop);
}

r__RangeStepVariable range(int32_t start, int32_t stop, int32_t step)
{
    return r__RangeStepVariable(start, stop, step);
}


