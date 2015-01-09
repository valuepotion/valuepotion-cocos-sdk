//
//  ValuePotion.h
//  SDK
//  Version 1.0.6
//
//  Created by Gil on 10/3/13.
//  Copyright (c) 2013 ValuePotion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VPPurchase.h"
#import "VPReward.h"

@interface ValuePotion : NSObject

@property (nonatomic, assign) id delegate;
@property (nonatomic, copy) NSString *clientId;
@property (nonatomic, copy) NSString *secretKey;
@property (nonatomic, assign) BOOL test;

+ (ValuePotion *)sharedInstance;

- (void)initializeWithClientId:(NSString *)clientId secretKey:(NSString *)secretKey;

#pragma mark - Interstitial Methods
- (BOOL)hasCachedInterstitial:(NSString *)placement;
- (void)cacheInterstitial:(NSString *)placement;
- (void)openInterstitial:(NSString *)placement;

#pragma mark - Tracking Methods
- (void)trackEvent:(NSString *)eventName value:(NSNumber *)value;
- (void)trackEvent:(NSString *)eventName category:(NSString *)category label:(NSString *)label value:(NSNumber *)value;
- (void)trackPurchaseEvent:(NSString *)eventName revenueAmount:(double)revenueAmount currency:(NSString *)currency transactionId:(NSString *)transactionId productId:(NSString *)productId;
- (void)trackPurchaseEvent:(NSString *)eventName revenueAmount:(double)revenueAmount currency:(NSString *)currency transactionId:(NSString *)transactionId productId:(NSString *)productId campaignId:(NSString *)campaignId contentId:(NSString *)contentId;
- (void)trackPurchaseEvent:(NSString *)eventName category:(NSString *)category label:(NSString *)label revenueAmount:(double)revenueAmount currency:(NSString *)currency transactionId:(NSString *)transactionId productId:(NSString *)productId campaignId:(NSString *)campaignId contentId:(NSString *)contentId;
- (void)trackEvent:(NSString *)eventName values:(NSDictionary *)values __deprecated;
- (void)trackPurchaseEvent:(NSString *)eventName revenueAmount:(double)revenueAmount currency:(NSString *)currency __deprecated;
- (void)trackPurchaseEvent:(NSString *)eventName revenueAmount:(double)revenueAmount currency:(NSString *)currency transactionId:(NSString *)transactionId __deprecated;
- (void)trackPurchaseEvent:(NSString *)eventName revenueAmount:(double)revenueAmount currency:(NSString *)currency purchase:(VPPurchase *)purchase __deprecated;
- (void)trackPurchaseEvent:(NSString *)eventName revenueAmount:(double)revenueAmount currency:(NSString *)currency transactionId:(NSString *)transactionId purchase:(VPPurchase *)purchase __deprecated;

#pragma mark - Push Notification Methods
- (void)registerForPushNotification;
- (void)unregisterForPushNotification;
- (BOOL)isPushNotificationEnabled;
- (void)registerPushToken:(NSData *)token;
- (void)forwardPushInfo:(NSDictionary *)info;

#pragma mark - UserInfo Methods
- (NSDictionary *)userInfo;
- (void)setUserId:(NSString *)userId;
- (void)setUserServerId:(NSString *)serverId;
- (void)setUserBirth:(NSString *)birth;
- (void)setUserGender:(NSString *)gender;
- (void)setUserLevel:(double)level;
- (void)setUserFriends:(double)friends;
- (void)setUserAccountType:(NSString *)accountType;
- (void)setUserValue:(id)value forKey:(NSString *)key;
- (void)setUserInfo:(NSDictionary *)userInfo __deprecated;

@end


#pragma mark - Delegate Methods
@protocol ValuePotionDelegate <NSObject>
@optional
/**
 * interstitial을 성공적으로 캐싱한 경우 호출됨.
 */
- (void)didCacheInterstitial:(NSString *)placement;

/**
 * interstitial 캐싱 실패 시 호출됨.
 */
- (void)didFailToCacheInterstitial:(NSString *)placement error:(NSError *)error;

/**
 * interstitial 뷰가 열릴 때 호출됨.
 */
- (void)willOpenInterstitial:(NSString *)placement;
	
/**
 * interstitial 뷰를 여는데 실패한 경우 호출됨.
 */
- (void)didFailToOpenInterstitial:(NSString *)placement error:(NSError *)error;

/**
 * interstitial 뷰가 닫힐 때 호출됨.
 */
- (void)didCloseInterstitial:(NSString *)placement;

/**
 * interstitial 뷰애서 사용자가 링크를 선택할 때 호출됨.
 */
- (void)didRequestOpenURL:(NSString *)URL placement:(NSString *)placement;

/**
 * interstitial 뷰에서 사용자가 구매하기를 선택할 때 호출됨.
 */
- (void)didRequestPurchase:(VPPurchase *)purchase placement:(NSString *)placement;

/**
 * reward 캠페인의 interstitial 뷰가 화면에 나타날 때 호출됨.
 */
- (void)didRequestRewards:(NSArray *)rewards placement:(NSString *)placement;

/**
 * inplay 뷰에서 컨버전이 완료되었을 때 호출됨.
 */
- (void)didCompleteConversion:(NSString *)placement;

@end
