
#include "SKExtend.h"

extern "C" {
#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
};

SKExtend *IAPExtend::instance = NULL;

void SKExtend::_bind_methods() {
	ClassDB::bind_method(D_METHOD("request_review"), &IAPExtend::request_review);
};

Error SKExtend::request_review() {
    if([SKStoreReviewController class]){
        [SKStoreReviewController requestReview] ;
    }
    return OK;
};

SKExtend::SKExtend() {
	ERR_FAIL_COND(instance != NULL);
	instance = this;
};


SKExtend::~SKExtend(){};