//
//  SGTabsViewController.h
//  SGTabs
//
//  Created by simon on 07.06.12.
//
//
//  Copyright (c) 2012 Simon Grätzer
//  
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <UIKit/UIKit.h>

@protocol SGTabsViewControllerDelegate <NSObject>

@optional
- (void)willShowTab:(UIViewController *)viewController;
- (void)willRemoveTab:(UIViewController *)viewController;
- (BOOL)canRemoveTab:(UIViewController *)viewController;// TODO

@end

@class SGToolbar, SGTabsView;

@interface SGTabsViewController : UIViewController {
    BOOL _editable;
    CGRect _contentFrame;
    BOOL _toobarVisible;
}

/// Is an optional delegate
@property (nonatomic, weak) id<SGTabsViewControllerDelegate> delegate;
@property (nonatomic, readonly) BOOL editable;

/// Currently visible view controller
@property (nonatomic, readonly) UIViewController *currentViewController;

@property (nonatomic, readonly) NSMutableArray *tabContents;

- (id)initEditable:(BOOL)editable;

/// Adds a tab, don't add the same instance twice!
- (void)addTab:(UIViewController *)viewController;

/// Bring a tab to the frontpage
- (void)showViewController:(UIViewController *)viewController;
/// Primarily intended for internal use
- (void)showIndex:(NSUInteger)index;

- (void)removeViewController:(UIViewController *)viewController;
/// Primarily intended for internal use
- (void)removeIndex:(NSUInteger)index;

- (void)setToolbarHidden:(BOOL)hidden animated:(BOOL)animated;
- (BOOL)toolbarHidden;

- (NSUInteger)count;
- (NSUInteger)maxCount;

@end
