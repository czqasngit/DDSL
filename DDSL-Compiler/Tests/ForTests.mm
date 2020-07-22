//
//  ForTests.m
//  DynamicDSLTests
//
//  Created by youxiaobin on 2020/7/15.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "DynamicDSLTestHelper.h"
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Antlr/DDSL-Antlr.h>
#include <DDSL-Script/DDSL-Script.h>
#include <DDSL-Runtime/DDSL-Runtime.h>
#import <vector>
#import "Compiler.h"

using namespace std;
using namespace DDSL;
@interface ForTests : XCTestCase

@end

@implementation ForTests

- (void)testForStmt {
    map<string, shared_ptr<DDSL::SemaASTNodeObject>> vari;
    vector<shared_ptr<SemaASTNodeObject>> images;
    images.push_back(make_shared<DDSL::SemaASTNodeObject>(new SemaASTNodeObject("http:///www.jd.com/")));
    images.push_back(make_shared<DDSL::SemaASTNodeObject>(new SemaASTNodeObject("http:///www.qq.com/")));
    images.push_back(make_shared<DDSL::SemaASTNodeObject>(new SemaASTNodeObject("http:///www.taobao.com/")));
    vari["images"] = make_shared<DDSL::SemaASTNodeObject>(new SemaASTNodeObject(images));
    string json = R"({"agex": 32, "namex": "johnx", "size": {"width": 20, "height": 30}, "object": {"rect": {"point": {"x": 200, "y": 100, "name": "小强"}}}, "items":[{"name": "小强", "age": 28},{"name": "小明", "age": 23},{"name": "小红", "age": 18}]})";
       string err;
    auto jsonObject = json11::Json::parse(json, err);
    auto result = DDSL::Complier(string("for item in items"), jsonObject, vari).compileForStmt();
    for(auto item : result.getResult()) {
//        cout << item->getText() << " - " << item->getType() << endl;
        auto sc = getObject(item);
        
        cout << "名称: " << sc->getVariableValue("name")->getText() << ", 年龄: " << sc->getVariableValue("age")->getText() << endl;
    }
    XCTAssert(!result.isEmpty());
    
}

@end
