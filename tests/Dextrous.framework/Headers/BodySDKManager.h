
#import <Foundation/Foundation.h>

#import <Dextrous/BodyFatConfig.h>
#import <Dextrous/ResponseModel.h>

NS_ASSUME_NONNULL_BEGIN
@class BodySDKManager;

typedef void(^Success)(id responseModel);

typedef void(^deviceSuccess)(id bodyFatConfig);
typedef void(^deviceFailure)(NSError *error);
typedef void(^Failure)(NSError *error);

@interface BodySDKManager : NSObject
+ (instancetype)sharedInstance;

//responseModel.code = 0;  请求成功 / Request succeeded
//responseModel.code = 1; 请求失败 / Request failed
//responseModel.msg   返回语句 / Return statement

-(void)registerApp:(NSString*)appId withSecret:(NSString*)appSecret success:(Success)success failure:(Failure)failure ;


// 初始化 / initialization
-(void)BlueSharedInstance;
// 扫描蓝牙 / Scan Bluetooth
-(void)BlueScanForPeripherals;
// 蓝牙停止扫描 / Bluetooth stops scanning
-(void)BlueStopCanPeripheral;

// 返回设备信息和数据 /R eturn device information and data
//ScaleDeviceMacID：设备Mac地址 示例：00:00:00:00:00:00 / ScaleDeviceMacID: Device Mac address Example: 00:00:00:00:00:00
//sex 0:女   1:男 / sex 0: female 1: male
//age 年龄  / age
//height 单位cm  / height in cm
//thirdNickName         /昵称      /NickName
//loginAccount          /用户账号   /user account
//thirdUserNo           /用户ID    /User ID

-(void)deviceSearchSuccessScaleDeviceMacID:(NSString *)ScaleDeviceMacID age:(int)age height:(double)height loginAccount:(NSString *)loginAccount sex:(int)sex thirdNickName:(NSString *)thirdNickName thirdUserNo:(NSString *)thirdUserNo deviceSuccess:(deviceSuccess)deviceSuccess deviceFailure:(deviceFailure)deviceFailure;
@end

NS_ASSUME_NONNULL_END
