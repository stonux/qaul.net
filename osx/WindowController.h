#import <Cocoa/Cocoa.h>
#import <WebKit/WebView.h>
#import "QaulConfigWifi.h"


@interface WindowController : NSObject /* Specify a superclass (eg: NSObject or NSView) */ {
    IBOutlet id start_name;
    IBOutlet id qaulTabView;
	IBOutlet WebView *qaulWebView;
	NSString *username;
	NSString *qaulResourcePath;
	int qaulStarted;
	
	// wifi config
	QaulConfigWifi *mysudo;
	NSArray * qaulInterfacesAll;
	NSEnumerator *en;
	SCNetworkInterfaceRef qaulWifiInterface;
	BOOL qaulWifiInterfaceSet;
	SCNetworkServiceRef qaulServiceId;
	BOOL qaulServiceFound;
	BOOL qaulServiceConfigured;
	CFStringRef qaulServiceName;
	OSStatus status;
	AuthorizationRef authorizationRef;
	
	// Timer
	NSTimer *qaullibTimer;
	NSTimer *qaullibTimer2;
	NSTimer *qaullibTimer3;
}


// window loaded
- (void)awakeFromNib;
- (void)applicationDidFinishLaunching:(id)sender;
// window is closing
- (BOOL)windowShouldClose:(id)sender;
- (BOOL)applicationShouldTerminate:(id)app;

// support methods
- (void)endAlert:(id)sheet returnCode:(int)returnCode contextInfo:(void *)contextInfo;

- (void)init_app;

// timer
- (void)startTimer;
- (void)stopTimer;
- (void)checkIpcMessage:(NSTimer *)theTimer;
- (void)checkIpcTopology:(NSTimer *)theTimer;
- (void)checkNames;

// wait timer
- (void)startDelay:(NSTimeInterval)secs;
- (void)fireDelay;

@end
