# Valuepotion Cocos2d-x SDK 통합 가이드

## 기본 설정

### 1. 앱 정보 등록
먼저 [밸류포션](https://valuepotion.com) 웹사이트에 방문하여 SDK를 적용할 앱의 정보를 등록합니다. 앱 정보 등록을 완료하면 Client ID 와 Secret Key 가 발급됩니다.

### 2. Cocos2d-x 프로젝트에 SDK 임포트
Valuepotion Cocos2d-x SDK에 포함된 `ValuePotionManager.h` 파일과 `ValuePotion` 디렉토리를 Cocos2d-x 프로젝트의 `Classes` 디렉토리에 복사하여 넣으십시오.

### 3. 안드로이드 프로젝트 설정
1. `proj.android` 프로젝트를 이클립스에서 연 후, `Classes/ValuePotion/android` 디렉토리에 있는 `valuepotion.jar`, `valuepotioncocos.jar` 파일을 `libs` 디렉토리 밑으로 이동시킵니다.
2. Google Play Services 프로젝트에 대한 dependency를 추가합니다. 자세한 내용은 [이 문서](https://developer.android.com/google/play-services/setup.html)를 참조하십시오.
3. Android Support Library 프로젝트에 대한 dependency를 추가합니다. 자세한 내용은 [이 문서](http://developer.android.com/tools/support-library/setup.html)를 참조하십시오.

### 4. iOS 프로젝트 설정
1. `proj.ios` 프로젝트를 Xcode에서 연 후, Build Settings 탭에서 Other Linker Flags 항목에 `-ObjC` 플래그를 추가합니다.

2. Build Phases 탭의 Link Binary With Libraries 항목에 다음의 framework 들을 추가합니다.
  * `UIKit.framework`
  * `Foundation.framework`
  * `CoreGraphics.framework`
  * `SystemConfiguration.framework`
  * `CoreTelephony.framework`
  * `AdSupport.framework`

## SDK 초기화
다음은 SDK를 초기화 하는 예제입니다. 게임 실행 초기에 불려질 수 있도록 `AppDelegate.cpp` 파일의 `bool AppDelegate::applicationDidFinishLaunching()` 메소드 내에서 사용하는 것을 권장합니다.
```c
bool AppDelegate::applicationDidFinishLaunching() {
  ...

  // 밸류포션 웹사이트에서 발급받은 Client ID와 Secret Key를 사용 해 SDK를 초기화 합니다.
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    ValuePotionManager::initialize("ANDROID_APP_CLIENT_ID", "ANDROID_APP_SECRET_KEY");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    ValuePotionManager::initialize("IOS_APP_CLIENT_ID", "IOS_APP_SECRET_KEY");
#endif

    return true;
}
```

안드로이드의 경우 추가적으로, `proj.android` 프로젝트에 포함된 각 Activity에 다음과 같이 코드를 작성합니다.
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
여기까지 설정하면 기본적인 session / install / update 이벤트 트래킹이 가능합니다.

## 인터스티셜 광고 연동
### 1. 인터스티셜 광고 노출하기
[밸류포션](https://valuepotion.com) 웹 사이트에서 생성한 캠페인을 인터스티셜 광고의 형태로 자신의 앱에 노출시킬 수 있습니다. 인터스티셜 광고를 화면에 띄우기 위해서는 플레이스먼트를 지정해야 하며, 지정하지 않는 경우 "default" 플레이스먼트가 사용됩니다.

플레이스먼트는 게임 내의 여러 지점에서 원하는 광고를 노출 시킬 수 있도록 하기 위해 부여하는 이름으로, 특별한 제약 없이 원하는 이름을
문자열로 지정하면 됩니다.

```c
// "default" 플레이스먼트에 대해 광고를 노출 합니다.
ValuePotionManager::openInterstitial(NULL);

// "main_menu" 플레이스먼트에 대해 광고를 노출 합니다.
ValuePotionManager::openInterstitial("main_menu");
```

### 2. 인터스티셜 광고 캐싱하기
`ValuePotionManager::openInterstitial()` 메소드를 사용하면 HTTP 를 통해 광고 데이터를 받아온 후 화면에 보여주기 때문에, 네트워크 상태에 따라 다소 지연이 발생할 수 있습니다. 최초 게임 구동 시 원하는 플레이스먼트에 대해 광고를 캐싱해두면,
이후 원하는 시점에 지연 없이 해당 광고를 화면에 노출시킬 수 있습니다.

```c
// 최초 "after_login" 플레이스먼트에 대해 광고를 캐싱합니다.
ValuePotionManager::cacheInterstitial("after_login");

...

// 원하는 시점에 "after_login" 플레이스먼트에 대해 광고를 노출합니다.
ValuePotionManager::openInterstitial("after_login");
```

### 3. 캐시가 있을 때만 인터스티셜 광고 노출하기
특정 플레이스먼트에 캐싱된 광고가 확실히 존재할 때에만 광고를 노출시킬 수도 있습니다.

```c
// "item_shop" 플레이스먼트에 캐싱된 광고가 존재하는지 체크합니다.
if (ValuePotionManager::hasCachedInterstitial("item_shop")) {
  // "item_shop" 플레이스먼트에 대해 광고를 노출합니다.
  ValuePotionManager::openInterstitial("item_shop");
}
```

## 이벤트 트래킹
이벤트 트래킹 기능을 통해 게임에 대한 보다 세밀한 분석이 가능합니다. 또한, 이를 기반으로 유저 코호트를 생성하여 마케팅에 활용할 수 있습니다. 이벤트는 크게 비결제 이벤트와 결제 이벤트로 나뉩니다.

### 1.비결제 이벤트 트래킹
비결제 이벤트는 게임 내 결제와 무관한 이벤트로, 주로 사용자 행태 분석을 위해 사용합니다. 비결제 이벤트 트래킹을 위해서는 이벤트의 이름과 값을 지정해야 합니다. 다음은 비결제 이벤트를 전송하는 예제입니다.

```c
// 사용자가 3개의 아이템을 획득
ValuePotionManager::trackEvent("get_item_ruby", 3);
```

특별한 값이 필요치 않은 이벤트인 경우, 간단히 이벤트 이름만을 지정하여도 됩니다.

```c
// 사용자가 item shop 메뉴에 방문
ValuePotionManager::trackEvent("enter_item_shop");
```

이벤트에 계층을 두어 구분하고 싶을 때는 다음과 같이 사용할 수 있습니다.

```c
const char *category = "item";
const char *action = "get_ruby";
const char *label = "reward_for_login";
double value = 30;
ValuePotionManager::trackEvent(category, action, label, value);
```

### 2. 결제 이벤트 트래킹
결제 이벤트는 게임 내 구매(In App Billing 또는 In App Purchase)가 발생했을 때 전송하는 이벤트입니다. 결제 이벤트를 트래킹하면 매출액, ARPU, ARPPU, PPU 등 유용한 지표들의 추이를 매일 확인할 수 있습니다.
다음은 게임 내에서 발생한 결제 이벤트를 전송하는 예제입니다.

```c
// 0.99 달러의 코인 아이템 구매가 발생
const char *orderId = "23847983247018237";                 // 결제 성공 후 발행된 영수증 번호
const char *productId = "com.valuepotion.tester.item_01";  // 아이템의 식별자
ValuePotionManager::trackPurchaseEvent("purchase_coin", 0.99, "USD", orderId, productId);
```

밸류포션은 In App Purchase (이하 IAP) 타입의 캠페인을 제공합니다. 게임 사용자가 IAP 타입의 광고를 통해 매출을 발생시킨 경우, 결제 이벤트에 추가 정보를 더해 전송하면 더욱 상세한 캠페인 별 매출 리포트를 제공 받으실 수 있습니다. 다음은 IAP 광고로부터 발생한 결제 이벤트를 전송하는 예제입니다.

`didRequestPurchase` 델리게이트 메소드에 대한 보다 자세한 정보는 **고급: 델리게이트 메소드** 섹션의 **didRequestPurchase** 항목을 참고하십시오.

```c
void AppDelegate::didRequestPurchase(const char *placement, const char *name, const char *productId, int quantity, const char *campaignId, const char *contentId)
{
  // 요청받은 결제를 진행합니다.

  ...

  // 1,200 원의 다이아몬드 아이템 구매가 발생.
  const char *orderId = "23847983247018237";                 // 결제 성공 후 발행된 영수증 번호
  const char *productId = "com.valuepotion.tester.item_01";  // 아이템의 식별자
  ValuePotionManager::.trackPurchaseEvent("iap_diamond", 1200, "KRW", orderId, productId, campaignId, contentId);
}
```

#### 참고
* 정확한 집계를 위해, 결제 이벤트 전송 시에는 실제 발생한 결제 금액과 통화 코드를 지정해주십시오.
* 통화 코드는 [ISO 4217](http://en.wikipedia.org/wiki/ISO_4217) 표준을 따릅니다.

### 3. 이벤트 트래킹 테스트
SDK의 테스트 모드를 통해 정상적으로 이벤트가 전송되는지 여부를 쉽게 확인할 수 있습니다. 테스트 모드를 활성화 시키는 방법은 다음과 같습니다.

```c
// 테스트 모드로 설정
ValuePotionManager::setTest(true);
```

테스트 모드로 빌드된 앱에서 전송되는 이벤트는 [밸류포션](https://valuepotion.com) 웹사이트의 개발자 콘솔 메뉴에서 실시간으로 확인 가능합니다.

**주의** : 앱 스토어에 제출하기 위한 최종 빌드 시에는 반드시 테스트 모드를 해제하십시오. 테스트 모드에서 전송된 이벤트는 개발자 콘솔 메뉴에서만 출력되고, 실제 집계에서는 제외됩니다.


## 사용자 정보 연동
이벤트 트래킹과는 별도로, 게임 사용자의 추가 정보에 대한 수집이 가능합니다. 현재 밸류포션에서 지원하는 사용자 정보는 사용자의 계정 ID, 사용자가 속한 게임 서버의 ID, 생년월일, 성별, 레벨, 친구 수, 계정 타입의 7가지입니다. 모든 항목은 선택적이므로, 필요치 않다면 어떤 것도 설정할 필요가 없습니다.

이 정보들을 이용해 유저 코호트를 생성하여 마케팅에 활용할 수있습니다. 사용자 정보는 게임의 진행 중 변경이 있을 때마다 새로이 설정하여 주시면 자동으로 밸류포션과 연동됩니다.

```java
ValuePotionManager::setUserId("support@valuepotion.com");
ValuePotionManager::setUserServerId("server1");
ValuePotionManager::setUserBirth("19830328");
ValuePotionManager::setUserGender("M");
ValuePotionManager::setUserLevel(32);
ValuePotionManager::setUserFriends(219);
ValuePotionManager::setUserAccountType("guest");
```

각 사용자 정보 항목에 대한 세부 내용은 다음과 같습니다.

이름             | 설명
--------------- | ------------
**userId**      | 게임 내에서 사용되는 사용자의 계정 id를 설정합니다.
**serverId**    | 게임 유저를 서버 별로 식별해야 하는 경우 유저가 속한 서버의 id를 설정합니다.<br>serverId를 기준으로 서버별 통계를 확인할 수 있습니다.
**birth**       | 사용자의 생년월일 8자리를 문자열로 세팅합니다.<br>연도 정보만 아는 경우 "19840000"과 같이 뒤 4자리를 0으로 채웁니다.<br>생일 정보만 아는 경우 "00001109"와 같이 앞 4자리를 0으로 채웁니다.
**gender**      | 남성인 경우 "M", 여성인 경우 "F" 문자열로 설정합니다.
**level**       | 사용자의 게임 내 레벨을 설정합니다.
**friends**     | 사용자의 친구 수를 설정합니다.
**accountType** | 사용자의 로그인 계정 타입을 설정합니다. (facebook, google, guest 등)

## Push Notification 연동
밸류포션 Push Notification API와 연동하면, 손쉽게 Push 타입의 캠페인을 생성하여 사용자에게 메시지를 전송할 수 있습니다. 장기간 게임을 플레이 하지 않은 유저들이 다시 접속하도록 유도하거나, 게임 내 이벤트 소식을 알리는 등 다방면으로 활용이 가능합니다.

### 1. 안드로이드 프로젝트 연동
[이 문서](https://github.com/valuepotion/valuepotion-android-sdk/blob/master/README.KO.md#push-notification-%EC%97%B0%EB%8F%99)를 참조하십시오.

### 2. iOS 프로젝트 연동
[이 문서](https://github.com/valuepotion/valuepotion-ios-sdk/blob/master/README.KO.md#push-notification-%EC%97%B0%EB%8F%99)를 참조하십시오. 단, `AppDelegate` 클래스가 아닌 `AppController` 클래스에 적용해야 합니다.


## 고급: 델리게이트 메소드
`ValuePotionManagerDelegate` 클래스에는 캠페인 연동 시 활용 가능한 델리게이트 메소드들이 정의되어 있습니다. 모든 델리게이트 메소드의 구현은 선택 사항입니다. 따라서 필요한 이벤트에 대한 핸들러만 구현하여 사용하시면 됩니다.

델리게이트 메소드를 구현할 클래스는 어떤 것이든 관계 없으나, 가능하면 앱이 실행되는 동안 항상 존재하는 `AppDelegate` 클래스를 사용하시는 것을 권장합니다. 먼저, 다음과 같이 delegate를 설정해야 합니다.
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

### 1. Interstitial 노출 관련
#### willOpenInterstitial
`ValuePotionManager::openInterstitial()` 메소드 호출 후, 인터스티셜 광고가 성공적으로 화면에 노출되는 시점에  호출됩니다.

```c
void AppDelegate::willOpenInterstitial(const char *placement)
{
  // 인터스티셜 광고가 열릴 때 필요한 작업이 있다면 여기에 구현합니다.
  // 실행 중인 게임을 pause 시키는 등의 처리를 할 수 있습니다.
}
```

#### didFailToOpenInterstitial
`ValuePotionManager::openInterstitial()` 메소드 호출 후, 인터스티셜 광고가 화면에 노출되지 못하는 경우 호출됩니다.

```java
void AppDelegate::didFailToOpenInterstitial(const char *placement, const char *errorMessage)
{
  // 인터스티셜 광고 노출에 실패했을 때 필요한 작업이 있다면 여기에 구현합니다.
  // 실패한 원인은 errorMessage 를 통해 확인할 수 있습니다.
}
```

#### didCloseInterstitial
인터스티셜 광고가 열려있는 상태에서 닫힐 때 호출됩니다.

```c
void AppDelegate::didCloseInterstitial(const char *placement)
{
  // 인터스티셜 광고가 닫힐 때 필요한 작업이 있다면 여기에 구현합니다.
  // 광고가 열려있는 동안 게임을 pause 시켰다면, 여기서 resume 시키는 등의 처리를 할 수 있습니다.
}
```

### 2. Interstitial 캐싱 관련
#### didChacheInterstitial
`ValuePotionManger::cacheInterstitial()` 메소드 호출 후, 성공적으로 광고가 캐싱 되었을 때 호출됩니다.

```c
void AppDelegate::didCacheInterstitial(const char *placement)
{
  // 인터스티셜 광고 캐싱이 완료된 후 필요한 작업이 있다면 여기에 구현합니다.
}
```

#### didFailToCacheInterstitial
`ValuePotionManager::cacheIntestitial()` 메소드 호출 후, 광고 캐싱에 실패했을 때 호출됩니다.

```c
void AppDelegate::didFailToCacheInterstitial(const char *placement, const char *errorMessage)
{
  // 인터스티셜 광고 캐싱에 실패했을 때 필요한 작업이 있다면 여기에 구현합니다.
  // 실패한 원인은 errorMessage 를 통해 확인할 수 있습니다.
}
```

### 3. Interstitial 액션 관련
#### didRequestOpenURL
인터스티셜 광고 노출 상태에서 사용자가 외부 링크를 클릭하는 경우 발생합니다.

```c
void AppDelegate::didRequestOpenURL(const char *placement, const char *URL)
{
  // 외부 링크를 열 때 필요한 작업이 있다면 여기에 구현합니다.
  // 앱이 Background로 진입하게 되므로, 사용자 데이터를 저장하는 등의 처리를 할 수 있습니다.
}
```

#### didRequestPurchase
IAP 타입의 인터스티셜 광고 노출 상태에서 사용자가 '결제하기'를 선택하는 경우 발생합니다.

```c
void AppDelegate::didRequestPurchase(const char *placement, const char *name, const char *productId, int quantity, const char *campaignId, const char *contentId)
{
  // 인자로 전달된 productId, quantity 정보를 가지고 실제 결제를 진행하도록 구현합니다.
  // 결제가 완료된 이후 ValuePotionManager::trackPurchaseEvent() 메소드를 사용해
  // 결제 이벤트를 전송하면 매출 리포트가 집계됩니다.
}
```

#### didRequestRewards
Reward 타입의 인터스티셜 광고가 노출될 때 발생합니다.

```c
void AppDelegate::didRequestRewards(const char *placement, std::vector<Reward> rewards)
{
  // rewards 벡터에는 해당 광고를 통해 사용자에게 지급하고자 하는 리워드 정보들이 담겨있습니다.
  // 이 정보들을 가지고 사용자에게 리워드를 지급하는 코드를 구현합니다.
  for (int i = 0; i < rewards.size(); i++) {
    Reward reward = rewards.at(i);
    // 지급할 리워드 아이템의 이름과 수량.
    printf("%s, %d", reward.name, reward.quantity);
  }
}
```
