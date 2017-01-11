#ifndef CHICKNLAB_EXT_RANGE_HPP
#define CHICKNLAB_EXT_RANGE_HPP

#include <cstdint>

class r__IteratorStepOne
{
    public:
        r__IteratorStepOne(int32_t v);
        int32_t operator*() const;
        r__IteratorStepOne operator++();
        r__IteratorStepOne operator++(int);
        bool operator==(const r__IteratorStepOne & other) const;
        bool operator!=(const r__IteratorStepOne & other) const;

    private:
        int32_t n;
};

class r__IteratorStepVariable
{
    public:
        r__IteratorStepVariable(int32_t v, int s);
        int32_t operator*() const;
        r__IteratorStepVariable operator++();
        r__IteratorStepVariable operator++(int);
        bool operator==(const r__IteratorStepVariable & other) const;
        bool operator!=(const r__IteratorStepVariable & other) const;

    private:
        int32_t n;
        int32_t step;
};

class r__RangeStepOne
{
    public:
        r__RangeStepOne(int32_t start, int32_t stop);
        r__IteratorStepOne begin() const;
        r__IteratorStepOne end() const;
    private:
        int32_t m_start, m_stop;
};

class r__RangeStepVariable
{
    public:
        r__RangeStepVariable(int32_t start, int32_t stop, int32_t step);
        r__IteratorStepVariable begin() const;
        r__IteratorStepVariable end() const;
    private:
        int32_t m_start, m_stop, m_step;
};

r__RangeStepOne range(int32_t stop);
r__RangeStepOne range(int32_t start, int32_t stop);
r__RangeStepVariable range(int32_t start, int32_t stop, int32_t step);

#endif // UTILS_RANGE_HPP
