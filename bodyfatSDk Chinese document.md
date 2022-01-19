# 与体脂秤交互获取人体各项数据

# SDK使用说明文档

[English document](https://github.com/yoda-fox/bodyfatSDK-ios/edit/main/README.md)  

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
        
### 1.填写参数 

   参数     |参数说明   |数据类型
  -------- | :-----------:  | :-----------:
  loginAccount|用户账号|String
  thirdUserNo|用户ID|int
  thirdNickName|用户昵称D|String
  height|测量者的身高(单位：cm,范围：100~220);|double
  age|测量者的年龄(范围：10~99)|int
  sex|测量者的性别(1:男，0：女)|int
 MacID|测量设备的MAC地址(选填);<br>格式: XX:XX:XX:XX:XX:XX|String
        
### 2.结果回调：     
参数     | 参数说明   |数据类型|描述
 -------- | :-----------:  | :-----------: | :-----------:
 body.BMI                |                       | double ("%.1f",body.BMI)  
 body.BMR               |              基础代谢  |  double ("%.1f ", body.BMR)) double
 body.age              |               年龄     |  int
 body.bodyAge       |                  身体年龄 |   double
 body.bodyScore        |               身体评分 |   int
 body.bodyType         |               体型     |  int |  1：偏瘦型; 2：偏瘦肌肉型; 3：标准型;<br>4：标准肌肉型; 5：缺乏运动型; 6：偏胖型;<br>7：偏胖肌肉型; 8：浮肿肥胖型; 9：肥胖型;<br>10：肥胖肌肉型
 body.boneKg           |               骨量     |  double
 body.boneRate         |               骨率      | double
 body.controlFatKg        |            脂肪控制量 | double
 body.controlMuscleKg   |              肌肉控制量  |double
 body.controlWeight     |              控制体重   | double
 body.fatKg          |                 脂肪量    |  double
 body.fatRate         |                脂肪率     | double
 body.healthLevel  |                   健康等级   | int |  1：偏瘦; 2：标准; 3：超重; 4：肥胖
 body.height         |                 身高    |   double
 body.muscleKg       |                 肌肉量     | double
 body.muscleRate       |               肌肉率   |   double
 body.notFatWeight | 去脂体重 | double
 body.obesityLevel | 肥胖等级 | int  |   0：无肥胖; 1：肥胖1级; 2：肥胖2级; 3：肥胖3级;<br>4：肥胖4级
 body.proteinPercentageKg | 蛋白质含量 |double
 body.proteinPercentageRate | 蛋白质比例|double
 body.sex | 性别|int
 body.standardWeight | 标准体重|double
 body.subcutaneousFatKg | 皮下脂肪量|double
 body.subcutaneousFatRate | 皮下脂肪率|double
 body.visceralFat | 内脏脂肪等级|int
 body.visceralFatKg | 内脏脂肪面积|double
 body.waterKg | 水分|double
 body.waterRate | 含水量|double
 body.weight | 重量|double
 body.MAC | 设备Mac地址|NSString|返回测量数据的体脂秤设备Mac地址
 body.impedanceStatus | 阻抗类型|int  |  **八极秤:** 1：手脚都接触电极; 2：只是脚接触秤电极;<br> 3：只是手接触手柄电极; -1：手脚都没接触电极<br> **普通脂肪秤:** 1：脚接触秤电极; -1：脚没有接触秤电极
 body.code | 返回状态 0为成功，1为失败|int
 body.Msg | 提示语|NSString|请求成功时返回的提示语
     
## 参数范围说明
### 1.体重
#### 标准体重：standardWeight
#### 男标准范围：
    float downWeight = standardWeight  - standardWeight  * 0.1f;
#### 女标准范围：
    float upWeight = standardWeight  + standardWeight  * 0.1f; 
#### 偏胖范围：
    float fatWeight = standardWeight  + standardWeight  * 0.2f;
#### 人的体重范围：
 分类     |标准范围
 -------- | :-----------:
偏瘦|weight<downWeight
标准|downWeight≤weight<upWeight 
偏胖|upWeight ≤weight<fatWeight 
肥胖|weight≥fatWeight 
			      			      
### 2.BMI
 分类     |标准范围
 -------- | :-----------:
偏瘦|BMI<18.5
标准|18.5≤BMI<24
偏胖|24≤BMI<30
肥胖|30≤BMI

