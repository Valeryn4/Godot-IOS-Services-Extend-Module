#ifndef GODOT_SKEXTEND_H
#define GODOT_SKEXTEND_H

#include <version_generated.gen.h>

#include "reference.h"


class SKExtend : public Reference {
    
#if VERSION_MAJOR == 3
    GDCLASS(SKExtend, Reference);
#else
    OBJ_TYPE(SKExtend, Reference);
#endif

    bool initialized;
    SKExtend *instance;

protected:
    static void _bind_methods();

public:
    Error request_review();
    

    SKExtend();
    ~SKExtend();
};




#endif