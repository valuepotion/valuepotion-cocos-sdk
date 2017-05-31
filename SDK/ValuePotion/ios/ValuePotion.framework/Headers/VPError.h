//
//  VPError.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ValuePotion/ValuePotionDefines.h>


NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, VPErrorType) {
    /** Unknown error. */
    VPErrorTypeUnknown = 0,
    /** Not initialized. */
    VPErrorTypeNotInitialized,
    /** No ad. */
    VPErrorTypeNoFill,
    /** Opened interstitial exists. */
    VPErrorTypeOpenedInterstitialExists,
    /** Cached interstitial exists. */
    VPErrorTypeCachedInterstitialExists,
    /** Cached interstitial is expired. */
    VPErrorTypeExpiredInterstitial,
    /** Interstitial is not support current orientation. */
    VPErrorTypeInvalidOrientation,
    /** Interstitial is blocked by user. (eg. Don't show today) */
    VPErrorTypeBlocked,
    /** Request is canceled by same placement reqeusts so quickly. */
    VPErrorTypeRequestTooSoon,
    /** Server error. */
    VPErrorTypeServerError,
    /** Wrong video request. */
    VPErrorTypeWrongVideoRequest,
    /** Empty interstitial. */
    VPErrorTypeEmptyInterstitial = VPErrorTypeNoFill,
};

OBJC_EXTERN NSString *const kVPErrorDomain;


@interface VPError : NSError

/**
 * 에러 타입에 맞는 에러 객체를 생성하여 리턴한다.
 */
+ (VPError *)errorWithType:(VPErrorType)errorType;

/**
 * VPErrorTypeServerError 타입의 에러를 생성하여 리턴한다.
 */
+ (VPError *)errorWithServerMessage:(NSString *)serverMessage;

@end

NS_ASSUME_NONNULL_END
