//
//  VPAdView.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <ValuePotion/ValuePotionDefines.h>


@class VPAdItem;


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
- (nonnull instancetype)initWithAdItem:(nonnull VPAdItem *)adItem;

/**
 * Initialize the view with ad item.
 *
 * @param adItem an ad item gained from a VPAdContainer
 * @param closeBlock a code block is called when a user touches close button in banner.
 */
- (nonnull instancetype)initWithAdItem:(nonnull VPAdItem *)adItem closeBlock:(nonnull dispatch_block_t)closeBlock;

/**
 * Load ad item and set view up.
 *
 * @param adItem an ad item gained from a VPAdContainer
 */
- (void)loadAdItem:(nonnull VPAdItem *)adItem;

/**
 * Load ad item and set view up.
 *
 * @param adItem an ad item gained from a VPAdContainer
 * @param closeBlock a code block is called when a user touches close button in banner.
 */
- (void)loadAdItem:(nonnull VPAdItem *)adItem closeBlock:(nonnull dispatch_block_t)closeBlock;

@end
