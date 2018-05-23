//
//  Pixoneye.h
//  PixoneyeSDK
//
//  Created by Noam Segev on 23/07/2017.
//  Copyright © 2017 Pixoneye. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PixCampaign.h"


typedef void(^onGetBestItemResult)(NSString*);
typedef void(^onGetBestItemsResult)(NSDictionary<NSString*, PixCampaign*>*);

extern NSString* const PIXONEYE_CAMPAIGN_ID_KEY;
extern NSString* const PIXONEYE_CAMPAIGN_METADATA_KEY;

@interface Pixoneye : NSObject
@property (assign, atomic) BOOL isStopped;
-(instancetype)init __unavailable;

+ (instancetype)sharedInstance;
/*!
 @brief Call this method to initialize Pixoneye.
 
 @param appID Received from Pixoneye.
 
 @param userID optional  An id of the user in your system.
 
 @param apiKey Received from Pixoneye.
 
 @code
 [Pixoneye startPixoneye:@"YOUR_APP_ID" @"YOUR_USER_ID" @"YOUR_API_KEY"];
 @endcode
 
 @remark
 Better called from app Delegate.
 Make sure you have request perrmission for photos prior to this.
 You might prefer downloading the api key from your server rather than hardcosing it in you app.
 @endremark
 */
- (void) startPixoneyeWithAppId:(NSString*) appId apiKey:(NSString*) apiKey andUserId:(NSString*) userId;
/*!
 @brief Turns on console logging.
 
 @param verbose BOOL.
 
 @code
 [Pixoneye setVerbose:YES];
 @endcode
 
 @remark Default value is off
 */
- (void) setVerbose:(BOOL) verbose;
/*!
 @brief Retrives IOS SDK version.
 
 @return String The version.
 
 */
- (NSString*) getVersion;
/*!
 @brief Retrives IOS SDK build number.
 
 @return String The version.
 
 */
- (NSString*) getBuild;

/*!
 @brief Call this method to get an item from the Pixoneye recomendation system. Must be done after calling start
 
 @param appID Received from Pixoneye.
 
 @param extraData Apply some constarints on the recomendation.
 
 @param completionBlock recevie an item or null.
 
 @code
 [Pixoneye getBestItem:@"YOUR_APP_ID" :@"YOUR_API_KEY": @"some constraint" : ^(NSString* item) {
 if(item != nil){
 if ([Pixoneye isVerbose]) NSLog(@"%s getBestItem returned", __PRETTY_FUNCTION__);    }
 }];
 @endcode
 
 @remark This is a super-easy method.
 */

-(void) getBestItemForAdUnitId:(NSString*)extraData completionBlock:(onGetBestItemResult) completionBlock;

/*!
 @brief Call this method to get a list of items item from the Pixoneye recomendation system. Must be done after calling start
 
 @param appID Received from Pixoneye.
 
 @param completionBlock recevie a list of Campaigns.
 
 @code
 //TODO
 @endcode
 
 @remark This is a super-easy method.
 */
- (void) getBestAllItems:(onGetBestItemsResult) completionBlock;
- (void) getBestItemsForAdUnitIds:(NSArray<NSString*>*)adUnitIDs completionBlock:(onGetBestItemsResult) completionBlock;

/*!
 @brief Retrive console logging status of the SDK.
 
 @return BOOL is logging on or off.
 */

//- (BOOL) isVerbose;
-(void)endPixoneye;

- (void) sendPushToken:(NSString*)pushToken;
@end
