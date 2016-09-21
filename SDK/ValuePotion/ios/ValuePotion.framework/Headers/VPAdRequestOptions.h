//
//  VPAdRequestOptions.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ValuePotion/ValuePotionDefines.h>


@class VPAdDimension;



@interface VPAdRequestOptions : NSObject

/**
 * The placement for an ad
 */
@property (nonatomic, copy, readonly, nonnull) NSString *placement;

/**
 * The dimension for an ad
 */
@property (nonatomic, strong, readonly, nonnull) VPAdDimension *dimension;

/**
 * The number of requesting items at same time. Default is 1.
 */
@property (nonatomic) NSInteger numberToRequest;

/**
 * When you receive some banner's responses, desides when you receive the callback.
 * If you want to receive it immediately, set this to YES, otherwise NO. Default is NO.
 *
 * Every request for ad has a main body and assets.
 * If this is YES, when callback method is called, one or more items of VPAdContainer contain only metadata and body data except other assets.
 * But do not worry. As all assets are received, a VPAdView can present the content fully.
 * If this is NO, when callback method is called, a VPAdView can present full content just right.
 */
@property (nonatomic) BOOL callbackBeforeCachingAssets;

/**
 * YES if you want to start rendering ad item immediately when callback received, otherwise NO. Default is NO.
 */
@property (nonatomic) BOOL startRenderingAtCallback;

+ (nonnull instancetype)optionsWithPlacement:(nonnull NSString *)placement dimension:(nonnull VPAdDimension *)dimension;

- (nonnull instancetype)initWithPlacement:(nonnull NSString *)placement dimension:(nonnull VPAdDimension *)dimension;

- (nonnull instancetype)init __unavailable;

@end
