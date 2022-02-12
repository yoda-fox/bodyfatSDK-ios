# Interact with the body fat scale to obtain various data of the human body

# SDK usage instructions document

[中文文档](https://github.com/yoda-fox/bodyfatSDK-ios/edit/main/bodyfatSDk%20Chinese%20document.md)  

## Conditions of Use

    1.Xcode
   
    2.IOS 9.0 and above
## Add Bluetooth permissions to the “Info.plist”file

     1.Privacy-Bluetooth Peripheral Usage Description
   
     2.Privacy-Bluetooth Always Usage Description
     
## Import Dexrous.framework

     Import Dexrous.framework in the file
     
## Declare header file

     Declare it in the.m file that you want to call #import <Dextrous/Dextrous.h>
     
## Initialization

   ### 1. Add at file “Appdelegate. Add m didFinishLaunchingWithOptions”
   
    [[BodySDKManager sharedInstance]BlueSharedInstance];
    
    [[BodySDKManager sharedInstance]registerApp:@"appid" withSecret:@"secret" success:^(id  _Nonnull responseModel) {
         ResponseModel *resmodel = responseModel;
         } failure:^(NSError * _Nonnull error) {
             NSLog(@"%@",error);
         }];
   ### 2. Parameter description        
         
      Appid, secret, need to fill in their application.    
      
   ### 3. Result callback:
   
      resmodel.code = 0; For success resmodel.code = 1; Error is the request failed

      ResModel. MSG is an NSString prompt

      
 ## Call the interface to obtain various human body data. Make sure that the user turns on Bluetooth and initializes successfully.
 
      [[BodySDKManager sharedInstance]deviceSearchSuccessScaleDeviceMacID:@"MacID" age:age height:height loginAccount:@"loginAccount" sex:sex thirdNickName:thirdNickName thirdUserNo:thirdUserNo deviceSuccess:^(id  _Nonnull bodyFatConfig) {
        NSLog(@"%@",bodyFatConfig);
        BodyFatConfig *body = [[BodyFatConfig alloc]init];
        body = bodyFatConfig;
        NSLog(@"");
        } deviceFailure:^(NSError * _Nonnull error) {
            NSLog(@"%@",error);
            NSLog(@"");
        }];
          
# Input parameter description


  Parameters | parameters introduction | data type
 -------- | :-----------:  | :-----------:
 loginAccount|user account|String
 thirdUserNo|user ID|int
 thirdNickName|User nickname|String
 height|The height of the user (unit: cm, range: 100~220)|double
 AGE|The age of the user (range: 10-99)|int
 sex|Gender of the user (1: male, 0: female)|int
 MacID|MAC address of the measuring device (optional);<br>Format: XX:XX:XX:XX:XX:XX|String       
         
### Fill in parameters

 Data name     |How to Obtain   |Data type|Description
 -------- | :-----------:  | :-----------: | :-----------:
 body.BMI                |                BMI       | double ("%.1f",body.BMI)  
body.BMR | basal metabolism | double ("%.1f ", body.BMR)) double
  body.age | age | int
  body.bodyAge | Body Age | double
  body.bodyScore | Body Score | int
 body.bodyType         |               Body type     |  int |  1: Lean type; 2: Lean muscle type; 3: Standard type;<br>4: Standard muscle type; 5: lack of exercise type;  <br>6: overweight type;7: Obese muscular type; <br>8: Puffyand obese type; 9: Obese type;10: Obese muscle type
 body.boneKg | Bone Mass | double
  body.boneRate | Bone Rate | double
  body.controlFatKg | Fat control volume | double
  body.controlMuscleKg | Muscle control volume | double
  body.controlWeight | Control weight | double
  body.fatKg | fat mass | double
 body.healthLevel  |                   Health level  | int |  1: Lean; 2: Standard; 3:Overweight; 4: Obese
 body.height | height | double
  body.muscleKg | muscle mass | double
  body.muscleRate | Muscle Rate | double
  body.notFatWeight | Fat-free body weight | double
 body.obesityLevel | Obesity grade | int  |   0: No obesity; 1: Obesity level 1; 2: Obesity level 2; <br>3: Obesity level 3; 4: Obesity level 4
 body.proteinPercentageKg | Protein Content |double
  body.proteinPercentageRate | Protein Ratio|double
  body.sex | gender|int
  body.standardWeight | Standard Weight | double
  body.subcutaneousFatKg | Subcutaneous fat mass | double
  body.subcutaneousFatRate | Subcutaneous Fat Rate | double
  body.visceralFat | Visceral Fat Grade|int
  body.visceralFatKg | Visceral fat area|double
  body.waterKg | Moisture|double
  body.waterRate | Water content | double
  body.weight | weight | double
  body.upFat|Upper limb fat rate|double|
 body.downFat|Lower limb fat rate|double|
 body.upMuscle|Upper limb muscle rate|double|
 body.downMuscle|Lower limb muscle rate|double|
  body.MAC | Device Mac address | NSString | Mac address of the body fat scale device that returns the measurement data
 body.impedanceStatus | Impedance type|int  |  **8 electrodes body up & down scale:** <br>1: Both hands and feet are in contact with the electrodes;<br>2: Only the feet are in contact with the electrodes of the scale; 3: Only the hand touches the electrode of the handle;<br> -1: No hand or foot touches the electrode<br> **Normal body fat scale:** <br>1: The foot is in contact with the electrode of the scale;<br>-1: The foot is not in contact with the electrode of the scale
body.code | Return status 0 means success, 1 means failure|int
  body.Msg | Prompt | NSString | Prompt returned when the request is successful