### 3.脂肪率
#### 男性：
如果年龄：小于 40
low = 10f;<br>
stander = 21f;<br>
lightFat = 26f;<br>
如果年龄： 大于等于40， 小于60 的<br>
low = 11f;<br>
stander = 22f;<br>
lightFat = 27f;<br>
如果年龄： 大于等于60 的<br>
low = 13f;<br>
stander = 24f;<br>
lightFat = 29f;<br>
#### 女性：
如果年龄：小于 40<br>
low = 20f;<br>
stander = 34f;<br>
lightFat = 39f;<br>
如果年龄： 大于等于40， 小于60 的<br>
low = 21f;<br>
stander = 35f;<br>
lightFat = 40f;<br>
如果年龄： 大于等于60 的<br>
low = 22f;<br>
stander = 36f;<br>
lightFat = 41f; <br>

 分类     |标准范围
 -------- | :-----------:
偏瘦|fat≤low
标准|low<fat≤stander
偏胖|stander<fat≤lightFat
肥胖|lightFat<fat

### 4.皮下脂肪率
 分类|男性标准范围|女性标准范围
 -------- | :-----------: | :-----------:
偏瘦|<8.6%|<18.5%
标准|8.6%-16.7%|18.5%-26.7%
偏胖|16.7%-20.7|26.7-30.8%
肥胖|>20.7%|>30.8%	
		
### 5. 肌肉率
#### 男性：
身高：小于 160cm<br>
low = 38.5f;<br>
mid = 46.5f;<br>
身高： 大于等于160， 小于等于170 的<br>
low = 44f;<br>
mid = 52.4f;<br>
如果年龄： 大于 170 的<br>
low = 49.4f;<br>
mid = 59.4f;
#### 女性：
身高：小于 150cm<br>
low = 29.1f;<br>
mid = 34.7f;<br>
身高： 大于等于150， 小于等于160 的<br>
low = 32.9f;<br>
mid = 37.5f;<br>
如果年龄： 大于 170 的<br>
low = 36.5f;<br>
mid = 42.5f;
 分类     |标准范围
 -------- | :-----------:
不足|muscle≤low
标准|low<muscle≤mid
优|mid<muscle

### 6.水分
#### 男性：
low = 55f;
mid = 65f;
#### 女性：
low = 45f;
mid = 60f;
 分类     |标准范围
 -------- | :-----------:
不足|water≤low
标准|low<water≤mid
优|mid<water
	    
### 7.内脏脂肪等级
 分类     |标准范围
 -------- | :-----------:
标准|visceral≤9
警惕|9<visceral≤14
危险|14<visceral
	       
### 8.骨量
#### 男性：
如果体重：小于 60kg<br>
low = 2.4f;<br>
mid = 2.6f;<br>
如果体重： 大于等于60， 小于等于75 的<br>
low = 2.8f;<br>
mid = 3.0f;<br>
如果体重： 大于 75 的<br>
low = 3.1f;<br>
mid = 3.3f;
#### 女性：
如果体重：小于 45kg<br>
low = 1.7f;<br>
mid = 1.9f;<br>
如果体重： 大于等于45， 小于等于60 的<br>
low = 2.1f;<br>
mid = 2.3f;<br>
如果体重： 大于 60 的<br>
low = 2.4f;<br>
mid = 2.6f;
 分类     |标准范围
 -------- | :-----------:
不足|bone≤low
标准|low<bone≤mid
优|mid<bone    

### 9.基础代谢	   
如果年龄：小于等于29 的<br>
男性：low = weight * 24.0f;<br>
女性：low = weight * 23.6f;<br>
如果年龄：大于等于30， 小于等于49 的<br>
男性：low = weight * 22.3f;<br>
女性：low = weight * 21.7f;<br>
如果年龄：大于 49 的<br>
男性：low = weight * 21.5f;<br>
女性：low = weight * 20.7f;<br>
 分类     |标准范围
 -------- | :-----------:
偏低|bmr≤low
优|low<bmr
### 10.蛋白质比例
 分类     |标准范围
 -------- | :-----------:
不足|protein<16
标准|16≤protein≤20
优|20<protein	  
### 11.身体得分
 分类     |标准范围
 -------- | :-----------:
存在隐患|0-60
亚健康|60-70
一般|70-80
良好|80-90   
非常好|≥90	   		
    
    

    
