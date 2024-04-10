//
//  ShieldCallback.h
//  ShieldSDK
//
//  Copyright (c) 2013 Promon AS. All rights reserved.
//

/*
 * This protocol is to be implemented by classes that want to
 * be notified about events provided by Promon Shield.
 */
@protocol ShieldCallback <NSObject>

typedef NS_ENUM(NSInteger, ShieldDeveloperModeStatus) {
    /** Shield has determined status of Developer Mode to disabled. */
    ShieldDeveloperModeStatusDisabled = 0,
    /** Shield has determined status of Developer Mode to enabled. */
    ShieldDeveloperModeStatusEnabled = 1,
    /** Shield is not able to determine status of Developer mode, for example due to unsupported iOS version. */
    ShieldDeveloperModeStatusNotAvailable = 2
};

@optional

// This method is called when the Shield SDK has determined whether the device that the application runs on is jailbroken.
- (void) jailbreakStatus: (int) jailbroken;

// This method is called when the Shield SDK has determined that the application runs in emulator.
- (void) emulatorDetected;

// This method is called when the Shield SDK has determined whether the host application was repackaged.
- (void) repackagingStatus: (int) repackaged;

// This method is called when the Shield SDK has determined whether the host application is being recorded.
- (void)screenRecordStatusChanged:(BOOL)isRecording;

// This method is called when the Shield SDK has determined whether a debugger is attached to the host application.
- (void) debuggerStatus: (int) debugged;

// This method is called when the Shield SDK discovers that a screenshot has been taken of the application.
- (void) screenshotDetected;

// This method is called when Shield has prevented an untrusted library from being injected into the
// application during runtime.
- (void) libraryInjectionPrevented;

// This method is called when Shield has detected that there are untrusted libraries in the process.
- (void) libraryInjectionDetected;

// This method is called when Shield has detected that there are hooking frameworks in the process.
- (void) hookingFrameworksDetected;

// This method is called when Shield has determined whether developer mode is enabled on the device.
// Available on devices running iOS >= 16.
- (void) developerModeStatus: (ShieldDeveloperModeStatus) status;

// This method is called to pass "unspecified" messages from Shield.
- (void) buildSpecificMessage: (int) type withData: (NSData*) msg;

@end
