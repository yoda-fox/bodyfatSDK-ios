# Interact with the body fat scale to obtain various data of the human body

# SDK instruction document

[中文文档](https://github.com/yoda-fox/bodyfatSDK-ios/edit/main/bodyfatSDk%20Chinese%20document.md)  

## Conditions of Use

    1.Xcode
   
    2.IOS 9.0 and above
## Add permissions Add Bluetooth permissions in the Info.plist file

     1.Privacy-Bluetooth Peripheral Usage Description
   
     2.Privacy-Bluetooth Always Usage Description
     
## Import Dexrous.framework

     Import Dexrous.framework in the file
     
## Declare header file

     Declare #import <Dextrous/Dextrous.h> in the .m file that needs to be called
     
## Initialization

   ### 1. Add in the Appdelegate.m didFinishLaunchingWithOptions method     
   
    [[BodySDKManager sharedInstance]BlueSharedInstance];
    
    [[BodySDKManager sharedInstance]registerApp:@"appid" withSecret:@"secret" success:^(id  _Nonnull responseModel) {
         ResponseModel *resmodel = responseModel;
         } failure:^(NSError * _Nonnull error) {
             NSLog(@"%@",error);
         }];
   ### 2. Parameter description        
         
      appid, secret, you need to fill in the one you applied for.     
      
   ### 3. Result callback:
   
      resmodel.code = 0; is success resmodel.code = 1; is error error is request failure
     
      resmodel.msg is a prompt message of NSString type
      
 ## To call the interface for obtaining various data of the human body, it is necessary to ensure that the user turns on the Bluetooth and the initialization is successful.
 
 
      [[BodySDKManager sharedInstance]deviceSearchSuccessScaleDeviceMacID:@"MacID" age:age height:height loginAccount:@"loginAccount" sex:sex thirdNickName:thirdNickName thirdUserNo:thirdUserNo deviceSuccess:^(id  _Nonnull bodyFatConfig) {
        NSLog(@"%@",bodyFatConfig);
        BodyFatConfig *body = [[BodyFatConfig alloc]init];
        body = bodyFatConfig;
        NSLog(@"");
        } deviceFailure:^(NSError * _Nonnull error) {
            NSLog(@"%@",error);
            NSLog(@"");
        }];
         
         
         
         
