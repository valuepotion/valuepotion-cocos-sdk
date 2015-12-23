#include "ValuePotionJni.h"
#include "ValuePotionManager.h"
#include <Json.h>

#define CLASS_NAME "com/valuepotion/sdk/cocos/android/VPCocosBinder"

using namespace cocos2d;
ValuePotionManagerDelegate * ValuePotionJni::s_delegate;

void ValuePotionJni::initialize(const char *clientId, const char *secretKey, const char *sdkType, const char *sdkVersion)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "initialize", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(clientId);
	jstring arg2 = methodInfo.env->NewStringUTF(secretKey);
	jstring arg3 = methodInfo.env->NewStringUTF(sdkType);
	jstring arg4 = methodInfo.env->NewStringUTF(sdkVersion);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1, arg2, arg3, arg4);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
	methodInfo.env->DeleteLocalRef(arg2);
	methodInfo.env->DeleteLocalRef(arg3);
	methodInfo.env->DeleteLocalRef(arg4);
}

void ValuePotionJni::setDelegate(ValuePotionManagerDelegate *delegate)
{
	s_delegate = delegate;
}

void ValuePotionJni::setTest(bool isTest)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setTest", "(Z)V"))
	{
		return;
	}
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, isTest);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

bool ValuePotionJni::hasCachedInterstitial(const char *placement)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "hasCachedInterstitial", "(Ljava/lang/String;)Z"))
	{
		return false;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(placement);
	jboolean ret = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, arg1);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
	return ret;
}

void ValuePotionJni::cacheInterstitial(const char *placement)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "cacheInterstitial", "(Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(placement);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
}

void ValuePotionJni::openInterstitial(const char *placement)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "openInterstitial", "(Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(placement);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
}

void ValuePotionJni::trackEvent(const char *eventName)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "trackEvent", "(Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(eventName);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
}

void ValuePotionJni::trackEvent(const char *eventName, double eventValue)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "trackEvent", "(Ljava/lang/String;D)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(eventName);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1, eventValue);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
}

void ValuePotionJni::trackEvent(const char *category, const char *eventName, const char *label, double eventValue)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "trackEvent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;D)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(category);
	jstring arg2 = methodInfo.env->NewStringUTF(eventName);
	jstring arg3 = methodInfo.env->NewStringUTF(label);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1, arg2, arg3, eventValue);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
	methodInfo.env->DeleteLocalRef(arg2);
	methodInfo.env->DeleteLocalRef(arg3);
}

void ValuePotionJni::trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "trackPurchaseEvent", "(Ljava/lang/String;DLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(eventName);
	jstring arg3 = methodInfo.env->NewStringUTF(currency);
	jstring arg4 = methodInfo.env->NewStringUTF(orderId);
	jstring arg5 = methodInfo.env->NewStringUTF(productId);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1, revenueAmount, arg3, arg4, arg5);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
	methodInfo.env->DeleteLocalRef(arg3);
	methodInfo.env->DeleteLocalRef(arg4);
	methodInfo.env->DeleteLocalRef(arg5);
}

void ValuePotionJni::trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "trackPurchaseEvent", "(Ljava/lang/String;DLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(eventName);
	jstring arg3 = methodInfo.env->NewStringUTF(currency);
	jstring arg4 = methodInfo.env->NewStringUTF(orderId);
	jstring arg5 = methodInfo.env->NewStringUTF(productId);
	jstring arg6 = methodInfo.env->NewStringUTF(campaignId);
	jstring arg7 = methodInfo.env->NewStringUTF(contentId);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1, revenueAmount, arg3, arg4, arg5, arg6, arg7);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
	methodInfo.env->DeleteLocalRef(arg3);
	methodInfo.env->DeleteLocalRef(arg4);
	methodInfo.env->DeleteLocalRef(arg5);
	methodInfo.env->DeleteLocalRef(arg6);
	methodInfo.env->DeleteLocalRef(arg7);
}

void ValuePotionJni::trackPurchaseEvent(const char *category, const char *eventName, const char *label, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "trackPurchaseEvent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;DLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(category);
	jstring arg2 = methodInfo.env->NewStringUTF(eventName);
	jstring arg3 = methodInfo.env->NewStringUTF(label);
	jstring arg5 = methodInfo.env->NewStringUTF(currency);
	jstring arg6 = methodInfo.env->NewStringUTF(orderId);
	jstring arg7 = methodInfo.env->NewStringUTF(productId);
	jstring arg8 = methodInfo.env->NewStringUTF(campaignId);
	jstring arg9 = methodInfo.env->NewStringUTF(contentId);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1, arg2, arg3, revenueAmount, arg5, arg6, arg7, arg8, arg9);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
	methodInfo.env->DeleteLocalRef(arg2);
	methodInfo.env->DeleteLocalRef(arg3);
	methodInfo.env->DeleteLocalRef(arg5);
	methodInfo.env->DeleteLocalRef(arg6);
	methodInfo.env->DeleteLocalRef(arg7);
	methodInfo.env->DeleteLocalRef(arg8);
	methodInfo.env->DeleteLocalRef(arg9);
}

void ValuePotionJni::cacheEndingInterstitial()
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "cacheEndingInterstitial", "()V"))
	{
		return;
	}
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

void ValuePotionJni::onBackPressed()
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "onBackPressed", "()V"))
	{
		return;
	}
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

void ValuePotionJni::setUserId(const char *userId)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setUserId", "(Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(userId);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
}

void ValuePotionJni::setUserServerId(const char *serverId)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setUserServerId", "(Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(serverId);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
}

void ValuePotionJni::setUserBirth(const char *birth)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setUserBirth", "(Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(birth);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
}

void ValuePotionJni::setUserGender(const char *gender)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setUserGender", "(Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(gender);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
}

