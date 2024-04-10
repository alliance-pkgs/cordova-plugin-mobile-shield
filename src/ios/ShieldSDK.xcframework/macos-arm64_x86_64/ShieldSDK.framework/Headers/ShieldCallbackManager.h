//
//  ShieldCallbackManager.h
//  ShieldSDK
//
//  Copyright (c) 2012 Promon AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ShieldCallback.h"

@interface ShieldCallbackManager : NSObject

 // This method adds a new observer that will be informed when Shield
 // performs security checks. You can add as many observers as you
 // like. Note that any observers added will be kept alive and will
 // receive callbacks for as long as the app is running.
+ (void)addObserver: (id<ShieldCallback>) observer;

 // This method sets an observer that will be informed when Shield performs
 // security checks. Note that if there was already another observer added using
 // this method, the previous observer will be removed.
 //
 // Please note that this method is deprecated and will be removed in the future.
 //
 // If you are setting an observer using this method and there has been another
 // observer registered previously, there can be rare instances where the old
 // observer is still being called instead of the new one shortly after this
 // method has returned.
+ (void)setObserver: (id<ShieldCallback>) observer __attribute__((deprecated));

 // This method removes the observer registered with setObserver.
 //
 // This method does not affect any observers registered with
 // addObserver.
 //
 // Please note that this method is deprecated and will be removed in the future.
 //
 // If you are removing an observer using this method, there can be rare instances
 // where the removed observer is still being called shortly after this method has
 // returned. Shield is internally retaining the observer object during the callback,
 // so you do not need to worry about memory management, but if your app depends on
 // not getting callbacks right after this method returns, you need to find a way to
 // handle this situation.
+ (void)removeObserver __attribute__((deprecated));
 
@end
