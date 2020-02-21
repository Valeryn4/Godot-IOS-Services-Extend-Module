IOS Services extend module
=====
This is the IOSServices module for Godot Engine 
- iOS
- purchaces
- request info
- [support promouting purchaces](https://developer.apple.com/app-store/promoting-in-app-purchases/) (deferred and now)
- [support request review](https://developer.apple.com/documentation/storekit/skstorereviewcontroller/2851536-requestreview)
- restire pyment
How to use
----------

Works the same as the standard singleton [InAppStore](https://docs.godotengine.org/ru/latest/tutorials/platform/services_for_ios.html#purchase)

Singletons
----------

### IAPExtend

**Methods:**
```gdscript
Error purchase(Variant p_params);
Error request_product_info(Variant p_params);
Error restore_purchases();
int get_pending_event_count(); #Returns the number of pending events on the queue.
Variant pop_pending_event(); #Pops the first event from the queue and returns it.
void finish_transaction(String product_id);
void set_auto_finish_transaction(bool b);
void set_auto_purchaces_from_store(bool b);
```

***examples:***
---------------

```gdsctipt

var in_app_store = Engine.get_singleton("IAPExtend")
in_app_store.set_auto_finish_transaction(true) #auto finished transactions
in_app_store.set_auto_purchaces_from_store(true) #auto purchacing transaction from store
in_app_store.finish_transaction("product_id") #finished transaction force

```

***sample***

```gdscript

var in_app_store = Engine.get_singleton("IAPExtend")

func on_purchase_pressed():
    var result = in_app_store.purchase( { "product_id": "my_product" } )
    if result == OK:
        animation.play("busy") # show the "waiting for response" animation
    else:
        show_error()

# put this on a 1 second timer or something
func check_events():
    while in_app_store.get_pending_event_count() > 0:
        var event = in_app_store.pop_pending_event()
        if event.type == "purchase":
            if event.result == "ok":
                show_success(event.product_id)
                in_app_store.finish_transaction(event.product_id) #ending transaction
            else:
                show_error()
                in_app_store.finish_transaction(event.product_id) #ending transaction
        elif event.type == "purchase_from_store" : #deferred transaction from store
            in_app_store.purchase( { "product_id": event.product_id } ) #continue transaction
```


***purchase***

```gdscript
var in_app_store = Engine.get_singleton("IAPExtend")
in_app_store.purchase({ "product_id": "my_product" })
```

responce
```json
{
  "type": "purchase",
  "result": "ok",
  "product_id": "the product id requested"
}
```
```gdscript

```

***request_product_info***

```gdscript

var in_app_store = Engine.get_singleton("IAPExtend")
var in_app_store.request_product_info({ "product_ids": ["my_product1", "my_product2"] })

```

responce
```
{
  "type": "product_info",
  "result": "ok",
  "invalid_ids": [ list of requested ids that were invalid ],
  "ids": [ list of ids that were valid ],
  "titles": [ list of valid product titles (corresponds with list of valid ids) ],
  "descriptions": [ list of valid product descriptions ] ,
  "prices": [ list of valid product prices ],
  "localized_prices": [ list of valid product localized prices ],
}
```


### SKExtend

**SKStoreReviewController.requestReview()**
An object that controls the process of requesting App Store ratings and reviews from users.

***example***
```gdscript
	
func request_review() :
	var store_kit = Engine.get_singleton("SKExtend")
	store_kit.request_review()
```

### iOS
- Drop the "iosservicesextend" directory inside the "modules" directory on the Godot source;

Configuring your game
---------------------

### iOS
Follow the [exporting to iOS official documentation](http://docs.godotengine.org/en/stable/learning/workflow/export/exporting_for_ios.html).



The following methods are available:
```python


License
-------------
MIT license
