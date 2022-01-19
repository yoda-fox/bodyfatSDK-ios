
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BodyFatConfig : NSObject
@property(nonatomic,assign)double BMI;
@property(nonatomic,assign)double BMR;
@property(nonatomic,assign)int age;                                     //年龄
@property(nonatomic,assign)double bodyAge;                              //体龄
@property(nonatomic,assign)int bodyScore;                               //身体评分
@property(nonatomic,assign)int bodyType;                                //体型
@property(nonatomic,assign)double boneKg;                               //骨量
@property(nonatomic,assign)double boneRate;                             //骨率
@property(nonatomic,assign)double controlFatKg;                         //脂肪控制量
@property(nonatomic,assign)double controlMuscleKg;                      //肌肉控制量
@property(nonatomic,assign)double controlWeight;                        //控制体重
@property(nonatomic,assign)double fatKg;                                //脂肪量
@property(nonatomic,assign)double fatRate;                              //脂肪率
@property(nonatomic,assign)int healthLevel;                             //健康等级
@property(nonatomic,assign)double height;                               //身高
@property(nonatomic,assign)double muscleKg;                             //肌肉公斤
@property(nonatomic,assign)double muscleRate;                           //肌肉率
@property(nonatomic,assign)double notFatWeight;                         //去脂体重
@property(nonatomic,assign)int obesityLevel;                            //肥胖等级
@property(nonatomic,assign)double proteinPercentageKg;                  //蛋白质含量
@property(nonatomic,assign)double proteinPercentageRate;                //蛋白质比例
@property(nonatomic,assign)int sex;                                     //性别
@property(nonatomic,assign)double standardWeight;                       //标准体重
@property(nonatomic,assign)double subcutaneousFatKg;                    //皮下脂肪量
@property(nonatomic,assign)double subcutaneousFatRate;                  //皮下脂肪率
@property(nonatomic,assign)int visceralFat;                             //内脏脂肪等级
@property(nonatomic,assign)double visceralFatKg;                        //内脏脂肪面积
@property(nonatomic,assign)double waterKg;                              //水分
@property(nonatomic,assign)double waterRate;                            //含水量
@property(nonatomic,assign)double weight;                               //重量
@property(nonatomic,strong)NSString *weightString;                      //重量字符串
@property(nonatomic,strong)NSString *MAC;                               //设备Mac地址
@property(nonatomic,assign)int impedanceStatus;                         //阻抗类型
@property(nonatomic,assign)double upFat;                                //上臂脂肪
@property(nonatomic,assign)double downFat;                              //下肢脂肪
@property(nonatomic,assign)double upMuscle;                             //上臂肌肉
@property(nonatomic,assign)double downMuscle;                           //上臂肌肉
@property(nonatomic,assign)int code;                                    //返回状态 0为成功，1为失败
@property(nonatomic,strong)NSString *Msg;                               //提示语
////阻抗类型
/**
 1-手脚都接触电极                             /          1- Both hands and feet touch the electrodes
 2-只是脚接触秤电极                          /           2- Only the foot touches the electrode of the scale
 3-只是手接触手柄电极                      /            3- Just touch the handle electrode with your hand
 -1-手脚都没接触电极                        /           -1-Neither hands nor feet touch the electrodes
 */


/**
 * 肥胖等级                                    /        Obesity grade
 * 0.无肥胖                                    /          0. No obesity
 * 1.肥胖1级                                  /          1. Obesity Grade 1
 * 2.肥胖2级                                  /            2. Obesity Grade 2
 * 3.肥胖3级                                  /            3. Obesity Grade 3
 * 4.肥胖4级                                  /            4. Obesity Grade 4
 */


/**
 * 健康等级                                 /             Health level
 * <p>
 * 1.偏瘦                                     /               1. Thin
 * 2.标准                                     /               2. Standard
 * 3.超重                                     /               3. Overweight
 * 4.肥胖                                     /               4. Obesity
 */

//体型                  /        bodyType
/**
 * 1.偏瘦型                                /                   1. Thin type
 * 2.偏瘦肌肉型                         /                   2. Lean muscle type
 * 3.标准型                                /                   3. Standard type
 * 4.标准肌肉型                         /                   4. Standard muscle type
 * 5.缺乏运动型                         /                   5. Lack of exercise
 * 6.偏胖型                                /                   6. Obese
 * 7.偏胖肌肉型                         /                   7. Fat muscle type
 * 8.浮肿肥胖型                         /                   8. Puffiness and obesity
 * 9.肥胖型                                /                   9. Obesity
 * 10.肥胖肌肉型                       /                  10. Obese muscle type
 */

@end

NS_ASSUME_NONNULL_END
