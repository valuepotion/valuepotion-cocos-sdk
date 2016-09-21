//
//  VPReward.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ValuePotion/ValuePotionDefines.h>


/**
 * The VPReward is passed in '-[ValuePotion didRequestRewards:placement:]' as argument.
 */
@interface VPReward : NSObject

@property (nonatomic, strong, readonly, nonnull) NSString *name;
@property (nonatomic, assign) NSInteger quantity;
@property (nonatomic, strong, readonly, nullable) NSString *campaignId;

@end
