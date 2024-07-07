// Princess.h

#ifndef PRINCESS_H
#define PRINCESS_H

#include <iostream>
#include <string>

namespace Fantasy {

    //#include "FrogPrince.h"
    class FrogPrince;

    class Princess {
        friend std::ostream& operator<<(std::ostream& os, const Princess& rhs);
    public:
        Princess(const std::string& name);
        void marries(FrogPrince& betrothed);
        const std::string& getName() const;

    private:
        std::string name;
        FrogPrince* spouse;
    };

}
    
#endif
