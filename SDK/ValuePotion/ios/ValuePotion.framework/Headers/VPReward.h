//
//  VPReward.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ValuePotion/ValuePotionDefines.h>


typedef NS_ENUM(NSInteger, VPRewardType) {
    VPRewardTypeNormal = 0,
    VPRewardTypeVideo,
};

/**
 * The VPReward is passed in '-[ValuePotion didRequestRewards:placement:]' as argument.
 */
@interface VPReward : NSObject

@property (nonatomic, assign, readonly) VPRewardType type;
@property (nonatomic, strong, readonly, nonnull) NSString *name;
@property (nonatomic, assign, readonly) NSInteger quantity;
@property (nonatomic, strong, readonly, nullable) NSString *campaignId;

@end
