//
//  AppDelegate.h
//  Pixoneye Test
//
//  Created by James Crosthwaite on 26/04/2018.
//  Copyright © 2018 James Crosthwaite. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

