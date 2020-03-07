#ifndef GODOT_IAPEXTEND_H
#define GODOT_IAPEXTEND_H

#include <version_generated.gen.h>

#include "reference.h"




class IAPExtend : public Reference {
    
#if VERSION_MAJOR == 3
    GDCLASS(IAPExtend, Reference);
#else
    OBJ_TYPE(IAPExtend, Reference);
#endif

    bool initialized;
    static IAPExtend *instance;
    
    
    List<Variant> pending_events;
    List<String> hide_promotion;
    List<String> position_promotion;

protected:
    static void _bind_methods();

public:
    Error request_product_info(Variant p_params);
    Error restore_purchases();
    Error purchase(Variant p_params);

    Error update_promoution_position(Variant p_array_id);
    Error hide_promotion(Variant p_array_id);


    int get_pending_event_count();
    Variant pop_pending_event();
    void finish_transaction(String product_id);
    void set_auto_finish_transaction(bool b);
    void set_auto_purchaces_from_store(bool b);

    void _post_event(Variant p_event);
    void _record_purchase(String product_id);

    bool _has_sort_promouting(String product_id);
    List<String>* _get_sort_promoutin_ptr();
    bool _has_hide_promouting(String product_id);
    
    static IAPExtend *get_singleton();
    
    IAPExtend();
    ~IAPExtend();
};

#endif
