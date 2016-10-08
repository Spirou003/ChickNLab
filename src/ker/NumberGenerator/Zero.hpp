#ifndef NUMBERGENERATORRANDOM_HPP
#define NUMBERGENERATORRANDOM_HPP

#include "../NumberGenerator.hpp"

/**
 * @brief Générateur de nombres nuls.
 *
 * Une classe basique qui ne retoure que zéro.
 */
class Zero: public NumberGenerator
{
    public:
        /**
         * @brief Obtenir un entier quelconque.
         * @return Zéro.
         */
        uint32_t NextInt() throw();

        /**
         * @brief Obtenir l'instance de Zero.
         * @return L'instance de Zero.
         */
        static NumberGenerator * GetInstance();

    private:
        Zero();
        ~Zero();

        static Zero * instance;
};


#endif
