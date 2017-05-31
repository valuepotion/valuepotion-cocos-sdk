//
//  VPAdDimension.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import <ValuePotion/ValuePotionDefines.h>


NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, VPAdDimensionType) {
    /** The default dimension type */
    VPAdDimensionTypeDefault __deprecated_msg("use VPAdDimensionTypeInterstitial") VP_SWIFT_UNAVAILABLE("use .interstitial") VP_SWIFT_NAME(default),
    /** The dimension type for interstitial ad */
    VPAdDimensionTypeInterstitial VP_SWIFT_NAME(interstitial),
    /** The dimension type for native banner */
    VPAdDimensionTypeNativeBanner VP_SWIFT_NAME(nativeBanner),
    /** The dimension type that has 320w x 50h */
    VPAdDimensionTypeBanner VP_SWIFT_NAME(banner),
    /** The dimension type that has 320w x 100h */
    VPAdDimensionTypeLargeBanner VP_SWIFT_NAME(largeBanner),
    /** The dimension type that has 300w x 250h */
    VPAdDimensionTypeMediumRectangle VP_SWIFT_NAME(mediumRectangle),
    /** The dimension type that has 728w x 90h */
    VPAdDimensionTypeLeaderboard VP_SWIFT_NAME(leaderboard),
    /** The dimension type that has 320w x 480h */
    VPAdDimensionTypeW320H480 VP_SWIFT_NAME(w320h480),
    /** The dimension type that has 320w x 50h */
    VPAdDimensionTypeW320H50 __deprecated_msg("use VpAdDimensionTypeBanner") VP_SWIFT_UNAVAILABLE("use .banner") VP_SWIFT_NAME(W320H50) = VPAdDimensionTypeBanner,
    /** The dimension type that has 320w x 100h */
    VPAdDimensionTypeW320H100 __deprecated_msg("use VpAdDimensionTypeLargeBanner") VP_SWIFT_UNAVAILABLE("use .largeBanner") VP_SWIFT_NAME(W320H100) = VPAdDimensionTypeLargeBanner,
    /** The dimension type that has 300w x 250h */
    VPAdDimensionTypeW300H250 __deprecated_msg("use VpAdDimensionTypeMediumRectangle") VP_SWIFT_UNAVAILABLE("use .mediumRectangle") VP_SWIFT_NAME(W320H250) = VPAdDimensionTypeMediumRectangle,
};


/**
 * The VPAdDimension contains width and height to reqeust ads.
 */
@interface VPAdDimension : NSObject

/**
 * The width of ad
 */
@property (nonatomic, readonly) NSInteger placementWidth;

/**
 * The height of ad
 */
@property (nonatomic, readonly) NSInteger placementHeight;

/**
 * The dimension that has 320w x 50h
 */
+ (instancetype)dimensionForBanner VP_SWIFT_NAME(banner());

/**
 * The dimension that has 320w x 100h
 */
+ (instancetype)dimensionForLargeBanner VP_SWIFT_NAME(largeBanner());

/**
 * The dimension that has 300w x 250h
 */
+ (instancetype)dimensionForMediumRectangle VP_SWIFT_NAME(mediumRectangle());

/**
 * This dimension is for native banner. It is 728w x 90h currently.
 */
+ (instancetype)dimensionForLeaderboard VP_SWIFT_NAME(leaderboard());

/**
 * This dimension is for interstitial ad. It is 320w x 480h currently.
 */
+ (instancetype)dimensionForInterstitial VP_SWIFT_NAME(interstitial());

/**
 * This dimension is for native banner. It is 320w x 100h currently.
 */
+ (instancetype)dimensionForNativeBanner VP_SWIFT_NAME(nativeBanner());

/**
 * The dimension that has 320w x 480h
 */
+ (instancetype)dimensionWith320x480 VP_SWIFT_NAME(fullscreen());

/**
 * A dimension that has any width and height.
 * @param width The banner width
 * @param height The banner height
 */
+ (instancetype)dimensionWithWidth:(NSInteger)width height:(NSInteger)height;

/**
 * Create dimension with VPAdDimensionType.
 */
+ (instancetype)dimensionWithType:(VPAdDimensionType)type;

/**
 * @return a CGSize structure with placementWidth and placementHeight
 */
- (CGSize)getSize;


- (instancetype)init __unavailable;


@end

@interface VPAdDimension (Deprecated)

/**
 * The default dimension. This dimension is for interstitial ad. It is 320w x 480h currently.
 */
+ (instancetype)defaultDimension __deprecated_msg("use +[VPAdDimension dimensionWith320x480]");

/**
 * The dimension that has 320w x 50h
 */
+ (instancetype)dimensionWith320x50 __deprecated_msg("use +[VPAdDimension dimensionForBanner]");

/**
 * The dimension that has 320w x 100h
 */
+ (instancetype)dimensionWith320x100 __deprecated_msg("use +[VPAdDimension dimensionForLargeBanner]");

/**
 * The dimension that has 300w x 250h
 */
+ (instancetype)dimensionWith300x250 __deprecated_msg("use +[VPAdDimension dimensionWithMediumRectangle]");

/**
 * The dimension that has 320w x 300h
 */
+ (instancetype)dimensionWith320x300 __deprecated_msg("use +[VPAdDimension dimensionWithMediumRectangle]");

@end


NS_ASSUME_NONNULL_END
