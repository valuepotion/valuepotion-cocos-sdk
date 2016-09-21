//
//  VPAdContainer.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ValuePotion/ValuePotionDefines.h>


@class VPAdDimension;
@class VPAdItem;


/**
 * The VPAdContainer is passed from '-[ValuePotion requestAdWithOptions:completion:]' delegate method.
 *
 * You must use the property 'items' and '-[VPAdContainer popAd]' exclusively.
 */
@interface VPAdContainer : NSObject

@property (nonatomic, strong, readonly, nonnull) NSString *placement;
@property (nonatomic, strong, readonly, nonnull) VPAdDimension *dimension;

/**
 * Pop ad item from the item queue. If container has no more ad, returns nil.
 */
- (nullable VPAdItem *)popAd;

/**
 * The array contains ad items.
 */
#ifdef AVAILABLE_SWIFT2_GENERIC
@property (nonatomic, readonly, nonnull) NSArray<VPAdItem *>* items;
#else
@property (nonatomic, readonly, nonnull) NSArray* items;
#endif

@end
