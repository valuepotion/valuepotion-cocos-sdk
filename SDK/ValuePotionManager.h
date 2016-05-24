//
//  ValuePotionManager.h
//  VPCocos
//  Version 1.0.9
//
//  Created by Gil on 10/13/14.
//  Copyright (c) 2013 ValuePotion. All rights reserved.
//

#ifndef ValuePotionManager_h
#define ValuePotionManager_h

#include "cocos2d.h"
#include <vector>

static const char *SDK_TYPE = "Cocos";
static const char *SDK_VERSION = "1.0.9";

struct Reward
{
    const char *name;
    int quantity;
};

class ValuePotionManagerDelegate {
public:
    virtual ~ValuePotionManagerDelegate() {}
    virtual void didCacheInterstitial(const char *placement) {}
    virtual void didFailToCacheInterstitial(const char *placement, const char *errorMessage) {}
    virtual void willOpenInterstitial(const char *placement) {}
    virtual void didFailToOpenInterstitial(const char *placement, const char *errorMessage) {}
    virtual void didCloseInterstitial(const char *placement) {}
    virtual void didRequestOpenURL(const char *placement, const char *URL) {}
    virtual void didRequestPurchase(const char *placement, const char *name, const char *productId, int quantity, const char *campaignId, const char *contentId) {}
    virtual void didRequestRewards(const char *placement, std::vector<Reward> rewards) {}
    virtual void didFailToGetEndingInterstitial() {}
    virtual void willCloseAppAfterEndingInterstitial() {}
};

class ValuePotionManager {
public:
    static void initialize(const char *clientId, const char *secretKey);
    static void setDelegate(ValuePotionManagerDelegate *delegate);
    static void setTest(bool isTest);

    static bool hasCachedInterstitial(const char *placement);
    static void cacheInterstitial(const char *placement);
    static void openInterstitial(const char *placement);
    
    static void trackEvent(const char *eventName);
    static void trackEvent(const char *eventName, double eventValue);
    static void trackEvent(const char *category, const char *eventName, const char *label, double eventValue);
    static void trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId);
    static void trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId);
    static void trackPurchaseEvent(const char *category, const char *eventName, const char *label, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId);

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    static void onBackPressed();
    static void cacheEndingInterstitial();
    #endif

    static void setUserId(const char *userId);
    static void setUserServerId(const char *serverId);
    static void setUserBirth(const char *birth);
    static void setUserGender(const char *gender);
    static void setUserLevel(double level);
    static void setUserFriends(double friends);
    static void setUserAccountType(const char *accountType);
};

#endif
