//
//  BindingTests.m
//  DynamicDSLTests
//
//  Created by youxiaobin on 2020/7/15.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DynamicDSLTestHelper.h"
#import "DDXMLBinding.h"
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Antlr/DDSL-Antlr.h>
#include <DDSL-Script/DDSL-Script.h>
#include <DDSL-Runtime/DDSL-Runtime.h>
#include "DDIR.h"

using namespace std;
using namespace DDSL;

@interface BindingTests : XCTestCase {
    map<string, shared_ptr<DDSL::SemaASTNodeObject>> variable;;
    Json jsonObject;
}
@end

@implementation BindingTests

- (void)setUp {
    vector<shared_ptr<SemaASTNodeObject>> images;
    images.push_back(make_shared<DDSL::SemaASTNodeObject>("http:///www.jd.com/"));
    images.push_back(make_shared<DDSL::SemaASTNodeObject>("http:///www.qq.com/"));
    images.push_back(make_shared<DDSL::SemaASTNodeObject>("http:///www.taobao.com/"));
    variable["images"] = make_shared<DDSL::SemaASTNodeObject>(images);
    
    
    string json = R"({"item":{"age": 30},"agex": 32, "namex": "johnx", "size": {"width": 20, "height": 30}, "object": {"rect": {"point": {"x": 200, "y": 100, "name": "小x强"}}}, "items":[{"name": "小强", "age": 28},{"name": "小明", "age": 23},{"name": "小红", "age": 18}]})";
    string err;
    jsonObject = json11::Json::parse(json, err);
}
- (void)testXMLBinding {
    NSBundle *bundle = [NSBundle bundleForClass:[self class]];
    NSString *xmlPath = [bundle pathForResource:@"node_ir" ofType:@"xml"];
    DDSL::DDXMLBinding *db = new DDSL::DDXMLBinding([xmlPath UTF8String], jsonObject, variable);
    db->BindingXML();
    XMLPrinter printer;
    db->GetDoc()->Print(&printer);
    cout << printer.CStr() << endl;
    delete db;
}

- (void)testXMLIR {
    NSBundle *bundle = [NSBundle bundleForClass:[self class]];
    NSString *xmlPath = [bundle pathForResource:@"node" ofType:@"xml"];
    auto db = DDIR([xmlPath UTF8String]);
    cout << db.ObtainXMLIR() << endl;
}

@end
