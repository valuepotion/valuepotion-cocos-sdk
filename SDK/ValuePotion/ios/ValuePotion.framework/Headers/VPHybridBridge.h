//
//  VPHybridBridge.h
//
//  Copyright © 2016년 ValuePotion. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ValuePotion/ValuePotionDefines.h>
#import <ValuePotion/ValuePotionInstance.h>

@class UIWebView;
@class WKWebView;
@class WKNavigationAction;
@class VPHybridBridge;


NS_ASSUME_NONNULL_BEGIN

@interface ValuePotion (HybridBridge)

+ (VPHybridBridge *)bridge;

@end


/**
 * VPHybridBridge provides that
 */
@interface VPHybridBridge : NSObject

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request;
- (BOOL)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction;

@end


NS_ASSUME_NONNULL_END
