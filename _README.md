# Valuepotion SDK for Cocos2d-x - Getting Started

## Before You Begin

### 1. Register Your App
Visit [Valuepotion](https://valuepotion.com) website and register the information of your app. After that, you will be given a **Client ID** and a **Secret Key**.

### 2. Import the SDK into your Cocos2d-x project
In Valuepotion Cocos2d-x SDK, there're `ValuePotionManager.h` file and `ValuePotion` folder. Copy them into `Classes` folder of your Cocox2d-x project.

### 3. Setup Android Project
1. Open `proj.android` project in Eclipse and move `valuepotion.jar` and `valuepotioncocos.jar` files under `Classes/ValuePotion/android` into `libs` folder.
2. Open `proj.android > jni > Android.mk` file and append `ValuePotionManager.cpp` and `ValuePotionJni.cpp` like following.
```
LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/ValuePotion/android/ValuePotionManager.cpp \
                   ../../Classes/ValuePotion/android/ValuePotionJni.cpp
```
3. Add *Google Play Services* as a dependency. Refer to [this document](https://developer.android.com/google/play-services/setup.html) to see the guide.
4. Add *Android Support Library* as a dependency. Refer to [this document](http://developer.android.com/tools/support-library/setup.html) to see the guide.

### 4. Setup iOS Project
1. Open `proj.ios` project in Xcode and add `-ObjC` flag to *Other Linker Flags* under *Build Settings*.

2. Add the following frameworks into *Link Binary With Libraries* under *Build Phases* tab.
  * `UIKit.framework`
  * `Foundation.framework`
  * `CoreGraphics.framework`
  * `SystemConfiguration.framework`
  * `CoreTelephony.framework`
  * `AdSupport.framework`

## Initialize SDK
The following example is to initialize SDK. We recommend you to initialize SDK in `bool AppDelegate::applicationDidFinishLaunching()` method of `AppDelegate.cpp` file in order to be initialize SDK in early timing.

```c
bool AppDelegate::applicationDidFinishLaunching() {
  ...

  // Use Client Id and Secret Key you received from Valuepotion website.
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    ValuePotionManager::initialize("ANDROID_APP_CLIENT_ID", "ANDROID_APP_SECRET_KEY");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    ValuePotionManager::initialize("IOS_APP_CLIENT_ID", "IOS_APP_SECRET_KEY");
#endif

    return true;
}
```

In case of Android, you have to add the following code into every Activity under `proj.android` project.

```java
protected void onCreate(Bundle savedInstanceState){
  super.onCreate(savedInstanceState);
  ...
  VPCocosBinder.setActivity(this);
}

@Override
protected void onStart() {
  super.onStart();
  ...
  VPCocosBinder.onStart(this);
}

@Override
protected void onResume() {
  super.onResume();
  ...
  VPCocosBinder.onResume(this);
}

@Override
protected void onPause() {
  super.onPause();
  ...
  VPCocosBinder.onPause(this);
}

@Override
protected void onStop() {
  super.onStop();
  ...
  VPCocosBinder.onStop(this);
}
```
If you've done so far, now you can see report of session / install / update.


## Integrate with Interstitial Ads

### 1. Display Interstitial Ads
If you've created a campaign at [Valuepotion](https://valuepotion.com), you can display it as an interstitial ad at your own app. Before displaying interstitial ads, you should set up a placement. Otherwise, "default" placement will be used by default.

**Placement** is a name to distinguish many points where you want to display ads. There's no restriction but it just should be a string.

```c
// Display ads at "default" placement.
ValuePotionManager::openInterstitial(NULL);

// Display ads at "main_menu" placement.
ValuePotionManager::openInterstitial("main_menu");
```

### 2. Cache Interstitial Ads
Using `ValuePotionManager::openInterstitial()` method, the SDK will download data for ads via HTTP and display on screen. So it takes some time. If you cache ads when your game launches, you can display the ads at any time with no delay.

```c
// If you cache an ad for "after_login" placement once,
ValuePotionManager::cacheInterstitial("after_login");

...

// Later on, you can display the ad with no delay.
ValuePotionManager::openInterstitial("after_login");
```

### 3. Display Interstitial Ads Only When Caches are Available
You can display interstitial ads only when caches are available.

```c
// Check if the cache for "item_shop" placement exists.
if (ValuePotionManager::hasCachedInterstitial("item_shop")) {
  // then, display the ad for "item_shop" placement.
  ValuePotionManager::openInterstitial("item_shop");
}
```

## Event Tracking
You can analyze your game with event tracking. And based on events you can create cohort to use for marketing. There are non-payment event and payment event.

### 1. Non-Payment Event
Non-payment event is not related to In-App Purchase. You can use non-payment event to analyze user behavior. To use non-payment event, you should define its name and values. The following code is an example to send non-payment event.

```c
// User has got 3 items.
ValuePotionManager::trackEvent("get_item_ruby", 3);
```

If there's no specific value needed, you can use event name only.

```c
// 사용자가 item shop 메뉴에 방문
ValuePotionManager::trackEvent("enter_item_shop");
```

If you want to build a hierarchy of events, you can specify that like following:

```c
const char *category = "item";
const char *action = "get_ruby";
const char *label = "reward_for_login";
double value = 30;
ValuePotionManager::trackEvent(category, action, label, value);
```

### 2. Payment Event
Payment event is tracked when In-App Purchase(In-App Billing) has occurred. If you track payment events, you can check daily statistics of Revenue, ARPU, ARPPU, PPU, etc.
The following code is an example to send payment event occurred in your game.

```c
// User purchased $0.99 coin item.
const char *orderId = "23847983247018237";                 // The identifier of receipt after completing purchase.
const char *productId = "com.valuepotion.tester.item_01";  // The identifier of item.
ValuePotionManager::trackPurchaseEvent("purchase_coin", 0.99, "USD", orderId, productId);
```

Valuepotion provides campaign of In-App Purchase (IAP) type. When a user makes revenue via an ad of IAP type, if you add extra info to payment event, you can get revenue report per campaign in detail. The following code is how to send payment event which occurred from IAP ad.

* To see more information about `didRequestPurchase` delegate method, please see **didRequestPurchase** item under **Advanced: Delegate Methods** section *

```c
void AppDelegate::didRequestPurchase(const char *placement, const char *name, const char *productId, int quantity, const char *campaignId, const char *contentId)
{
  // Proceed the requested payment

  ...

  // User purchased some Diamond item for KRW 1,200.
  const char *orderId = "23847983247018237";                 // The identifier of receipt after completing 
  const char *productId = "com.valuepotion.tester.item_01";  // The identifier of item.
  ValuePotionManager::trackPurchaseEvent("iap_diamond", 1200, "KRW", orderId, productId, campaignId, contentId);
}
```

You can also specify *category* and *label* like you did with non-payment event.

```c
ValuePotionManager::trackPurchaseEvent(category, eventName, label, amount, currency, orderId, productId, campaignId, contentId);
```

#### Reference
* For accurate analysis, please specify real purchase amount and currency.
* We follow [ISO 4217](http://en.wikipedia.org/wiki/ISO_4217) for currency.

### 3. Test If Event Tracking Works
You can test if event tracking works by using test mode of the SDK. The following code will activate test mode.

```c
// Activate test mode
ValuePotionManager::setTest(true);
```

If you send events from an app built with test mode, you should see the events on developer's console at [Valuepotion](https://valuepotion.com) at real time.

**Warning** : Before submitting your app to app store, please disable test mode. Events sent form test mode are only displayed on Developer's console but excluded from analysis.


## Integrate User Information
You can collect user information as well as events. Possible fields of user information are user id, server id which user belongs to, birthdate, gender, level, number of friends and type of user account. All of them are optional so you can choose which fields to collect.

You can use this information for marketing by creating user cohort. You can update your information when it changes to integrate with Valuepotion.

```java
ValuePotionManager::setUserId("support@valuepotion.com");
ValuePotionManager::setUserServerId("server1");
ValuePotionManager::setUserBirth("19830328");
ValuePotionManager::setUserGender("M");
ValuePotionManager::setUserLevel(32);
ValuePotionManager::setUserFriends(219);
ValuePotionManager::setUserAccountType("guest");
```

The following is the detail on each field.

Field           | Description
--------------- | ------------
**userId**      | User account id used in game
**serverId**    | If you need to distinguish users by server which they belong to, you should set serverId.<br>Then you can get statistics based on serverId.
**birth**       | Date of birth in YYYYMMDD. <br>If you know only year of birth, fill last four digits with "0" like "19840000".<br>If you know only date of birth(but not year), fill first four digits with "0" like "00001109".
**gender**      | "M" for male, "F" for female.
**level**       | Level of user in game.
**friends**     | Number of user's friends.
**accountType** | Type of user account. (facebook, google, guest, etc.)

## Integrate Push Notification
If you integrate with Push Notification API, you can easily create campaigns of Push type and send message to users. So you can wake up users who haven't played game for long time, or you can also notify users new events in game, etc.

### 1. Integerate Android push notification
Refer to *Integrate Push Notification* section under [this document](https://github.com/valuepotion/valuepotion-android-sdk/blob/master/README.md#integrate-push-notification).

### 2. Integrate iOS push notification
Refer to *Integrate Push Notification* section under [this document](https://github.com/valuepotion/valuepotion-ios-sdk/blob/master/README.md#push-notification-%EC%97%B0%EB%8F%99). You should integrate with `AppController` class, but not `AppDelegate` class.


## Advanced: Delegate Methods
`ValuePotionManagerDelegate` class has delegate methods defined to integrate with campaigns. All the delegate methods are optional. You can choose and implement methods as you need.

You can implement delegate methods in any class, but we recommend you to do it on `AppDelegate` class since it stays alive all the time.

```c
// AppDelegate.h
#include "cocos2d.h"
#include "ValuePotionManager.h"
class AppDelegate : private cocos2d::CCApplication, public ValuePotionManagerDelegate
{
  ...
}

// AppDelegate.cpp
#include "AppDelegate.h"
bool AppDelegate::applicationDidFinishLaunching()
{
  ...
  ValeuPotionManager::setDelegate(this);
}
```

### 1. Delegate Methods for Displaying Interstitial Ad
#### willOpenInterstitial
This delegate methods occurs when displaying interstitial ad is successfully done after calling `ValuePotionManager::openInterstitial()` method.

```c
void AppDelegate::willOpenInterstitial(const char *placement)
{
  // Put something you need to do when interstitial ad is displayed.
  // For example, you can pause game here.
}
```

#### didFailToOpenInterstitial
This delegate method occurs when displaying interstitial ad is failed after calling `ValuePotionManager::openInterstitial()` method.

```java
void AppDelegate::didFailToOpenInterstitial(const char *placement, const char *errorMessage)
{
  // Put something you need to do when interstitial ad gets failed.
  // You can check reason of failure via errorMessage variable.
}
```

#### didCloseInterstitial
This delegate method occurs when interstitial ad closes.

```c
void AppDelegate::didCloseInterstitial(const char *placement)
{
  // Put something you need to do when interstitial ad closes.
  // If you paused your game during ad is open, now you can resume it here.
}
```

### 2. Delegate Methods for Caching Interstitial Ad
#### didChacheInterstitial
This event occurs when caching interstitial ad is successfully done after calling `ValuePotionManger::cacheInterstitial()` method.

```c
void AppDelegate::didCacheInterstitial(const char *placement)
{
  // Put something you need to do when caching interstitial ad is successfully done
}
```

#### didFailToCacheInterstitial
This event occurs when caching interstitial ad is failed after calling `ValuePotionManager::cacheIntestitial()` method.

```c
void AppDelegate::didFailToCacheInterstitial(const char *placement, const char *errorMessage)
{
  // Put something you need to do when caching interstitial ad is failed.
  // You can check reason of failure via errorMessage variable.
}
```

### 3. Delegate Methods for Interstitial Ad Action
#### didRequestOpenURL
This event occurs when user clicks external url while interstitial ad is displayed.

```c
void AppDelegate::didRequestOpenURL(const char *placement, const char *URL)
{
  // Put something you need to do when external url gets opened.
  // App soon goes background, so you can do something like saving user data, etc.
}
```

#### didRequestPurchase
This delegate method occurs when user pressed 'Purchase' button while interstitial ad of IAP type is displayed.

```c
void AppDelegate::didRequestPurchase(const char *placement, const char *name, const char *productId, int quantity, const char *campaignId, const char *contentId)
{
  // Put codes to process real purchase by using parameters: productId, quantity.
  // After purchase, call ValuePotionManager::trackPurchaseEvent() method for revenue report.
}
```

#### didRequestRewards
This delegate method occurs when interstitial ad of Reward type is displayed.

```c
void AppDelegate::didRequestRewards(const char *placement, std::vector<Reward> rewards)
{
  // Vector 'rewards' contains rewards which ad is about to give users.
  // With this information you should implement actual code to give rewards to users.
  for (int i = 0; i < rewards.size(); i++) {
    Reward reward = rewards.at(i);
    // The names of quantities of rewards to give
    printf("%s, %d", reward.name, reward.quantity);
  }
}
```
