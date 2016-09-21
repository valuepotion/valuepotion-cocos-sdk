//
//  VPError.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <ValuePotion/ValuePotionDefines.h>


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
    /** Empty interstitial. */
    VPErrorTypeEmptyInterstitial = VPErrorTypeNoFill,
};

OBJC_EXTERN NSString *const __nonnull kVPErrorDomain;
