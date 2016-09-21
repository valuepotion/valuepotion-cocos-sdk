//
//  ValuePotionDefines.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#ifndef ValuePotionDefines_h
#define ValuePotionDefines_h


#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED

#ifndef __IPHONE_9_0
# define __IPHONE_9_0   90000
#endif

#ifndef __IPHONE_10_0
# define __IPHONE_10_0  100000
#endif

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_9_0
#   define AVAILABLE_SWIFT2_GENERIC
#endif

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
#   define AVAILABLE_SWIFT3_NAME
#   define VP_SWIFT_NAME(_x) NS_SWIFT_NAME(_x)
#   define VP_SWIFT_UNAVAILABLE(_x) NS_SWIFT_UNAVAILABLE(_x)
#   define VP_EXTENSIBLE_STRING_ENUM NS_EXTENSIBLE_STRING_ENUM
#else
#   ifndef VP_SWIFT_NAME
#       define VP_SWIFT_NAME(_x)
#   endif
#   ifndef VP_SWIFT_UNAVAILABLE
#       define VP_SWIFT_UNAVAILABLE(_x)
#   endif
#   ifndef VP_EXTENSIBLE_STRING_ENUM
#       define VP_EXTENSIBLE_STRING_ENUM
#   endif
#endif

#else  // __IPHONE_OS_VERSION_MAX_ALLOWED

#   ifndef VP_SWIFT_NAME
#       define VP_SWIFT_NAME(_x)
#   endif
#   ifndef VP_SWIFT_UNAVAILABLE
#       define VP_SWIFT_UNAVAILABLE(_x)
#   endif
#   ifndef VP_EXTENSIBLE_STRING_ENUM
#       define VP_EXTENSIBLE_STRING_ENUM
#   endif

#endif // __IPHONE_OS_VERSION_MAX_ALLOWED



#ifdef __TV_OS_VERSION_MAX_ALLOWED

#ifndef __TV_OS_VERSION_MAX_ALLOWED >= __TVOS_9_0
#   define __TVOS_PROHIBITED
#endif

#endif



typedef NS_ENUM(NSInteger, VPInterstitialBackgroundStyle) {
    VPInterstitialBackgroundBlackTranslucent = 0,
    VPInterstitialBackgroundLightTranslucent,
    VPInterstitialBackgroundBlackOpaque,
    VPInterstitialBackgroundLightOpaque,
};


@class NSError;
@class VPAdContainer;


typedef void (^VPAdRequestCallback)(VPAdContainer * __nullable container , NSError * __nullable error);


#endif /* ValuePotionDefines_h */