void ValuePotionJni::setUserLevel(double level)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setUserLevel", "(D)V"))
	{
		return;
	}
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, level);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

void ValuePotionJni::setUserFriends(double friends)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setUserFriends", "(D)V"))
	{
		return;
	}
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, friends);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

void ValuePotionJni::setUserAccountType(const char *accountType)
{
	JniMethodInfo methodInfo;

	if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setUserAccountType", "(Ljava/lang/String;)V"))
	{
		return;
	}
	jstring arg1 = methodInfo.env->NewStringUTF(accountType);
	methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, arg1);
	methodInfo.env->DeleteLocalRef(methodInfo.classID);
	methodInfo.env->DeleteLocalRef(arg1);
}

extern "C"
{
	void Java_com_valuepotion_sdk_cocos_android_VPCocosBinder_onCachedInterstitial(JNIEnv* env, jobject thiz, jstring placement)
	{
	  if (ValuePotionJni::s_delegate != NULL)
	  {
	    ValuePotionJni::s_delegate->didCacheInterstitial(JniHelper::jstring2string(placement).c_str());
	  }
	}

	void Java_com_valuepotion_sdk_cocos_android_VPCocosBinder_onClosedInterstitial(JNIEnv* env, jobject thiz, jstring placement)
	{
	  if (ValuePotionJni::s_delegate != NULL)
	  {
	    ValuePotionJni::s_delegate->didCloseInterstitial(JniHelper::jstring2string(placement).c_str());
	  }
	}

	void Java_com_valuepotion_sdk_cocos_android_VPCocosBinder_onFailedToCacheInterstitial(JNIEnv* env, jobject thiz, jstring placement, jstring error)
	{
	  if (ValuePotionJni::s_delegate != NULL)
	  {
	    ValuePotionJni::s_delegate->didFailToCacheInterstitial(JniHelper::jstring2string(placement).c_str(), JniHelper::jstring2string(error).c_str());
	  }
	}

	void Java_com_valuepotion_sdk_cocos_android_VPCocosBinder_onFailedToOpenInterstitial(JNIEnv* env, jobject thiz, jstring placement, jstring error)
	{
	  if (ValuePotionJni::s_delegate != NULL)
	  {
	    ValuePotionJni::s_delegate->didFailToOpenInterstitial(JniHelper::jstring2string(placement).c_str(), JniHelper::jstring2string(error).c_str());
	  }
	}

	void Java_com_valuepotion_sdk_cocos_android_VPCocosBinder_onReadyToOpenInterstitial(JNIEnv* env, jobject thiz, jstring placement)
	{
	  if (ValuePotionJni::s_delegate != NULL)
	  {
	    ValuePotionJni::s_delegate->willOpenInterstitial(JniHelper::jstring2string(placement).c_str());
	  }
	}

	void Java_com_valuepotion_sdk_cocos_android_VPCocosBinder_onRequestedOpen(JNIEnv* env, jobject thiz, jstring placement, jstring url)
	{
	  if (ValuePotionJni::s_delegate != NULL)
	  {
	    ValuePotionJni::s_delegate->didRequestOpenURL(JniHelper::jstring2string(placement).c_str(), JniHelper::jstring2string(url).c_str());
	  }
	}

	void Java_com_valuepotion_sdk_cocos_android_VPCocosBinder_onRequestedPurchase(JNIEnv* env, jobject thiz, jstring placement, jstring name, jstring productId, int quantity, jstring campaignId, jstring contentId)
	{
	  if (ValuePotionJni::s_delegate != NULL)
	  {
	    ValuePotionJni::s_delegate->didRequestPurchase(
	    		JniHelper::jstring2string(placement).c_str(),
	    		JniHelper::jstring2string(name).c_str(),
	    		JniHelper::jstring2string(productId).c_str(),
	    		quantity,
	    		JniHelper::jstring2string(campaignId).c_str(),
	    		JniHelper::jstring2string(contentId).c_str());
	  }
	}

	const char * copyString(const char * src)
	{
		int length = strlen(src);
		char * dest = new char[length + 1];
		strncpy(dest, src, sizeof(dest));
		dest[length] = 0;
		return dest;
	}

	void Java_com_valuepotion_sdk_cocos_android_VPCocosBinder_onRequestedReward(JNIEnv* env, jobject thiz, jstring placement, jstring rewardsJson)
	{
		extension::Json* json = extension::Json_create(JniHelper::jstring2string(rewardsJson).c_str());
		int length = extension::Json_getSize(json);
		std::vector<Reward> rewards;
		for (int i = 0; i < length; i++)
		{
			extension::Json* item = extension::Json_getItemAt(json, i);
			Reward reward;
			reward.name = copyString(extension::Json_getString(item, "name", ""));
			reward.quantity = extension::Json_getInt(item, "quantity", 0);
			rewards.push_back(reward);
		}
		extension::Json_dispose(json);
		ValuePotionJni::s_delegate->didRequestRewards(JniHelper::jstring2string(placement).c_str(), rewards);
		for (int i = 0; i < length; i++)
		{
			Reward reward = (Reward) rewards.at(i);
			delete[] reward.name;
		}
	}

	void Java_com_valuepotion_sdk_cocos_android_VPCocosBinder_onEndingInterstitialNotFound(JNIEnv* env, jobject thiz)
	{
		ValuePotionJni::s_delegate->didFailToGetEndingInterstitial();
	}

	void Java_com_valuepotion_sdk_cocos_android_VPCocosBinder_onAppClosingAfterEndingInterstitial(JNIEnv* env, jobject thiz)
	{
		ValuePotionJni::s_delegate->willCloseAppAfterEndingInterstitial();
	}
}
