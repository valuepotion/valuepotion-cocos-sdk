//
//  ValuePotionManager.mm
//  VPCocos
//
//  Created by Gil on 10/13/14.
//
//

#include "cocos2d.h"
#include "ValuePotionManager.h"
#import "ValuePotion.h"

@interface ValuePotionDelegateBridge : NSObject<ValuePotionDelegate>
@end

static ValuePotionDelegateBridge *sDelegateBridge = nil;
static ValuePotionManagerDelegate *sManagerDelegate = NULL;

#pragma mark - Helper Function
NSString* NSStringFromCString(const char *string) {
    if (string) {
        return [NSString stringWithUTF8String:string];
    } else {
        return nil;
    }
}

const char* CStringFromNSString(NSString *string) {
    if (string) {
        return [string cStringUsingEncoding:NSUTF8StringEncoding];
    } else {
        return "";
    }
}

#pragma mark - Initialize
void ValuePotionManager::initialize(const char *clientId, const char *secretKey)
{
    if (sDelegateBridge == NULL) {
        sDelegateBridge = [[ValuePotionDelegateBridge alloc] init];
        [[ValuePotion sharedInstance] setDelegate:sDelegateBridge];
    }
    [[ValuePotion sharedInstance] performSelector:@selector(setSdkType:) withObject:NSStringFromCString(SDK_TYPE)];
    [[ValuePotion sharedInstance] performSelector:@selector(setSdkVersion:) withObject:NSStringFromCString(SDK_VERSION)];
    [[ValuePotion sharedInstance] initializeWithClientId:NSStringFromCString(clientId) secretKey:NSStringFromCString(secretKey)];
}

void ValuePotionManager::setDelegate(ValuePotionManagerDelegate *delegate)
{
    sManagerDelegate = delegate;
}

void ValuePotionManager::setTest(bool isTest)
{
    [[ValuePotion sharedInstance] setTest:isTest];
}

#pragma mark - Interstitial
bool ValuePotionManager::hasCachedInterstitial(const char *placementString)
{
    NSString *placement = (placementString == NULL) ? nil : NSStringFromCString(placementString);
    return [[ValuePotion sharedInstance] hasCachedInterstitial:placement];
}

void ValuePotionManager::cacheInterstitial(const char *placementString)
{
    NSString *placement = (placementString == NULL) ? nil : NSStringFromCString(placementString);
    [[ValuePotion sharedInstance] cacheInterstitial:placement];
}

void ValuePotionManager::openInterstitial(const char *placementString)
{
    NSString *placement = (placementString == NULL) ? nil : NSStringFromCString(placementString);
    [[ValuePotion sharedInstance] openInterstitial:placement];
}

#pragma mark - Tracking
void ValuePotionManager::trackEvent(const char *eventName)
{
    [[ValuePotion sharedInstance] trackEvent:NSStringFromCString(eventName) value:nil];
}

void ValuePotionManager::trackEvent(const char *eventName, double eventValue)
{
    [[ValuePotion sharedInstance] trackEvent:NSStringFromCString(eventName) value:@(eventValue)];
}

void ValuePotionManager::trackEvent(const char *categroy, const char *eventName, const char *label, double eventValue)
{
    [[ValuePotion sharedInstance] trackEvent:NSStringFromCString(eventName)
                                    category:NSStringFromCString(categroy)
                                       label:NSStringFromCString(label)
                                       value:@(eventValue)];
}

void ValuePotionManager::trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId)
{
    [[ValuePotion sharedInstance] trackPurchaseEvent:NSStringFromCString(eventName)
                                       revenueAmount:revenueAmount
                                            currency:NSStringFromCString(currency)
                                       transactionId:NSStringFromCString(orderId)
                                           productId:NSStringFromCString(productId)];
}

void ValuePotionManager::trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId)
{
    [[ValuePotion sharedInstance] trackPurchaseEvent:NSStringFromCString(eventName)
                                       revenueAmount:revenueAmount
                                            currency:NSStringFromCString(currency)
                                       transactionId:NSStringFromCString(orderId)
                                           productId:NSStringFromCString(productId)
                                          campaignId:NSStringFromCString(campaignId)
                                           contentId:NSStringFromCString(contentId)];
}

#pragma mark - UserInfo
void ValuePotionManager::setUserId(const char *userId)
{
    [[ValuePotion sharedInstance] setUserId:NSStringFromCString(userId)];
}

void ValuePotionManager::setUserServerId(const char *serverId)
{
    [[ValuePotion sharedInstance] setUserServerId:NSStringFromCString(serverId)];
}

void ValuePotionManager::setUserBirth(const char *birth)
{
    [[ValuePotion sharedInstance] setUserBirth:NSStringFromCString(birth)];
}

void ValuePotionManager::setUserGender(const char *gender)
{
    [[ValuePotion sharedInstance] setUserGender:NSStringFromCString(gender)];
}

void ValuePotionManager::setUserLevel(double level)
{
    [[ValuePotion sharedInstance] setUserLevel:level];
}

void ValuePotionManager::setUserFriends(double friends)
{
    [[ValuePotion sharedInstance] setUserFriends:friends];
}

void ValuePotionManager::setUserAccountType(const char *accountType)
{
    [[ValuePotion sharedInstance] setUserAccountType:NSStringFromCString(accountType)];
}

@implementation ValuePotionDelegateBridge
- (void)didCacheInterstitial:(NSString *)placement
{
    if (sManagerDelegate) {
        sManagerDelegate->didCacheInterstitial([placement UTF8String]);
    }
}

- (void)didFailToCacheInterstitial:(NSString *)placement error:(NSError *)error
{
    if (sManagerDelegate) {
        sManagerDelegate->didFailToCacheInterstitial([placement UTF8String], [error.localizedDescription UTF8String]);
    }
}

- (void)willOpenInterstitial:(NSString *)placement
{
    if (sManagerDelegate) {
        sManagerDelegate->willOpenInterstitial([placement UTF8String]);
    }
}

- (void)didFailToOpenInterstitial:(NSString *)placement error:(NSError *)error
{
    if (sManagerDelegate) {
        sManagerDelegate->didFailToOpenInterstitial([placement UTF8String], [error.localizedDescription UTF8String]);
    }
}

- (void)didCloseInterstitial:(NSString *)placement
{
    if (sManagerDelegate) {
        sManagerDelegate->didCloseInterstitial([placement UTF8String]);
    }
}

- (void)didRequestOpenURL:(NSString *)URL placement:(NSString *)placement
{
    if (sManagerDelegate) {
        sManagerDelegate->didRequestOpenURL([placement UTF8String], [URL UTF8String]);
    }
}

- (void)didRequestPurchase:(VPPurchase *)purchase placement:(NSString *)placement
{
    if (sManagerDelegate) {
        sManagerDelegate->didRequestPurchase([placement UTF8String], [purchase.name UTF8String], [purchase.productId UTF8String], purchase.quantity, [purchase.campaignId UTF8String], [purchase.contentId UTF8String]);
    }
}

- (void)didRequestRewards:(NSArray *)rewards placement:(NSString *)placement
{
    if (sManagerDelegate) {
        std::vector<Reward> cppRewards;
        for (int i = 0; i < rewards.count; i++) {
            VPReward *reward = [rewards objectAtIndex:i];
            Reward r = {CStringFromNSString(reward.name), reward.quantity};
            cppRewards.push_back(r);
        }
        sManagerDelegate->didRequestRewards([placement UTF8String], cppRewards);
    }
}
@end