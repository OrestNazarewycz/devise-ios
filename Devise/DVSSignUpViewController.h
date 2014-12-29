//
//  DVSSignUpViewController.h
//  Devise
//
//  Created by Wojciech Trzasko on 23.12.2014.
//  Copyright (c) 2014 Netguru Sp. z o.o. All rights reserved.
//

#import "DVSBaseViewController.h"

#import "DVSUser.h"

typedef NS_OPTIONS(NSInteger, DVSSignUpFields) {
    DVSSignUpViewsEmailAndPassword           = 1 << 0,
    DVSSignUpViewsSignUpButton               = 1 << 1,
    DVSSignUpViewsDismissButton              = 1 << 2,
    DVSSignUpViewsNavigationSignUpButton     = 1 << 3,
    DVSSignUpViewsNavigationDismissButton    = 1 << 4
};

@protocol DVSSignUpViewControllerDelegate;

@interface DVSSignUpViewController : DVSBaseViewController

@property (weak, nonatomic) id<DVSSignUpViewControllerDelegate> delegate;

- (instancetype)initWithFields:(DVSSignUpFields)viewsOptions;

@end

@protocol DVSSignUpViewControllerDelegate <NSObject>

- (void)signUpViewController:(DVSSignUpViewController *)controller didSignUpUser:(DVSUser *)user;
- (void)signUpViewController:(DVSSignUpViewController *)controller didFailWithError:(NSError *)error;

@end