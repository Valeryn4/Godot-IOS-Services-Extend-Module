
#include "SKExtend.h"

extern "C" {
#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
};

SKExtend *SKExtend::instance = NULL;

void SKExtend::_bind_methods() {
	ClassDB::bind_method(D_METHOD("request_review"), &SKExtend::request_review);
};

Error SKExtend::request_review() {
    if([SKStoreReviewController class]){
        [SKStoreReviewController requestReview] ;
    }
    return OK;
};

SKExtend *SKExtend::get_singleton() {
    
    return instance;
};

SKExtend::SKExtend() {
	ERR_FAIL_COND(instance != NULL);
	instance = this;
};


SKExtend::~SKExtend(){};
