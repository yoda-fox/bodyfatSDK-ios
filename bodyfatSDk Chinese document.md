# 与体脂秤交互获取人体各项数据

# SDK使用说明文档

[英文文档](https://github.com/yoda-fox/bodyfatSDK-ios/edit/main/README.md)  

## 使用条件

   1.Xcode
   
   2.IOS 9.0及以上
   
## 添加权限 在Info.plist文件中添加蓝牙权限

    1.Privacy - Bluetooth Peripheral Usage Description      蓝牙外设使用说明
   
    2.Privacy - Bluetooth Always Usage Description          蓝牙始终使用说明
   
## 导入Dextrous.framework

    在文件中导入Dextrous.framework
    
## 申明头文件

    在需要调用的.m文件中申明 #import <Dextrous/Dextrous.h>
    
## 初始化

  ### 1.在Appdelegate.m    didFinishLaunchingWithOptions方法中添加
    
    [[BodySDKManager sharedInstance]BlueSharedInstance];
    
    [[BodySDKManager sharedInstance]registerApp:@"appid" withSecret:@"secret" success:^(id  _Nonnull responseModel) {
         ResponseModel *resmodel = responseModel;
         } failure:^(NSError * _Nonnull error) {
             NSLog(@"%@",error);
         }];
         
  ### 2.参数说明
  
      appid，secret ，需填入自己申请的。
      
  ### 3.结果回调：
  
     resmodel.code = 0;为成功 resmodel.code = 1;为错误 error为请求失败
     
     resmodel.msg 为NSString类型的提示信息
     
## 调用获取人体各项数据的接口，需要确保用户开启蓝牙和初始化成功。
     
     [[BodySDKManager sharedInstance]deviceSearchSuccessScaleDeviceMacID:@"MacID" age:age height:height loginAccount:@"loginAccount" sex:sex thirdNickName:thirdNickName thirdUserNo:thirdUserNo deviceSuccess:^(id  _Nonnull bodyFatConfig) {
        NSLog(@"%@",bodyFatConfig);
        BodyFatConfig *body = [[BodyFatConfig alloc]init];
        body = bodyFatConfig;
        NSLog(@"");
        } deviceFailure:^(NSError * _Nonnull error) {
            NSLog(@"%@",error);
            NSLog(@"");
        }];
     
     
    
    

    
