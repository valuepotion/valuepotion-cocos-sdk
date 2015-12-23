#include "ValuePotionManager.h"
#include "ValuePotionJni.h"

void ValuePotionManager::initialize(const char * clientId, const char * secretKey)
{
	ValuePotionJni::initialize(clientId, secretKey, SDK_TYPE, SDK_VERSION);
}

void ValuePotionManager::setDelegate(ValuePotionManagerDelegate * delegate)
{
	ValuePotionJni::setDelegate(delegate);
}

void ValuePotionManager::setTest(bool isTest)
{
	ValuePotionJni::setTest(isTest);
}

bool ValuePotionManager::hasCachedInterstitial(const char * placement)
{
	return ValuePotionJni::hasCachedInterstitial(placement);
}

void ValuePotionManager::cacheInterstitial(const char * placement)
{
	ValuePotionJni::cacheInterstitial(placement);
}

void ValuePotionManager::openInterstitial(const char *placement)
{
	ValuePotionJni::openInterstitial(placement);
}


void ValuePotionManager::trackEvent(const char *eventName)
{
	ValuePotionJni::trackEvent(eventName);
}

void ValuePotionManager::trackEvent(const char *eventName, double eventValue)
{
	ValuePotionJni::trackEvent(eventName, eventValue);
}

void ValuePotionManager::trackEvent(const char *category, const char *eventName, const char *label, double eventValue)
{
	ValuePotionJni::trackEvent(category, eventName, label, eventValue);
}

void ValuePotionManager::trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId)
{
	ValuePotionJni::trackPurchaseEvent(eventName, revenueAmount, currency, orderId, productId);
}

void ValuePotionManager::trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId)
{
	ValuePotionJni::trackPurchaseEvent(eventName, revenueAmount, currency, orderId, productId, campaignId, contentId);
}

void ValuePotionManager::trackPurchaseEvent(const char *category, const char *eventName, const char *label, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId)
{
	ValuePotionJni::trackPurchaseEvent(category, eventName, label, revenueAmount, currency, orderId, productId, campaignId, contentId);
}

void ValuePotionManager::onBackPressed()
{
	ValuePotionJni::onBackPressed();
}

void ValuePotionManager::cacheEndingInterstitial()
{
	ValuePotionJni::cacheEndingInterstitial();
}

void ValuePotionManager::setUserId(const char *userId)
{
	ValuePotionJni::setUserId(userId);
}

void ValuePotionManager::setUserServerId(const char *serverId)
{
	ValuePotionJni::setUserServerId(serverId);
}

void ValuePotionManager::setUserBirth(const char *birth)
{
	ValuePotionJni::setUserBirth(birth);
}

void ValuePotionManager::setUserGender(const char *gender)
{
	ValuePotionJni::setUserGender(gender);
}

void ValuePotionManager::setUserLevel(double level)
{
	ValuePotionJni::setUserLevel(level);
}

void ValuePotionManager::setUserFriends(double friends)
{
	ValuePotionJni::setUserFriends(friends);
}

void ValuePotionManager::setUserAccountType(const char *accountType)
{
	ValuePotionJni::setUserAccountType(accountType);
}
