
#import <Foundation/Foundation.h>

@interface ResponseModel : NSObject
@property (nonatomic ) NSInteger code;
@property (nonatomic, copy) NSString * msg;
@property (nonatomic ,strong) NSMutableArray *data;
@property(nonatomic,strong)NSString *token;
@end



