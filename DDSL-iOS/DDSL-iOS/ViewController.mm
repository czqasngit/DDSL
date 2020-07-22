//
//  ViewController.m
//  CrossPlatformTemplate
//
//  Created by youxiaobin on 2020/6/22.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import "ViewController.h"
#import <DDSL-Flex/DDSL-Flex.h>
#import <DDSL-Runtime/DDSL-Runtime.h>

using namespace DDSL;
using namespace flex;
using namespace enumeration;
using namespace data;


static data::Size __MeasureFunc(Node *node, float maxWidth, float maxHeight) {
    if(node->getNodeType() == enumeration::label) {
        UIFont *font = [UIFont systemFontOfSize:((TextNode *)node)->getFontSize()];
        TextNode *tn = (TextNode *)node;
        NSString *text = [NSString stringWithUTF8String:tn->getText().c_str()];
        CGSize size = [text boundingRectWithSize:CGSizeMake((CGFloat)maxWidth, (CGFloat)maxHeight)
                                         options:NSStringDrawingUsesLineFragmentOrigin
                                      attributes:@{NSFontAttributeName: font}
                                         context:NULL].size;
        int maxNumberLine = tn->getMaxLineNumber();
        float height = maxNumberLine > 0 ? MIN(ceil(font.lineHeight * maxNumberLine), ceil((float)size.height)) : ceil((float)size.height);
        return {ceil((float)size.width), height};
    }
    return {0, 0};
}

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.edgesForExtendedLayout = UIRectEdgeNone;
//    [self _yogaTest];
    [self _loadXML];
}

- (UIColor *)colorWithHexString:(NSString *)hexString {
    if(![hexString hasPrefix:@"#"]) return NULL;
    if(hexString.length != 7) return NULL;
    NSString *cString = [[hexString stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] uppercaseString];
    if ([cString length] < 6){
        return [UIColor clearColor];
    }
    if ([cString hasPrefix:@"0X"]){
        cString = [cString substringFromIndex:2];
    }
    if ([cString hasPrefix:@"#"]){
        cString = [cString substringFromIndex:1];
    }
    if ([cString length] != 6){
        return [UIColor clearColor];
    }
    NSRange range;
    range.location = 0;
    range.length = 2;
    NSString *rString = [cString substringWithRange:range];
    range.location = 2;
    NSString *gString = [cString substringWithRange:range];
    range.location = 4;
    NSString *bString = [cString substringWithRange:range];
    // Scan values
    unsigned int r, g, b;
    [[NSScanner scannerWithString:rString] scanHexInt:&r];
    [[NSScanner scannerWithString:gString] scanHexInt:&g];
    [[NSScanner scannerWithString:bString] scanHexInt:&b];
    return [UIColor colorWithRed:((float)r / 255.0f) green:((float)g / 255.0f) blue:((float)b / 255.0f) alpha:1.0];
}

- (void)_addView:(Node *)node pv:(UIView *)pv {
    data::Rect rect = node->getRect();
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(rect.point.x, rect.point.y, rect.size.width, rect.size.height)];
    if(!node->getDisplayAttribute().backgroundColorHex.empty()) {
        view.backgroundColor = [self colorWithHexString:[NSString stringWithUTF8String:node->getDisplayAttribute().backgroundColorHex.c_str()]];
    }
    [pv addSubview:view];
    for(int i = 0; i < node->getChildCount(); i ++) {
        Node *child = node->getChild(i);
        if(child->getChildCount() > 0) {
            [self _addView:child pv:view];
        } else {
            data::Rect cr = child->getRect();
            UIView *childView;
            if(child->getNodeType() == label) {
                UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(cr.point.x, cr.point.y, cr.size.width, cr.size.height)];
                [view addSubview:label];
                TextNode *tn = (TextNode *)child;
                label.text = [NSString stringWithUTF8String:tn->getText().c_str()];
                label.font = [UIFont systemFontOfSize:tn->getFontSize()];
                label.textColor = [self colorWithHexString:[NSString stringWithUTF8String:tn->getDisplayAttribute().foregroundColorHex.c_str()]];
                childView = label;
                label.numberOfLines = tn->getMaxLineNumber();
            } else {
                UIView *cv = [[UIView alloc] initWithFrame:CGRectMake(cr.point.x, cr.point.y, cr.size.width, cr.size.height)];
                [view addSubview:cv];
                childView = cv;
            }
            
            if(child->getDisplayAttribute().backgroundColorAvailiable()) {
                childView.backgroundColor = [self colorWithHexString:[NSString stringWithUTF8String:child->getDisplayAttribute().backgroundColorHex.c_str()]];
            }
            if(child->getDisplayAttribute().borderAvailiable()) {
                childView.layer.borderColor = [self colorWithHexString:[NSString stringWithUTF8String:child->getDisplayAttribute().border.colorHex.c_str()]].CGColor;
                childView.layer.borderWidth = child->getDisplayAttribute().border.width;
            }
            if(child->getDisplayAttribute().shadowAvailiable()) {
                childView.layer.shadowColor = [self colorWithHexString:[NSString stringWithUTF8String:child->getDisplayAttribute().shadow.colorHex.c_str()]].CGColor;
                childView.layer.shadowOffset = CGSizeMake(child->getDisplayAttribute().shadow.offset.width, child->getDisplayAttribute().shadow.offset.height);
                childView.layer.shadowRadius = child->getDisplayAttribute().shadow.radius;
                childView.layer.shadowOpacity = child->getDisplayAttribute().shadow.opacity;
            }
        }
    }
}

- (void)_loadXML {
    vector<shared_ptr<DDSL::SemaASTNodeObject>> images;
    images.push_back(make_shared<DDSL::SemaASTNodeObject>("http:///www.jd.com/"));
    images.push_back(make_shared<DDSL::SemaASTNodeObject>("http:///www.qq.com/"));
    images.push_back(make_shared<DDSL::SemaASTNodeObject>("http:///www.taobao.com/"));
    map<string, shared_ptr<DDSL::SemaASTNodeObject>> variable;
    variable["images"] = make_shared<DDSL::SemaASTNodeObject>(images);
    string json = R"({"item":{"age": 30},"agex": 32, "namex": "johnx", "size": {"width": 20, "height": 30}, "object": {"rect": {"point": {"x": 200, "y": 100, "name": "小x强"}}}, "items":[{"name": "小强", "age": 28},{"name": "小明", "age": 23},{"name": "小红", "age": 18}]})";
    NSString *xmlPath = [[NSBundle mainBundle] pathForResource:@"node" ofType:@"xml"];
    Node *rootNode = NodeParser::LoadXML(xmlPath.UTF8String, [UIScreen mainScreen].scale, json, variable, __MeasureFunc);
    if(rootNode) {
        rootNode->calculateLayoutWithSize([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height);
        [self _addView:rootNode pv:self.view];
        rootNode->destory();
    }
}

@end
