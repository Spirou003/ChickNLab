#ifndef NUMBERGENERATOR_HPP
#define NUMBERGENERATOR_HPP

#include <cstdint>

/**
 * @brief Générateur de nombres.
 *
 * Cette classe abstraite est utilisée afin d'utiliser un générateur de nombre, aléatoire ou non.
 */
class NumberGenerator
{
    public:
        NumberGenerator();
        ~NumberGenerator();

        /**
         * @brief Obtenir un entier quelconque.
         * @return Un entier quelconque.
         */
        virtual uint32_t NextInt() throw() = 0;
};

#endif
