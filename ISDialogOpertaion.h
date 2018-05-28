#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>



@interface ISDialogButton : NSObject

@property int actionType;
@property (retain) NSDictionary *dictionary;
@property (retain) id parameter;
@property (retain) NSString *title;
@property long long urlType;
+(id)buttonWithTitle:(id)arg1 ;
@end

@interface ISDialog : NSObject

@property bool allowDuplicates;
@property (readonly) bool allowsBioAuthorization;
@property bool authorizationIsForced;
@property (retain) NSArray<ISDialogButton*> *buttons;
@property long long defaultButtonIndex;
@property bool dismissOnHomeButton;
@property bool dismissOnLock;
@property (copy) NSString *displayCountKey;
@property (getter=isDisplayable, readonly) bool displayable;
@property bool displaysOnLockscreen;
@property bool expectsResponse;
@property bool groupsTextFields;
@property long long kind;
@property long long maximumDisplayCount;
@property (retain) NSString *message;
@property bool noDefaultButton;
@property bool oneButtonPerLine;
@property bool shouldDismissAfterUnlock;
@property bool shouldDisplayAsTopMost;
@property bool shouldPendInSetupIfNotAllowed;
@property (retain) NSArray *textFields;
@property (retain) NSString *title;
@property long long unlockActionButtonIndex;


+ (long long)displayCountForKey:(id)arg1;

- (long long)_kindForString:(id)arg1;
- (bool)allowDuplicates;
- (bool)allowsBioAuthorization;
- (id)authenticationContext;
- (bool)authorizationIsForced;
- (id)copyUserNotification;
- (void*)copyValueForCFUserNotificationKey:(CFStringRef)arg1;
- (id)copyXPCEncoding;
- (void)dealloc;
- (long long)defaultButtonIndex;
- (bool)dismissOnHomeButton;
- (bool)dismissOnLock;
- (id)displayCountKey;
- (bool)displaysOnLockscreen;
- (bool)expectsResponse;
- (bool)groupsTextFields;
- (void)incrementDisplayCount;
- (id)init;
- (id)initWithAuthenticationChallege:(id)arg1;
- (id)initWithDialogDictionary:(id)arg1;
- (id)initWithError:(id)arg1;
- (id)initWithOfferDeviceError:(id)arg1;
- (id)initWithTitle:(id)arg1 message:(id)arg2;
- (id)initWithXPCEncoding:(id)arg1;
- (bool)isDisplayable;
- (bool)isEqual:(id)arg1;
- (long long)kind;
- (long long)maximumDisplayCount;
- (id)message;
- (bool)noDefaultButton;
- (bool)oneButtonPerLine;

- (bool)shouldDismissAfterUnlock;
- (bool)shouldDisplayAsTopMost;
- (bool)shouldPendInSetupIfNotAllowed;
- (id)textFields;
- (id)title;
- (long long)unlockActionButtonIndex;
- (id)valueForUserInfoKey:(id)arg1;

// Image: /System/Library/PrivateFrameworks/iTunesStoreUI.framework/iTunesStoreUI

+ (id)ITunesStoreNotAvailableDialog;

@end

@interface DaemonDialogOperation : NSObject

@property (readonly) ISDialog * dialog;
@property (assign) BOOL displaysOnLockscreen;
@property (copy) id outputBlock;
@property (copy,readonly) id dialogResponse;
-(void)dealloc;
-(void)run;
-(BOOL)displaysOnLockscreen;
-(void)setDisplaysOnLockscreen:(BOOL)arg1 ;
-(id)initWithDialog:(id)arg1 ;
-(void)setOutputBlock:(id)arg1 ;
-(id)outputBlock;
@end

@interface ISCreateAccountPromptOperation : NSObject
@property (assign,nonatomic) long long responseType;              //@synthesize responseType=_responseType - In the implementation block
@property (nonatomic,retain) NSString * reason;                   //@synthesize reason=_reason - In the implementation block
-(id)init;
-(void)run;
-(id)_newCreateAccountDialog;
-(id)initWithReason:(id)arg1 ;
@end

@interface ISDialogOperation : NSObject
@property bool performDefaultActions;
@property (retain) ISDialog *dialog;
@property (assign) id delegate; 
@property (retain) ISDialogButton * selectedButton;
@property (readonly) NSArray *textFieldValues;
@property (retain) id userNotification;

+ (id)operationWithDialog:(id)arg1;
+ (id)operationWithError:(id)arg1;

- (void)_handleResponseForNotification:(void*)arg1 responseFlags:(unsigned long long)arg2;
- (void)_run;
- (void)_showUserNotification:(id)arg1;
- (void)_waitForUserNotificationResponse:(void*)arg1;
- (void)cancel;
- (void)handleButtonSelected:(long long)arg1 withResponseDictionary:(id)arg2;
- (void)run;
- (id)textFieldValues;
- (id)userNotification;

@end



