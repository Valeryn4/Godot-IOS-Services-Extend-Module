#include <version_generated.gen.h>

#if VERSION_MAJOR == 3
#include <core/class_db.h>
#include <core/engine.h>
#else
#include "object_type_db.h"
#include "core/globals.h"
#endif

#include "register_types.h"
#include "ios/src/IAPExtend.h"
#include "ios/src/SKExtend.h"

void register_iosservicesextend_types() {
#if VERSION_MAJOR == 3
    Engine::get_singleton()->add_singleton(Engine::Singleton("IAPExtend", memnew(IAPExtend)));
    Engine::get_singleton()->add_singleton(Engine::Singleton("SKExtend", memnew(SKExtend)));
#else
    Globals::get_singleton()->add_singleton(Globals::Singleton("IAPExtend", memnew(IAPExtend)));
    Globals::get_singleton()->add_singleton(Globals::Singleton("SKExtend", memnew(SKExtend)));
#endif
}

void unregister_iosservicesextend_types() {
}
