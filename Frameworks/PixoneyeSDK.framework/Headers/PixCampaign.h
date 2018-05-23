//
//  PixCampaign.h
//  PixoneyeSDK
//
//  Created by Itzik Alkotzer on 20/09/2017.
//  Copyright © 2017 Pixoneye. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PixCampaign : NSObject

-(instancetype)init __unavailable;

-(instancetype)initWithDic:(NSDictionary*)dic;

@property(nonatomic, strong, readonly) NSString *adUnitID;
@property(nonatomic, strong, readonly) NSString *campaignID;
@property(nonatomic, strong, readonly) NSString *trackingID;

@end
