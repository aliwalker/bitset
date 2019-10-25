#ifndef BITSET_HPP
#define BITSET_HPP

#include <assert.h>
#include <cstdlib>

class Bitset
{
private:
    /// Store the bits as an array of uint32_t.
    /// A single int can be marked 32 times.
    uint32_t *intvals;

    /// Length of [intvals].
    size_t intvalCount;

public:
    Bitset(size_t numbits)
    {
        this->intvalCount = (numbits >> 5) + (numbits % 32 ? 1 : 0);
        this->intvals = new uint32_t[intvalCount];

        for (int i = 0; i < intvalCount; i++)
        {
            intvals[i] = 0;
        }
    }

    virtual ~Bitset()
    {
        intvalCount = 0;
        delete[] intvals;
    }

    /// Number of bits.
    size_t length() const
    {
        return intvalCount << 5;
    }

    /// Mark a number as seen.
    void add(size_t idx)
    {
        // Index to elem within intvals.
        int intIdx = idx >> 5;

        // The low bits serve as offset.
        int offset = idx & 31;

        // Mark as seen.
        intvals[intIdx] |= (1 << offset);
    }

    /// Whether a number is seen.
    bool has(size_t idx)
    {
        // Index into [intvals].
        int intIdx = idx >> 5;

        // The low bits serve as offset.
        int offset = idx & 31;

        return (intvals[intIdx] >> offset) & 1;
    }

    /// Merge.
    void merge(const Bitset &that)
    {
        assert(this->intvalCount == that.intvalCount);

        for (int i = 0; i < intvalCount; i++)
            this->intvals[i] |= that.intvals[i];
    }
};

#endif