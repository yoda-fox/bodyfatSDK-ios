
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>


NS_ASSUME_NONNULL_BEGIN

/**
 连接状态 枚举
 */
typedef NS_ENUM(NSUInteger, DeviceLinkStateType) {
    DeviceLinkStateConnected = 0, // 链接成功
    DeviceLinkStateFail, // 链接失败
    DeviceLinkStateDisconnect, //断开连接
    DeviceLinkStateCharacteristics, //写数据
};
/**
 设备数据 枚举
 */
typedef NS_ENUM(NSUInteger, DeviceDataType) {
    DeviceDataStateConnected = 0, // 链接成功
    DeviceDataStateFail, // 链接失败
    DeviceDataStateDisconnect //断开连接
};
typedef void (^DeviceSearchSuccessBlock)(CBPeripheral *peripheral, NSDictionary *advertisementData, NSNumber *RSSI);//搜索成功
typedef void (^DeviceLinkStateTypeBlock)(DeviceLinkStateType deviceLinkState);//搜索状态
typedef void (^DeviceDataTypeBlock)(DeviceDataType deviceDataType,  Byte *byte);//数据回调

@interface WatchBabyBLE : NSObject<CBCentralManagerDelegate,CBPeripheralDelegate>

/// 中央管理者 -->管理设备的扫描 --连接
@property (nonatomic, strong) CBCentralManager *centralManager;
// 蓝牙状态
@property (nonatomic, assign) CBManagerState peripheralState;
// 扫描到的设备
@property (nonatomic, strong) CBPeripheral *cbPeripheral;
//特征
@property (nonatomic ,strong) CBCharacteristic *wCharacteristic;//写
@property (nonatomic ,strong) CBCharacteristic *rCharacteristic;//读

@property (nonatomic) DeviceDataType deviceDataType;//当前连接诶状态

@property (nonatomic, copy) DeviceSearchSuccessBlock deviceSearchSuccessBlock;//搜索成功


#pragma mark - 方法

+(instancetype)sharedInstance;
// 扫描设备
- (void)scanForPeripherals;

-(void)stopCanPeripheral;
// 连接设备
- (void)connectToPeripheral:(CBPeripheral *)peripheral;
- (void)cancelPeripheralConnection;

@end

NS_ASSUME_NONNULL_END
