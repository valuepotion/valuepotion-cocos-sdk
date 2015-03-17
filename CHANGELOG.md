# Change Log

## v1.0.3
* Built with valuepotion-android-sdk-1.0.25 and valuepotion-ios-sdk-1.0.7
* Minor bug fixes
* Improved stability

### Android
* If the following code is already in your AndroidManifest.xml,
 ```xml
        <receiver
            android:name="com.valuepotion.sdk.push.GcmBroadcastReceiver"
            android:permission="com.google.android.c2dm.permission.SEND">
            <intent-filter>
                <action android:name="com.google.android.c2dm.intent.RECEIVE" />
                <action android:name="com.google.android.c2dm.intent.REGISTRATION" />
                <action android:name="com.valuepotion.sdk.push.NOTIFICATION_OPENED" />

                <category android:name="PACKAGE_NAME" />
            </intent-filter>
        </receiver>
 ```
 then replace it with the code below:
 ```xml
        <receiver
            android:name="com.valuepotion.sdk.push.GcmBroadcastReceiver"
            android:permission="com.google.android.c2dm.permission.SEND">
            <intent-filter>
                <action android:name="com.google.android.c2dm.intent.RECEIVE" />
                <action android:name="com.google.android.c2dm.intent.REGISTRATION" />

                <category android:name="PACKAGE_NAME" />
            </intent-filter>
        </receiver>
        <receiver
            android:name="com.valuepotion.sdk.push.NotificationOpenedReceiver">
            <intent-filter>
                <action android:name="com.valuepotion.sdk.push.NOTIFICATION_OPENED" />
            </intent-filter>
        </receiver>
 ```


## v1.0.2
* Built with valuepotion-android-sdk-1.0.24 and valuepotion-ios-sdk-1.0.6
* You can now specify category and label for payment events.

```c
ValuePotionManager::trackPurchaseEvent(category, eventName, label, amount, currency, orderId, productId, campaignId, contentId);
```

## v1.0.1
* Built with valuepotion-android-sdk-1.0.22 and valuepotion-ios-sdk-1.0.4

### Android
* Fixed a bug regarding push open.

## v1.0.0
* Built with valuepotion-android-sdk-1.0.21 and valuepotion-ios-sdk-1.0.4
