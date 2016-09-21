//
//  VPPurchase.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ValuePotion/ValuePotionDefines.h>


/**
 * The VPPurchase is passed from '-[ValuePotion didRequestPurchase:placement:]' delegate method.
 *
 * @see http://developers.valuepotion.com/en/sdk_ios/advanced.html
 */
@interface VPPurchase : NSObject

@property (nonatomic, copy, readonly, nonnull) NSString *name;
@property (nonatomic, copy, readonly, nonnull) NSString *productId;
@property (nonatomic, assign) NSInteger quantity;
@property (nonatomic, copy, readonly, nullable) NSString *campaignId;
@property (nonatomic, copy, readonly, nullable) NSString *contentId;

@end
