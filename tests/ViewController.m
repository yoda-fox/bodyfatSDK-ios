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
    UIButton *sen = [[UIButton alloc]initWithFrame:CGRectMake(100, 100, 200, 200)];
    [sen addTarget:self action:@selector(sendOnClick:) forControlEvents:UIControlEventTouchUpInside];
    sen.backgroundColor = [UIColor yellowColor];
    [self.view addSubview:sen];
    
}

-(void)sendOnClick:(UIButton *)sender{
    //等AppDeledate中registerApp方法调用成功后使用/Use it after the registerApp method in AppDeledate is called successfully
    [[BodySDKManager sharedInstance]deviceSearchSuccessScaleDeviceMacID:@"00:00:00:00:00:00" age:18 height:172 loginAccount:@"用户账号/user account(必填/Required)" sex:1 thirdNickName:@"用户账号/user account(必填/Required)" thirdUserNo:@"用户ID/User ID(必填/Required)" deviceSuccess:^(id  _Nonnull bodyFatConfig) {
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
