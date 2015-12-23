#ifndef _VALUEPOTION_JNI_H_
#define _VALUEPOTION_JNI_H_

#include <jni.h>
#include "platform/android/jni/JniHelper.h"
//#include <android/log.h>
#include "ValuePotionManager.h"

class ValuePotionJni {
	public:
		static ValuePotionManagerDelegate * s_delegate;

		static void initialize(const char *clientId, const char *secretKey, const char *sdkType, const char *sdkVersion);
		static void setDelegate(ValuePotionManagerDelegate *delegate);

		static void setTest(bool isTest);

		static void onBackPressed();
		static void cacheEndingInterstitial();

		static bool hasCachedInterstitial(const char *placement);
		static void cacheInterstitial(const char *placement);
		static void openInterstitial(const char *placement);

		static void trackEvent(const char *eventName);
		static void trackEvent(const char *eventName, double eventValue);
		static void trackEvent(const char *category, const char *eventName, const char *label, double eventValue);
		static void trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId);
		static void trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId);
		static void trackPurchaseEvent(const char *category, const char *eventName, const char *label, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId);

		static void setUserId(const char *userId);
		static void setUserServerId(const char *serverId);
		static void setUserBirth(const char *birth);
		static void setUserGender(const char *gender);
		static void setUserLevel(double level);
		static void setUserFriends(double friends);
		static void setUserAccountType(const char *accountType);
};

#endif // _VALUEPOTION_JNI_H_
