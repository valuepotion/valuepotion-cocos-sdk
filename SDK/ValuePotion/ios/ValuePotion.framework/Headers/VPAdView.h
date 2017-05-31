//
//  VPAdView.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <ValuePotion/ValuePotionDefines.h>


@class VPAdItem;
@class VPAdView;


NS_ASSUME_NONNULL_BEGIN


typedef NS_OPTIONS(NSInteger, VPAdViewVideoPlayerLayout) {
    VPAdViewVideoPlayerLayoutTitleLeft              = 1,
    VPAdViewVideoPlayerLayoutTitleRight             = 2,
    VPAdViewVideoPlayerLayoutTitleCenter            = 3,

    VPAdViewVideoPlayerLayoutProgressRound          = 1 << 4,
    VPAdViewVideoPlayerLayoutProgressTotal          = 2 << 4,
    VPAdViewVideoPlayerLayoutProgressRemained       = 3 << 4,
    VPAdViewVideoPlayerLayoutProgressUnderbar       = 4 << 4,

    VPAdViewVideoPlayerLayoutRound __deprecated_msg("use VPAdViewVideoPlayerLayoutProgressRound") = VPAdViewVideoPlayerLayoutProgressRound,
    VPAdViewVideoPlayerLayoutTotal __deprecated_msg("use VPAdViewVideoPlayerLayoutProgressTotal") = VPAdViewVideoPlayerLayoutProgressTotal,
    VPAdViewVideoPlayerLayoutRemained __deprecated_msg("use VPAdViewVideoPlayerLayoutProgressRemained") = VPAdViewVideoPlayerLayoutProgressRemained,
    VPAdViewVideoPlayerLayoutUnderbar __deprecated_msg("use VPAdViewVideoPlayerLayoutProgressUnderbar") = VPAdViewVideoPlayerLayoutProgressUnderbar,
};


@protocol VPAdViewDelegate <NSObject>

@optional

- (void)adViewWillStartLoading:(VPAdView *)adView;
- (void)adViewDidLoaded:(VPAdView *)adView;
- (void)adViewDidLoadingFailed:(VPAdView *)adView;

- (BOOL)adView:(VPAdView *)adView shouldPlayVideoViaWifi:(BOOL)isWifi atFirst:(BOOL)atFirst;
- (void)adView:(VPAdView *)adView withAdItem:(nullable VPAdItem *)adItem willDisplayContentWithSize:(CGSize)size;

@end


/**
 * The VPAdView is a view contains a banner with VPAdItem.
 */
@interface VPAdView : UIView {
@private
    id _internal;
}

/**
 * Initialize the view with ad item.
 *
 * @param adItem an ad item gained from a VPAdContainer
 */
- (instancetype)initWithAdItem:(VPAdItem *)adItem;

/**
 * Initialize the view with ad item.
 *
 * @param adItem an ad item gained from a VPAdContainer
 * @param closeBlock a code block is called when a user touches close button in banner.
 */
- (instancetype)initWithAdItem:(VPAdItem *)adItem closeBlock:(dispatch_block_t)closeBlock VP_SWIFT_NAME(init(adItem:close:));

/**
 * Load ad item and set view up.
 *
 * @param adItem an ad item gained from a VPAdContainer
 */
- (void)loadAdItem:(VPAdItem *)adItem VP_SWIFT_NAME(load(_:));

/**
 * Load ad item and set view up.
 *
 * @param adItem an ad item gained from a VPAdContainer
 * @param closeBlock a code block is called when a user touches close button in banner.
 */
- (void)loadAdItem:(VPAdItem *)adItem closeBlock:(dispatch_block_t)closeBlock VP_SWIFT_NAME(load(_:close:));

/**
 * Add another VPAdView to display a companion ad.
 *
 * @param companionAdView another VPAdView to display a companion ad.
 */
- (void)addCompanionAdView:(VPAdView *)companionAdView width:(NSInteger)width height:(NSInteger)height VP_SWIFT_NAME(add(companion:width:height:));


@property (nonatomic, weak) id<VPAdViewDelegate> adViewDelegate;

@property (nonatomic, assign) BOOL huggingContentVertically;

@property (nonatomic, assign, readonly, getter=isCompanionAdView) BOOL companionAdView VP_SWIFT_NAME(isCompanionAdView);


+ (void)setVideoPlayerLayout:(VPAdViewVideoPlayerLayout)layout VP_SWIFT_NAME(set(videoPlayerLayout:));

+ (VPAdViewVideoPlayerLayout)getVideoPlayerLayout;

+ (void)registerCustomBundle:(NSBundle *)customBundle;


@end


NS_ASSUME_NONNULL_END
