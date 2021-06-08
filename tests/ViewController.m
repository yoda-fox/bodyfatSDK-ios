//
//  ViewController.m
//  tests
//
//  Created by YouDa on 2021/6/8.
//

#import "ViewController.h"
#import <Dextrous/Dextrous.h>
#import <Dextrous/BodySDKManager.h>
#import <Dextrous/BodyFatConfig.h>
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [[BodySDKManager sharedInstance]deviceSearchSuccessScaleDeviceMacID:@"" age:18 height:172 loginAccount:@"150" sex:1 thirdNickName:@"fsvws" thirdUserNo:@"efwe" deviceSuccess:^(id  _Nonnull bodyFatConfig) {
        NSLog(@"%@",bodyFatConfig);
        BodyFatConfig *body = [[BodyFatConfig alloc]init];
        body = bodyFatConfig;
        NSLog(@"");
        } deviceFailure:^(NSError * _Nonnull error) {
            NSLog(@"%@",error);
            NSLog(@"");
        }];
}


@end
