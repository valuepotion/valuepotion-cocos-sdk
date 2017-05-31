//
//  VPAdItem.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//


#import <Foundation/Foundation.h>

#import <ValuePotion/ValuePotionDefines.h>


/**
 * The VPAdItem contains a information to show in VPAdView.
 */
@interface VPAdItem : NSObject {
@private
    id _internal;
}

@property (nonatomic, assign, readonly, getter=isVideoAd) BOOL videoAd VP_SWIFT_NAME(isVideoAd);

@end
